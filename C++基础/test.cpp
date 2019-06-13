1. /*
2. * fs/eventpoll.c (Efficient event retrieval implementation)
3. * Copyright (C) 2001,...,2009 Davide Libenzi
4. *
5. * This program is free software; you can redistribute it and/or modify
6. * it under the terms of the GNU General Public License as published by
7. * the Free Software Foundation; either version 2 of the License, or
8. * (at your option) any later version.
9. *
10. * Davide Libenzi <davidel@xmailserver.org>
11. *
12. */
13.
14. /*
15. * 在深入了解epoll的实现之前, 先来了解内核的3个方面.
16. * 1. 等待队列 waitqueue
17. * 我们简单解释一下等待队列:
18. * 队列头(wait_queue_head_t)往往是资源生产者,
19. * 队列成员(wait_queue_t)往往是资源消费者,
20. * 当头的资源ready后, 会逐个执行每个成员指定的回调函数,
21. * 来通知它们资源已经ready了, 等待队列大致就这个意思.
22. * 2. 内核的poll机制
23. * 被Poll的fd, 必须在实现上支持内核的Poll技术,
24. * 比如fd是某个字符设备,或者是个socket, 它必须实现
25. * file_operations中的poll操作, 给自己分配有一个等待队列头.
26. * 主动poll fd的某个进程必须分配一个等待队列成员, 添加到
27. * fd的对待队列里面去, 并指定资源ready时的回调函数.
28. * 用socket做例子, 它必须有实现一个poll操作, 这个Poll是
29. * 发起轮询的代码必须主动调用的, 该函数中必须调用poll_wait(),
30. * poll_wait会将发起者作为等待队列成员加入到socket的等待队列中去.
31. * 这样socket发生状态变化时可以通过队列头逐个通知所有关心它的进程.
32. * 这一点必须很清楚的理解, 否则会想不明白epoll是如何
33. * 得知fd的状态发生变化的.
34. * 3. epollfd本身也是个fd, 所以它本身也可以被epoll,
35. * 可以猜测一下它是不是可以无限嵌套epoll下去...
36. *
37. * epoll基本上就是使用了上面的1,2点来完成.
38. * 可见epoll本身并没有给内核引入什么特别复杂或者高深的技术,
39. * 只不过是已有功能的重新组合, 达到了超过select的效果.
40. */
41.
42. /*
43. * 相关的其它内核知识:
44. * 1. fd我们知道是文件描述符, 在内核态, 与之对应的是struct file结构,
45. * 可以看作是内核态的文件描述符.
46. * 2. spinlock, 自旋锁, 必须要非常小心使用的锁,
47. * 尤其是调用spin_lock_irqsave()的时候, 中断关闭, 不会发生进程调度,
48. * 被保护的资源其它CPU也无法访问. 这个锁是很强力的, 所以只能锁一些
49. * 非常轻量级的操作.
50. * 3. 引用计数在内核中是非常重要的概念,
51. * 内核代码里面经常有些release, free释放资源的函数几乎不加任何锁,
52. * 这是因为这些函数往往是在对象的引用计数变成0时被调用,
53. * 既然没有进程在使用在这些对象, 自然也不需要加锁.
54. * struct file 是持有引用计数的.
55. */
56.
57. /* --- epoll相关的数据结构 --- */
58.
59. /*
60. * This structure is stored inside the "private_data" member of the file
61. * structure and rapresent the main data sructure for the eventpoll
62. * interface.
63. */
64. /* 每创建一个epollfd, 内核就会分配一个eventpoll与之对应, 可以说是
65. * 内核态的epollfd. */
66. struct eventpoll {
67. /* Protect the this structure access */
68. spinlock_t lock;
69.
70. /*
71. * This mutex is used to ensure that files are not removed
72. * while epoll is using them. This is held during the event
73. * collection loop, the file cleanup path, the epoll file exit
74. * code and the ctl operations.
75. */
76. /* 添加, 修改或者删除监听fd的时候, 以及epoll_wait返回, 向用户空间
77. * 传递数据时都会持有这个互斥锁, 所以在用户空间可以放心的在多个线程
78. * 中同时执行epoll相关的操作, 内核级已经做了保护. */
79. struct mutex mtx;
80.
81. /* Wait queue used by sys_epoll_wait() */
82. /* 调用epoll_wait()时, 我们就是"睡"在了这个等待队列上... */
83. wait_queue_head_t wq;
84.
85. /* Wait queue used by file->poll() */
86. /* 这个用于epollfd本事被poll的时候... */
87. wait_queue_head_t poll_wait;
88.
89. /* List of ready file descriptors */
90. /* 所有已经ready的epitem都在这个链表里面 */
91. struct list_head rdllist;
92.
93. /* RB tree root used to store monitored fd structs */
94. /* 所有要监听的epitem都在这里 */
95. struct rb_root rbr;
96.
97. /*
98. * This is a single linked list that chains all the "struct epitem" that
99. * happened while transfering ready events to userspace w/out
100. * holding ->lock.
101. */
102. struct epitem *ovflist;
103.
104. /* The user that created the eventpoll descriptor */
105. /* 这里保存了一些用户变量, 比如fd监听数量的最大值等等 */
106. struct user_struct *user;
107. };
108.
109. /*
110. * Each file descriptor added to the eventpoll interface will
111. * have an entry of this type linked to the "rbr" RB tree.
112. */
113. /* epitem 表示一个被监听的fd */
114. struct epitem {
115. /* RB tree node used to link this structure to the eventpoll RB tree */
116. /* rb_node, 当使用epoll_ctl()将一批fds加入到某个epollfd时, 内核会分配
117. * 一批的epitem与fds们对应, 而且它们以rb_tree的形式组织起来, tree的root
118. * 保存在epollfd, 也就是struct eventpoll中.
119. * 在这里使用rb_tree的原因我认为是提高查找,插入以及删除的速度.
120. * rb_tree对以上3个操作都具有O(lgN)的时间复杂度 */
121. struct rb_node rbn;
122.
123. /* List header used to link this structure to the eventpoll ready list */
124. /* 链表节点, 所有已经ready的epitem都会被链到eventpoll的rdllist中 */
125. struct list_head rdllink;
126.
127. /*
128. * Works together "struct eventpoll"->ovflist in keeping the
129. * single linked chain of items.
130. */
131. /* 这个在代码中再解释... */
132. struct epitem *next;
133.
134. /* The file descriptor information this item refers to */
135. /* epitem对应的fd和struct file */
136. struct epoll_filefd ffd;
137.
138. /* Number of active wait queue attached to poll operations */
139. int nwait;
140.
141. /* List containing poll wait queues */
142. struct list_head pwqlist;
143.
144. /* The "container" of this item */
145. /* 当前epitem属于哪个eventpoll */
146. struct eventpoll *ep;
147.
148. /* List header used to link this item to the "struct file" items list */
149. struct list_head fllink;
150.
151. /* The structure that describe the interested events and the source fd */
152. /* 当前的epitem关系哪些events, 这个数据是调用epoll_ctl时从用户态传递过来 */
153. struct epoll_event event;
154. };
155.
156. struct epoll_filefd {
157. struct file *file;
158. int fd;
159. };
160.
161. /* Wait structure used by the poll hooks */
162. struct eppoll_entry {
163. /* List header used to link this structure to the "struct epitem" */
164. struct list_head llink;
165.
166. /* The "base" pointer is set to the container "struct epitem" */
167. struct epitem *base;
168.
169. /*
170. * Wait queue item that will be linked to the target file wait
171. * queue head.
172. */
173. wait_queue_t wait;
174.
175. /* The wait queue head that linked the "wait" wait queue item */
176. wait_queue_head_t *whead;
177. };
178.
179. /* Wrapper struct used by poll queueing */
180. struct ep_pqueue {
181. poll_table pt;
182. struct epitem *epi;
183. };
184.
185. /* Used by the ep_send_events() function as callback private data */
186. struct ep_send_events_data {
187. int maxevents;
188. struct epoll_event __user *events;
189. };
190.
191. /* --- 代码注释 --- */
192.
193. /* 你没看错, 这就是epoll_create()的真身, 基本啥也不干直接调用epoll_create1了,
194. * 另外你也可以发现, size这个参数其实是没有任何用处的... */
195. SYSCALL_DEFINE1(epoll_create, int, size)
196. {
197. if (size <= 0)
198. return -EINVAL;
199.
200. return sys_epoll_create1(0);
201. }
202.
203. /* 这才是真正的epoll_create啊~~ */
204. SYSCALL_DEFINE1(epoll_create1, int, flags)
205. {
206. int error;
207. struct eventpoll *ep = NULL;//主描述符
208.
209. /* Check the EPOLL_* constant for consistency. */
210. /* 这句没啥用处... */
211. BUILD_BUG_ON(EPOLL_CLOEXEC != O_CLOEXEC);
212.
213. /* 对于epoll来讲, 目前唯一有效的FLAG就是CLOEXEC */
214. if (flags & ~EPOLL_CLOEXEC)
215. return -EINVAL;
216. /*
217. * Create the internal data structure ("struct eventpoll").
218. */
219. /* 分配一个struct eventpoll, 分配和初始化细节我们随后深聊~ */
220. error = ep_alloc(&ep);
221. if (error < 0)
222. return error;
223. /*
224. * Creates all the items needed to setup an eventpoll file. That is,
225. * a file structure and a free file descriptor.
226. */
227. /* 这里是创建一个匿名fd, 说起来就话长了...长话短说:
228. * epollfd本身并不存在一个真正的文件与之对应, 所以内核需要创建一个
229. * "虚拟"的文件, 并为之分配真正的struct file结构, 而且有真正的fd.
230. * 这里2个参数比较关键:
231. * eventpoll_fops, fops就是file operations, 就是当你对这个文件(这里是虚拟的)进
行操作(比如读)时,
232. * fops里面的函数指针指向真正的操作实现, 类似C++里面虚函数和子类的概念.
233. * epoll只实现了poll和release(就是close)操作, 其它文件系统操作都有VFS全权处理
了.
234. * ep, ep就是struct epollevent, 它会作为一个私有数据保存在struct file的private
指针里面.
235. * 其实说白了, 就是为了能通过fd找到struct file, 通过struct file能找到eventpoll
结构.
236. * 如果懂一点Linux下字符设备驱动开发, 这里应该是很好理解的,
237. * 推荐阅读 <Linux device driver 3rd>
238. */
239. error = anon_inode_getfd("[eventpoll]", &eventpoll_fops, ep,
240. O_RDWR | (flags & O_CLOEXEC));
241. if (error < 0)
242. ep_free(ep);
243.
244. return error;
245. }
246.
247. /*
248. * 创建好epollfd后, 接下来我们要往里面添加fd咯
249. * 来看epoll_ctl
250. * epfd 就是epollfd
251. * op ADD,MOD,DEL
252. * fd 需要监听的描述符
253. * event 我们关心的events
254. */
255. SYSCALL_DEFINE4(epoll_ctl, int, epfd, int, op, int, fd,
256. struct epoll_event __user *, event)
257. {
258. int error;
259. struct file *file, *tfile;
260. struct eventpoll *ep;
261. struct epitem *epi;
262. struct epoll_event epds;
263.
264. error = -EFAULT;
265.
266. /*
267. * 错误处理以及从用户空间将epoll_event结构copy到内核空间.
268. */
269. if (ep_op_has_event(op) &&
270. copy_from_user(&epds, event, sizeof(struct epoll_event)))
271. goto error_return;
272.
273. /* Get the "struct file *" for the eventpoll file */
274. /* 取得struct file结构, epfd既然是真正的fd, 那么内核空间
275. * 就会有与之对于的一个struct file结构
276. * 这个结构在epoll_create1()中, 由函数anon_inode_getfd()分配 */
277. error = -EBADF;
278. file = fget(epfd);
279. if (!file)
280. goto error_return;
281.
282. /* Get the "struct file *" for the target file */
283. /* 我们需要监听的fd, 它当然也有个struct file结构, 上下2个不要搞混了哦 */
284. tfile = fget(fd);
285. if (!tfile)
286. goto error_fput;
287.
288. /* The target file descriptor must support poll */
289. error = -EPERM;
290. /* 如果监听的文件不支持poll, 那就没辙了.
291. * 你知道什么情况下, 文件会不支持poll吗?
292. */
293. if (!tfile->f_op || !tfile->f_op->poll)
294. goto error_tgt_fput;
295.
296. /*
297. * We have to check that the file structure underneath the file descriptor
298. * the user passed to us _is_ an eventpoll file. And also we do not permit
299. * adding an epoll file descriptor inside itself.
300. */
301. error = -EINVAL;
302. /* epoll不能自己监听自己... */
303. if (file == tfile || !is_file_epoll(file))
304. goto error_tgt_fput;
305.
306. /*
307. * At this point it is safe to assume that the "private_data" contains
308. * our own data structure.
309. */
310. /* 取到我们的eventpoll结构, 来自与epoll_create1()中的分配 */
311. ep = file->private_data;
312.
313. /* 接下来的操作有可能修改数据结构内容, 锁之~ */
314. mutex_lock(&ep->mtx);
315.
316. /*
317. * Try to lookup the file inside our RB tree, Since we grabbed "mtx"
318. * above, we can be sure to be able to use the item looked up by
319. * ep_find() till we release the mutex.
320. */
321. /* 对于每一个监听的fd, 内核都有分片一个epitem结构,
322. * 而且我们也知道, epoll是不允许重复添加fd的,
323. * 所以我们首先查找该fd是不是已经存在了.
324. * ep_find()其实就是RBTREE查找, 跟C++STL的map差不多一回事, O(lgn)的时间复杂度.
325. */
326. epi = ep_find(ep, tfile, fd);
327.
328. error = -EINVAL;
329. switch (op) {
330. /* 首先我们关心添加 */
331. case EPOLL_CTL_ADD:
332. if (!epi) {
333. /* 之前的find没有找到有效的epitem, 证明是第一次插入, 接受!
334. * 这里我们可以知道, POLLERR和POLLHUP事件内核总是会关心的
335. * */
336. epds.events |= POLLERR | POLLHUP;
337. /* rbtree插入, 详情见ep_insert()的分析
338. * 其实我觉得这里有insert的话, 之前的find应该
339. * 是可以省掉的... */
340. error = ep_insert(ep, &epds, tfile, fd);
341. } else
342. /* 找到了!? 重复添加! */
343. error = -EEXIST;
344. break;
345. /* 删除和修改操作都比较简单 */
346. case EPOLL_CTL_DEL:
347. if (epi)
348. error = ep_remove(ep, epi);
349. else
350. error = -ENOENT;
351. break;
352. case EPOLL_CTL_MOD:
353. if (epi) {
354. epds.events |= POLLERR | POLLHUP;
355. error = ep_modify(ep, epi, &epds);
356. } else
357. error = -ENOENT;
358. break;
359. }
360. mutex_unlock(&ep->mtx);
361.
362. error_tgt_fput:
363. fput(tfile);
364. error_fput:
365. fput(file);
366. error_return:
367.
368. return error;
369. }
370.
371. /* 分配一个eventpoll结构 */
372. static int ep_alloc(struct eventpoll **pep)
373. {
374. int error;
375. struct user_struct *user;
376. struct eventpoll *ep;
377.
378. /* 获取当前用户的一些信息, 比如是不是root啦, 最大监听fd数目啦 */
379. user = get_current_user();
380. error = -ENOMEM;
381. ep = kzalloc(sizeof(*ep), GFP_KERNEL);
382. if (unlikely(!ep))
383. goto free_uid;
384.
385. /* 这些都是初始化啦 */
386. spin_lock_init(&ep->lock);
387. mutex_init(&ep->mtx);
388. init_waitqueue_head(&ep->wq);
389. init_waitqueue_head(&ep->poll_wait);
390. INIT_LIST_HEAD(&ep->rdllist);
391. ep->rbr = RB_ROOT;
392. ep->ovflist = EP_UNACTIVE_PTR;
393. ep->user = user;
394.
395. *pep = ep;
396.
397. return 0;
398.
399. free_uid:
400. free_uid(user);
401. return error;
402. }
403.
404.
405. /*
406. * Must be called with "mtx" held.
407. */
408. /*
409. * ep_insert()在epoll_ctl()中被调用, 完成往epollfd里面添加一个监听fd的工作
410. * tfile是fd在内核态的struct file结构
411. */
412. static int ep_insert(struct eventpoll *ep, struct epoll_event *event,
413. struct file *tfile, int fd)
414. {
415. int error, revents, pwake = 0;
416. unsigned long flags;
417. struct epitem *epi;
418. struct ep_pqueue epq;
419.
420. /* 查看是否达到当前用户的最大监听数 */
421. if (unlikely(atomic_read(&ep->user->epoll_watches) >=
422. max_user_watches))
423. return -ENOSPC;
424. /* 从著名的slab中分配一个epitem */
425. if (!(epi = kmem_cache_alloc(epi_cache, GFP_KERNEL)))
426. return -ENOMEM;
427.
428. /* Item initialization follow here ... */
429. /* 这些都是相关成员的初始化... */
430. INIT_LIST_HEAD(&epi->rdllink);
431. INIT_LIST_HEAD(&epi->fllink);
432. INIT_LIST_HEAD(&epi->pwqlist);
433. epi->ep = ep;
434. /* 这里保存了我们需要监听的文件fd和它的file结构 */
435. ep_set_ffd(&epi->ffd, tfile, fd);
436. epi->event = *event;
437. epi->nwait = 0;
438. /* 这个指针的初值不是NULL哦... */
439. epi->next = EP_UNACTIVE_PTR;
440.
441. /* Initialize the poll table using the queue callback */
442. /* 好, 我们终于要进入到poll的正题了 */
443. epq.epi = epi;
444. /* 初始化一个poll_table
445. * 其实就是指定调用poll_wait(注意不是epoll_wait!!!)时的回调函数,和我们关心哪些
events,
446. * ep_ptable_queue_proc()就是我们的回调啦, 初值是所有event都关心 */
447. init_poll_funcptr(&epq.pt, ep_ptable_queue_proc);
448.
449. /*
450. * Attach the item to the poll hooks and get current event bits.
451. * We can safely use the file* here because its usage count has
452. * been increased by the caller of this function. Note that after
453. * this operation completes, the poll callback can start hitting
454. * the new item.
455. */
456. /* 这一部很关键, 也比较难懂, 完全是内核的poll机制导致的...
457. * 首先, f_op->poll()一般来说只是个wrapper, 它会调用真正的poll实现,
458. * 拿UDP的socket来举例, 这里就是这样的调用流程: f_op->poll(), sock_poll(),
459. * udp_poll(), datagram_poll(), sock_poll_wait(), 最后调用到我们上面指定的
460. * ep_ptable_queue_proc()这个回调函数...(好深的调用路径...).
461. * 完成这一步, 我们的epitem就跟这个socket关联起来了, 当它有状态变化时,
462. * 会通过ep_poll_callback()来通知.
463. * 最后, 这个函数还会查询当前的fd是不是已经有啥event已经ready了, 有的话
464. * 会将event返回. */
465. revents = tfile->f_op->poll(tfile, &epq.pt);
466.
467. /*
468. * We have to check if something went wrong during the poll wait queue
469. * install process. Namely an allocation for a wait queue failed due
470. * high memory pressure.
471. */
472. error = -ENOMEM;
473. if (epi->nwait < 0)
474. goto error_unregister;
475.
476. /* Add the current item to the list of active epoll hook for this file */
477. /* 这个就是每个文件会将所有监听自己的epitem链起来 */
478. spin_lock(&tfile->f_lock);
479. list_add_tail(&epi->fllink, &tfile->f_ep_links);
480. spin_unlock(&tfile->f_lock);
481.
482. /*
483. * Add the current item to the RB tree. All RB tree operations are
484. * protected by "mtx", and ep_insert() is called with "mtx" held.
485. */
486. /* 都搞定后, 将epitem插入到对应的eventpoll中去 */
487. ep_rbtree_insert(ep, epi);
488.
489. /* We have to drop the new item inside our item list to keep track of it */
490. spin_lock_irqsave(&ep->lock, flags);
491.
492. /* If the file is already "ready" we drop it inside the ready list */
493. /* 到达这里后, 如果我们监听的fd已经有事件发生, 那就要处理一下 */
494. if ((revents & event->events) && !ep_is_linked(&epi->rdllink)) {
495. /* 将当前的epitem加入到ready list中去 */
496. list_add_tail(&epi->rdllink, &ep->rdllist);
497.
498. /* Notify waiting tasks that events are available */
499. /* 谁在epoll_wait, 就唤醒它... */
500. if (waitqueue_active(&ep->wq))
501. wake_up_locked(&ep->wq);
502. /* 谁在epoll当前的epollfd, 也唤醒它... */
503. if (waitqueue_active(&ep->poll_wait))
504. pwake++;
505. }
506.
507. spin_unlock_irqrestore(&ep->lock, flags);
508.
509. atomic_inc(&ep->user->epoll_watches);
510.
511. /* We have to call this outside the lock */
512. if (pwake)
513. ep_poll_safewake(&ep->poll_wait);
514.
515. return 0;
516.
517. error_unregister:
518. ep_unregister_pollwait(ep, epi);
519.
520. /*
521. * We need to do this because an event could have been arrived on some
522. * allocated wait queue. Note that we don't care about the ep->ovflist
523. * list, since that is used/cleaned only inside a section bound by "mtx".
524. * And ep_insert() is called with "mtx" held.
525. */
526. spin_lock_irqsave(&ep->lock, flags);
527. if (ep_is_linked(&epi->rdllink))
528. list_del_init(&epi->rdllink);
529. spin_unlock_irqrestore(&ep->lock, flags);
530.
531. kmem_cache_free(epi_cache, epi);
532.
533. return error;
534. }
535.
536. /*
537. * This is the callback that is used to add our wait queue to the
538. * target file wakeup lists.
539. */
540. /*
541. * 该函数在调用f_op->poll()时会被调用.
542. * 也就是epoll主动poll某个fd时, 用来将epitem与指定的fd关联起来的.
543. * 关联的办法就是使用等待队列(waitqueue)
544. */
545. static void ep_ptable_queue_proc(struct file *file, wait_queue_head_t *whead,
546. poll_table *pt)
547. {
548. struct epitem *epi = ep_item_from_epqueue(pt);
549. struct eppoll_entry *pwq;
550.
551. if (epi->nwait >= 0 && (pwq = kmem_cache_alloc(pwq_cache, GFP_KERNEL))) {
552. /* 初始化等待队列, 指定ep_poll_callback为唤醒时的回调函数,
553. * 当我们监听的fd发生状态改变时, 也就是队列头被唤醒时,
554. * 指定的回调函数将会被调用. */
555. init_waitqueue_func_entry(&pwq->wait, ep_poll_callback);
556. pwq->whead = whead;
557. pwq->base = epi;
558. /* 将刚分配的等待队列成员加入到头中, 头是由fd持有的 */
559. add_wait_queue(whead, &pwq->wait);
560. list_add_tail(&pwq->llink, &epi->pwqlist);
561. /* nwait记录了当前epitem加入到了多少个等待队列中,
562. * 我认为这个值最大也只会是1... */
563. epi->nwait++;
564. } else {
565. /* We have to signal that an error occurred */
566. epi->nwait = -1;
567. }
568. }
569.
570. /*
571. * This is the callback that is passed to the wait queue wakeup
572. * machanism. It is called by the stored file descriptors when they
573. * have events to report.
574. */
575. /*
576. * 这个是关键性的回调函数, 当我们监听的fd发生状态改变时, 它会被调用.
577. * 参数key被当作一个unsigned long整数使用, 携带的是events.
578. */
579. static int ep_poll_callback(wait_queue_t *wait, unsigned mode, int sync, void *key
)
580. {
581. int pwake = 0;
582. unsigned long flags;
583. struct epitem *epi = ep_item_from_wait(wait);//从等待队列获取epitem.需要知道哪
个进程挂载到这个设备
584. struct eventpoll *ep = epi->ep;//获取
585.
586. spin_lock_irqsave(&ep->lock, flags);
587.
588. /*
589. * If the event mask does not contain any poll(2) event, we consider the
590. * descriptor to be disabled. This condition is likely the effect of the
591. * EPOLLONESHOT bit that disables the descriptor when an event is received,
592. * until the next EPOLL_CTL_MOD will be issued.
593. */
594. if (!(epi->event.events & ~EP_PRIVATE_BITS))
595. goto out_unlock;
596.
597. /*
598. * Check the events coming with the callback. At this stage, not
599. * every device reports the events in the "key" parameter of the
600. * callback. We need to be able to handle both cases here, hence the
601. * test for "key" != NULL before the event match test.
602. */
603. /* 没有我们关心的event... */
604. if (key && !((unsigned long) key & epi->event.events))
605. goto out_unlock;
606.
607. /*
608. * If we are trasfering events to userspace, we can hold no locks
609. * (because we're accessing user memory, and because of linux f_op->poll()
610. * semantics). All the events that happens during that period of time are
611. * chained in ep->ovflist and requeued later on.
612. */
613. /*
614. * 这里看起来可能有点费解, 其实干的事情比较简单:
615. * 如果该callback被调用的同时, epoll_wait()已经返回了,
616. * 也就是说, 此刻应用程序有可能已经在循环获取events,
617. * 这种情况下, 内核将此刻发生event的epitem用一个单独的链表
618. * 链起来, 不发给应用程序, 也不丢弃, 而是在下一次epoll_wait
619. * 时返回给用户.
620. */
621. if (unlikely(ep->ovflist != EP_UNACTIVE_PTR)) {
622. if (epi->next == EP_UNACTIVE_PTR) {
623. epi->next = ep->ovflist;
624. ep->ovflist = epi;
625. }
626. goto out_unlock;
627. }
628.
629. /* If this file is already in the ready list we exit soon */
630. /* 将当前的epitem放入ready list */
631. if (!ep_is_linked(&epi->rdllink))
632. list_add_tail(&epi->rdllink, &ep->rdllist);
633.
634. /*
635. * Wake up ( if active ) both the eventpoll wait list and the ->poll()
636. * wait list.
637. */
638. /* 唤醒epoll_wait... */
639. if (waitqueue_active(&ep->wq))
640. wake_up_locked(&ep->wq);
641. /* 如果epollfd也在被poll, 那就唤醒队列里面的所有成员. */
642. if (waitqueue_active(&ep->poll_wait))
643. pwake++;
644.
645. out_unlock:
646. spin_unlock_irqrestore(&ep->lock, flags);
647.
648. /* We have to call this outside the lock */
649. if (pwake)
650. ep_poll_safewake(&ep->poll_wait);
651.
652. return 1;
653. }
654.
655. /*
656. * Implement the event wait interface for the eventpoll file. It is the kernel
657. * part of the user space epoll_wait(2).
658. */
659. SYSCALL_DEFINE4(epoll_wait, int, epfd, struct epoll_event __user *, events,
660. int, maxevents, int, timeout)
661. {
662. int error;
663. struct file *file;
664. struct eventpoll *ep;
665.
666. /* The maximum number of event must be greater than zero */
667. if (maxevents <= 0 || maxevents > EP_MAX_EVENTS)
668. return -EINVAL;
669.
670. /* Verify that the area passed by the user is writeable */
671. /* 这个地方有必要说明一下:
672. * 内核对应用程序采取的策略是"绝对不信任",
673. * 所以内核跟应用程序之间的数据交互大都是copy, 不允许(也时候也是不能...)指针引
用.
674. * epoll_wait()需要内核返回数据给用户空间, 内存由用户程序提供,
675. * 所以内核会用一些手段来验证这一段内存空间是不是有效的.
676. */
677. if (!access_ok(VERIFY_WRITE, events, maxevents * sizeof(struct epoll_event)))
{
678. error = -EFAULT;
679. goto error_return;
680. }
681.
682. /* Get the "struct file *" for the eventpoll file */
683. error = -EBADF;
684. /* 获取epollfd的struct file, epollfd也是文件嘛 */
685. file = fget(epfd);
686. if (!file)
687. goto error_return;
688.
689. /*
690. * We have to check that the file structure underneath the fd
691. * the user passed to us _is_ an eventpoll file.
692. */
693. error = -EINVAL;
694. /* 检查一下它是不是一个真正的epollfd... */
695. if (!is_file_epoll(file))
696. goto error_fput;
697.
698. /*
699. * At this point it is safe to assume that the "private_data" contains
700. * our own data structure.
701. */
702. /* 获取eventpoll结构 */
703. ep = file->private_data;
704.
705. /* Time to fish for events ... */
706. /* OK, 睡觉, 等待事件到来~~ */
707. error = ep_poll(ep, events, maxevents, timeout);
708.
709. error_fput:
710. fput(file);
711. error_return:
712.
713. return error;
714. }
715.
716. /* 这个函数真正将执行epoll_wait的进程带入睡眠状态... */
717. static int ep_poll(struct eventpoll *ep, struct epoll_event __user *events,
718. int maxevents, long timeout)
719. {
720. int res, eavail;
721. unsigned long flags;
722. long jtimeout;
723. wait_queue_t wait;//等待队列
724.
725. /*
726. * Calculate the timeout by checking for the "infinite" value (-1)
727. * and the overflow condition. The passed timeout is in milliseconds,
728. * that why (t * HZ) / 1000.
729. */
730. /* 计算睡觉时间, 毫秒要转换为HZ */
731. jtimeout = (timeout < 0 || timeout >= EP_MAX_MSTIMEO) ?
732. MAX_SCHEDULE_TIMEOUT : (timeout * HZ + 999) / 1000;
733.
734. retry:
735. spin_lock_irqsave(&ep->lock, flags);
736.
737. res = 0;
738. /* 如果ready list不为空, 就不睡了, 直接干活... */
739. if (list_empty(&ep->rdllist)) {
740. /*
741. * We don't have any available event to return to the caller.
742. * We need to sleep here, and we will be wake up by
743. * ep_poll_callback() when events will become available.
744. */
745. /* OK, 初始化一个等待队列, 准备直接把自己挂起,
746. * 注意current是一个宏, 代表当前进程 */
747. init_waitqueue_entry(&wait, current);//初始化等待队列,wait表示当前进程
748. __add_wait_queue_exclusive(&ep->wq, &wait);//挂载到ep结构的等待队列
749.
750. for (;;) {
751. /*
752. * We don't want to sleep if the ep_poll_callback() sends us
753. * a wakeup in between. That's why we set the task state
754. * to TASK_INTERRUPTIBLE before doing the checks.
755. */
756. /* 将当前进程设置位睡眠, 但是可以被信号唤醒的状态,
757. * 注意这个设置是"将来时", 我们此刻还没睡! */
758. set_current_state(TASK_INTERRUPTIBLE);
759. /* 如果这个时候, ready list里面有成员了,
760. * 或者睡眠时间已经过了, 就直接不睡了... */
761. if (!list_empty(&ep->rdllist) || !jtimeout)
762. break;
763. /* 如果有信号产生, 也起床... */
764. if (signal_pending(current)) {
765. res = -EINTR;
766. break;
767. }
768. /* 啥事都没有,解锁, 睡觉... */
769. spin_unlock_irqrestore(&ep->lock, flags);
770. /* jtimeout这个时间后, 会被唤醒,
771. * ep_poll_callback()如果此时被调用,
772. * 那么我们就会直接被唤醒, 不用等时间了...
773. * 再次强调一下ep_poll_callback()的调用时机是由被监听的fd
774. * 的具体实现, 比如socket或者某个设备驱动来决定的,
775. * 因为等待队列头是他们持有的, epoll和当前进程
776. * 只是单纯的等待...
777. **/
778. jtimeout = schedule_timeout(jtimeout);//睡觉
779. spin_lock_irqsave(&ep->lock, flags);
780. }
781. __remove_wait_queue(&ep->wq, &wait);
782.
783. /* OK 我们醒来了... */
784. set_current_state(TASK_RUNNING);
785. }
786. /* Is it worth to try to dig for events ? */
787. eavail = !list_empty(&ep->rdllist) || ep->ovflist != EP_UNACTIVE_PTR;
788.
789. spin_unlock_irqrestore(&ep->lock, flags);
790.
791. /*
792. * Try to transfer events to user space. In case we get 0 events and
793. * there's still timeout left over, we go trying again in search of
794. * more luck.
795. */
796. /* 如果一切正常, 有event发生, 就开始准备数据copy给用户空间了... */
797. if (!res && eavail &&
798. !(res = ep_send_events(ep, events, maxevents)) && jtimeout)
799. goto retry;
800.
801. return res;
802. }
803.
804. /* 这个简单, 我们直奔下一个... */
805. static int ep_send_events(struct eventpoll *ep,
806. struct epoll_event __user *events, int maxevents)
807. {
808. struct ep_send_events_data esed;
809.
810. esed.maxevents = maxevents;
811. esed.events = events;
812.
813. return ep_scan_ready_list(ep, ep_send_events_proc, &esed);
814. }
815.
816. /**
817. * ep_scan_ready_list - Scans the ready list in a way that makes possible for
818. * the scan code, to call f_op->poll(). Also allows for
819. * O(NumReady) performance.
820. *
821. * @ep: Pointer to the epoll private data structure.
822. * @sproc: Pointer to the scan callback.
823. * @priv: Private opaque data passed to the @sproc callback.
824. *
825. * Returns: The same integer error code returned by the @sproc callback.
826. */
827. static int ep_scan_ready_list(struct eventpoll *ep,
828. int (*sproc)(struct eventpoll *,
829. struct list_head *, void *),
830. void *priv)
831. {
832. int error, pwake = 0;
833. unsigned long flags;
834. struct epitem *epi, *nepi;
835. LIST_HEAD(txlist);
836.
837. /*
838. * We need to lock this because we could be hit by
839. * eventpoll_release_file() and epoll_ctl().
840. */
841. mutex_lock(&ep->mtx);
842.
843. /*
844. * Steal the ready list, and re-init the original one to the
845. * empty list. Also, set ep->ovflist to NULL so that events
846. * happening while looping w/out locks, are not lost. We cannot
847. * have the poll callback to queue directly on ep->rdllist,
848. * because we want the "sproc" callback to be able to do it
849. * in a lockless way.
850. */
851. spin_lock_irqsave(&ep->lock, flags);
852. /* 这一步要注意, 首先, 所有监听到events的epitem都链到rdllist上了,
853. * 但是这一步之后, 所有的epitem都转移到了txlist上, 而rdllist被清空了,
854. * 要注意哦, rdllist已经被清空了! */
855. list_splice_init(&ep->rdllist, &txlist);
856. /* ovflist, 在ep_poll_callback()里面我解释过, 此时此刻我们不希望
857. * 有新的event加入到ready list中了, 保存后下次再处理... */
858. ep->ovflist = NULL;
859. spin_unlock_irqrestore(&ep->lock, flags);
860.
861. /*
862. * Now call the callback function.
863. */
864. /* 在这个回调函数里面处理每个epitem
865. * sproc 就是 ep_send_events_proc, 下面会注释到. */
866. error = (*sproc)(ep, &txlist, priv);
867.
868. spin_lock_irqsave(&ep->lock, flags);
869. /*
870. * During the time we spent inside the "sproc" callback, some
871. * other events might have been queued by the poll callback.
872. * We re-insert them inside the main ready-list here.
873. */
874. /* 现在我们来处理ovflist, 这些epitem都是我们在传递数据给用户空间时
875. * 监听到了事件. */
876. for (nepi = ep->ovflist; (epi = nepi) != NULL;
877. nepi = epi->next, epi->next = EP_UNACTIVE_PTR) {
878. /*
879. * We need to check if the item is already in the list.
880. * During the "sproc" callback execution time, items are
881. * queued into ->ovflist but the "txlist" might already
882. * contain them, and the list_splice() below takes care of them.
883. */
884. /* 将这些直接放入readylist */
885. if (!ep_is_linked(&epi->rdllink))
886. list_add_tail(&epi->rdllink, &ep->rdllist);
887. }
888. /*
889. * We need to set back ep->ovflist to EP_UNACTIVE_PTR, so that after
890. * releasing the lock, events will be queued in the normal way inside
891. * ep->rdllist.
892. */
893. ep->ovflist = EP_UNACTIVE_PTR;
894.
895. /*
896. * Quickly re-inject items left on "txlist".
897. */
898. /* 上一次没有处理完的epitem, 重新插入到ready list */
899. list_splice(&txlist, &ep->rdllist);
900.
901. /* ready list不为空, 直接唤醒... */
902. if (!list_empty(&ep->rdllist)) {
903. /*
904. * Wake up (if active) both the eventpoll wait list and
905. * the ->poll() wait list (delayed after we release the lock).
906. */
907. if (waitqueue_active(&ep->wq))
908. wake_up_locked(&ep->wq);
909. if (waitqueue_active(&ep->poll_wait))
910. pwake++;
911. }
912. spin_unlock_irqrestore(&ep->lock, flags);
913.
914. mutex_unlock(&ep->mtx);
915.
916. /* We have to call this outside the lock */
917. if (pwake)
918. ep_poll_safewake(&ep->poll_wait);
919.
920. return error;
921. }
922.
923. /* 该函数作为callbakc在ep_scan_ready_list()中被调用
924. * head是一个链表, 包含了已经ready的epitem,
925. * 这个不是eventpoll里面的ready list, 而是上面函数中的txlist.
926. */
927. static int ep_send_events_proc(struct eventpoll *ep, struct list_head *head,
928. void *priv)
929. {
930. struct ep_send_events_data *esed = priv;
931. int eventcnt;
932. unsigned int revents;
933. struct epitem *epi;
934. struct epoll_event __user *uevent;
935.
936. /*
937. * We can loop without lock because we are passed a task private list.
938. * Items cannot vanish during the loop because ep_scan_ready_list() is
939. * holding "mtx" during this call.
940. */
941. /* 扫描整个链表... */
942. for (eventcnt = 0, uevent = esed->events;
943. !list_empty(head) && eventcnt < esed->maxevents;) {
944. /* 取出第一个成员 */
945. epi = list_first_entry(head, struct epitem, rdllink);
946. /* 然后从链表里面移除 */
947. list_del_init(&epi->rdllink);
948. /* 读取events,
949. * 注意events我们ep_poll_callback()里面已经取过一次了, 为啥还要再取?
950. * 1. 我们当然希望能拿到此刻的最新数据, events是会变的~
951. * 2. 不是所有的poll实现, 都通过等待队列传递了events, 有可能某些驱动压根没
传
952. * 必须主动去读取. */
953. revents = epi->ffd.file->f_op->poll(epi->ffd.file, NULL) &
954. epi->event.events;
955.
956. /*
957. * If the event mask intersect the caller-requested one,
958. * deliver the event to userspace. Again, ep_scan_ready_list()
959. * is holding "mtx", so no operations coming from userspace
960. * can change the item.
961. */
962. if (revents) {
963. /* 将当前的事件和用户传入的数据都copy给用户空间,
964. * 就是epoll_wait()后应用程序能读到的那一堆数据. */
965. if (__put_user(revents, &uevent->events) ||
966. __put_user(epi->event.data, &uevent->data)) {
967. /* 如果copy过程中发生错误, 会中断链表的扫描,
968. * 并把当前发生错误的epitem重新插入到ready list.
969. * 剩下的没处理的epitem也不会丢弃, 在ep_scan_ready_list()
970. * 中它们也会被重新插入到ready list */
971. list_add(&epi->rdllink, head);
972. return eventcnt ? eventcnt : -EFAULT;
973. }
974. eventcnt++;
975. uevent++;
976. if (epi->event.events & EPOLLONESHOT)
977. epi->event.events &= EP_PRIVATE_BITS;
978. else if (!(epi->event.events & EPOLLET)) {
979. /*
980. * If this file has been added with Level
981. * Trigger mode, we need to insert back inside
982. * the ready list, so that the next call to
983. * epoll_wait() will check again the events
984. * availability. At this point, noone can insert
985. * into ep->rdllist besides us. The epoll_ctl()
986. * callers are locked out by
987. * ep_scan_ready_list() holding "mtx" and the
988. * poll callback will queue them in ep->ovflist.
989. */
990. /* 嘿嘿, EPOLLET和非ET的区别就在这一步之差呀~
991. * 如果是ET, epitem是不会再进入到readly list,
992. * 除非fd再次发生了状态改变, ep_poll_callback被调用.
993. * 如果是非ET, 不管你还有没有有效的事件或者数据,
994. * 都会被重新插入到ready list, 再下一次epoll_wait
995. * 时, 会立即返回, 并通知给用户空间. 当然如果这个
996. * 被监听的fds确实没事件也没数据了, epoll_wait会返回一个0,
997. * 空转一次.
998. */
999. list_add_tail(&epi->rdllink, &ep->rdllist);
1000. }
1001. }
1002. }
1003.
1004. return eventcnt;
1005. }
1006.
1007. /* ep_free在epollfd被close时调用,
1008. * 释放一些资源而已, 比较简单 */
1009. static void ep_free(struct eventpoll *ep)
1010. {
1011. struct rb_node *rbp;
1012. struct epitem *epi;
1013.
1014. /* We need to release all tasks waiting for these file */
1015. if (waitqueue_active(&ep->poll_wait))
1016. ep_poll_safewake(&ep->poll_wait);
1017.
1018. /*
1019. * We need to lock this because we could be hit by
1020. * eventpoll_release_file() while we're freeing the "struct eventpoll".
1021. * We do not need to hold "ep->mtx" here because the epoll file
1022. * is on the way to be removed and no one has references to it
1023. * anymore. The only hit might come from eventpoll_release_file() but
1024. * holding "epmutex" is sufficent here.
1025. */
1026. mutex_lock(&epmutex);
1027.
1028. /*
1029. * Walks through the whole tree by unregistering poll callbacks.
1030. */
1031. for (rbp = rb_first(&ep->rbr); rbp; rbp = rb_next(rbp)) {
1032. epi = rb_entry(rbp, struct epitem, rbn);
1033.
1034. ep_unregister_pollwait(ep, epi);
1035. }
1036.
1037. /*
1038. * Walks through the whole tree by freeing each "struct epitem". At this
1039. * point we are sure no poll callbacks will be lingering around, and also by
1040. * holding "epmutex" we can be sure that no file cleanup code will hit
1041. * us during this operation. So we can avoid the lock on "ep->lock".
1042. */
1043. /* 之所以在关闭epollfd之前不需要调用epoll_ctl移除已经添加的fd,
1044. * 是因为这里已经做了... */
1045. while ((rbp = rb_first(&ep->rbr)) != NULL) {
1046. epi = rb_entry(rbp, struct epitem, rbn);
1047. ep_remove(ep, epi);
1048. }
1049.
1050. mutex_unlock(&epmutex);
1051. mutex_destroy(&ep->mtx);
1052. free_uid(ep->user);
1053. kfree(ep);
1054. }
1055.
1056. /* File callbacks that implement the eventpoll file behaviour */
1057. static const struct file_operations eventpoll_fops = {
1058. .release = ep_eventpoll_release,
1059. .poll = ep_eventpoll_poll
1060. };
1061.
1062. /* Fast test to see if the file is an evenpoll file */
1063. static inline int is_file_epoll(struct file *f)
1064. {
1065. return f->f_op == &eventpoll_fops;
1066. }
1067.
1068. /* OK, eventpoll我认为比较重要的函数都注释完了... */