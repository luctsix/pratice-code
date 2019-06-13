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
15. * �������˽�epoll��ʵ��֮ǰ, �����˽��ں˵�3������.
16. * 1. �ȴ����� waitqueue
17. * ���Ǽ򵥽���һ�µȴ�����:
18. * ����ͷ(wait_queue_head_t)��������Դ������,
19. * ���г�Ա(wait_queue_t)��������Դ������,
20. * ��ͷ����Դready��, �����ִ��ÿ����Աָ���Ļص�����,
21. * ��֪ͨ������Դ�Ѿ�ready��, �ȴ����д��¾������˼.
22. * 2. �ں˵�poll����
23. * ��Poll��fd, ������ʵ����֧���ں˵�Poll����,
24. * ����fd��ĳ���ַ��豸,�����Ǹ�socket, ������ʵ��
25. * file_operations�е�poll����, ���Լ�������һ���ȴ�����ͷ.
26. * ����poll fd��ĳ�����̱������һ���ȴ����г�Ա, ��ӵ�
27. * fd�ĶԴ���������ȥ, ��ָ����Դreadyʱ�Ļص�����.
28. * ��socket������, ��������ʵ��һ��poll����, ���Poll��
29. * ������ѯ�Ĵ�������������õ�, �ú����б������poll_wait(),
30. * poll_wait�Ὣ��������Ϊ�ȴ����г�Ա���뵽socket�ĵȴ�������ȥ.
31. * ����socket����״̬�仯ʱ����ͨ������ͷ���֪ͨ���й������Ľ���.
32. * ��һ��������������, ������벻����epoll�����
33. * ��֪fd��״̬�����仯��.
34. * 3. epollfd����Ҳ�Ǹ�fd, ����������Ҳ���Ա�epoll,
35. * ���Բ²�һ�����ǲ��ǿ�������Ƕ��epoll��ȥ...
36. *
37. * epoll�����Ͼ���ʹ���������1,2�������.
38. * �ɼ�epoll����û�и��ں�����ʲô�ر��ӻ��߸���ļ���,
39. * ֻ���������й��ܵ��������, �ﵽ�˳���select��Ч��.
40. */
41.
42. /*
43. * ��ص������ں�֪ʶ:
44. * 1. fd����֪�����ļ�������, ���ں�̬, ��֮��Ӧ����struct file�ṹ,
45. * ���Կ������ں�̬���ļ�������.
46. * 2. spinlock, ������, ����Ҫ�ǳ�С��ʹ�õ���,
47. * �����ǵ���spin_lock_irqsave()��ʱ��, �жϹر�, ���ᷢ�����̵���,
48. * ����������Դ����CPUҲ�޷�����. ������Ǻ�ǿ����, ����ֻ����һЩ
49. * �ǳ��������Ĳ���.
50. * 3. ���ü������ں����Ƿǳ���Ҫ�ĸ���,
51. * �ں˴������澭����Щrelease, free�ͷ���Դ�ĺ������������κ���,
52. * ������Ϊ��Щ�����������ڶ�������ü������0ʱ������,
53. * ��Ȼû�н�����ʹ������Щ����, ��ȻҲ����Ҫ����.
54. * struct file �ǳ������ü�����.
55. */
56.
57. /* --- epoll��ص����ݽṹ --- */
58.
59. /*
60. * This structure is stored inside the "private_data" member of the file
61. * structure and rapresent the main data sructure for the eventpoll
62. * interface.
63. */
64. /* ÿ����һ��epollfd, �ں˾ͻ����һ��eventpoll��֮��Ӧ, ����˵��
65. * �ں�̬��epollfd. */
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
76. /* ���, �޸Ļ���ɾ������fd��ʱ��, �Լ�epoll_wait����, ���û��ռ�
77. * ��������ʱ����������������, �������û��ռ���Է��ĵ��ڶ���߳�
78. * ��ͬʱִ��epoll��صĲ���, �ں˼��Ѿ����˱���. */
79. struct mutex mtx;
80.
81. /* Wait queue used by sys_epoll_wait() */
82. /* ����epoll_wait()ʱ, ���Ǿ���"˯"��������ȴ�������... */
83. wait_queue_head_t wq;
84.
85. /* Wait queue used by file->poll() */
86. /* �������epollfd���±�poll��ʱ��... */
87. wait_queue_head_t poll_wait;
88.
89. /* List of ready file descriptors */
90. /* �����Ѿ�ready��epitem��������������� */
91. struct list_head rdllist;
92.
93. /* RB tree root used to store monitored fd structs */
94. /* ����Ҫ������epitem�������� */
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
105. /* ���ﱣ����һЩ�û�����, ����fd�������������ֵ�ȵ� */
106. struct user_struct *user;
107. };
108.
109. /*
110. * Each file descriptor added to the eventpoll interface will
111. * have an entry of this type linked to the "rbr" RB tree.
112. */
113. /* epitem ��ʾһ����������fd */
114. struct epitem {
115. /* RB tree node used to link this structure to the eventpoll RB tree */
116. /* rb_node, ��ʹ��epoll_ctl()��һ��fds���뵽ĳ��epollfdʱ, �ں˻����
117. * һ����epitem��fds�Ƕ�Ӧ, ����������rb_tree����ʽ��֯����, tree��root
118. * ������epollfd, Ҳ����struct eventpoll��.
119. * ������ʹ��rb_tree��ԭ������Ϊ����߲���,�����Լ�ɾ�����ٶ�.
120. * rb_tree������3������������O(lgN)��ʱ�临�Ӷ� */
121. struct rb_node rbn;
122.
123. /* List header used to link this structure to the eventpoll ready list */
124. /* ����ڵ�, �����Ѿ�ready��epitem���ᱻ����eventpoll��rdllist�� */
125. struct list_head rdllink;
126.
127. /*
128. * Works together "struct eventpoll"->ovflist in keeping the
129. * single linked chain of items.
130. */
131. /* ����ڴ������ٽ���... */
132. struct epitem *next;
133.
134. /* The file descriptor information this item refers to */
135. /* epitem��Ӧ��fd��struct file */
136. struct epoll_filefd ffd;
137.
138. /* Number of active wait queue attached to poll operations */
139. int nwait;
140.
141. /* List containing poll wait queues */
142. struct list_head pwqlist;
143.
144. /* The "container" of this item */
145. /* ��ǰepitem�����ĸ�eventpoll */
146. struct eventpoll *ep;
147.
148. /* List header used to link this item to the "struct file" items list */
149. struct list_head fllink;
150.
151. /* The structure that describe the interested events and the source fd */
152. /* ��ǰ��epitem��ϵ��Щevents, ��������ǵ���epoll_ctlʱ���û�̬���ݹ��� */
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
191. /* --- ����ע�� --- */
192.
193. /* ��û����, �����epoll_create()������, ����ɶҲ����ֱ�ӵ���epoll_create1��,
194. * ������Ҳ���Է���, size���������ʵ��û���κ��ô���... */
195. SYSCALL_DEFINE1(epoll_create, int, size)
196. {
197. if (size <= 0)
198. return -EINVAL;
199.
200. return sys_epoll_create1(0);
201. }
202.
203. /* �����������epoll_create��~~ */
204. SYSCALL_DEFINE1(epoll_create1, int, flags)
205. {
206. int error;
207. struct eventpoll *ep = NULL;//��������
208.
209. /* Check the EPOLL_* constant for consistency. */
210. /* ���ûɶ�ô�... */
211. BUILD_BUG_ON(EPOLL_CLOEXEC != O_CLOEXEC);
212.
213. /* ����epoll����, ĿǰΨһ��Ч��FLAG����CLOEXEC */
214. if (flags & ~EPOLL_CLOEXEC)
215. return -EINVAL;
216. /*
217. * Create the internal data structure ("struct eventpoll").
218. */
219. /* ����һ��struct eventpoll, ����ͳ�ʼ��ϸ�������������~ */
220. error = ep_alloc(&ep);
221. if (error < 0)
222. return error;
223. /*
224. * Creates all the items needed to setup an eventpoll file. That is,
225. * a file structure and a free file descriptor.
226. */
227. /* �����Ǵ���һ������fd, ˵�����ͻ�����...������˵:
228. * epollfd����������һ���������ļ���֮��Ӧ, �����ں���Ҫ����һ��
229. * "����"���ļ�, ��Ϊ֮����������struct file�ṹ, ������������fd.
230. * ����2�������ȽϹؼ�:
231. * eventpoll_fops, fops����file operations, ���ǵ��������ļ�(�����������)��
�в���(�����)ʱ,
232. * fops����ĺ���ָ��ָ�������Ĳ���ʵ��, ����C++�����麯��������ĸ���.
233. * epollֻʵ����poll��release(����close)����, �����ļ�ϵͳ��������VFSȫȨ����
��.
234. * ep, ep����struct epollevent, ������Ϊһ��˽�����ݱ�����struct file��private
ָ������.
235. * ��ʵ˵����, ����Ϊ����ͨ��fd�ҵ�struct file, ͨ��struct file���ҵ�eventpoll
�ṹ.
236. * �����һ��Linux���ַ��豸��������, ����Ӧ���Ǻܺ�����,
237. * �Ƽ��Ķ� <Linux device driver 3rd>
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
248. * ������epollfd��, ����������Ҫ���������fd��
249. * ����epoll_ctl
250. * epfd ����epollfd
251. * op ADD,MOD,DEL
252. * fd ��Ҫ������������
253. * event ���ǹ��ĵ�events
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
267. * �������Լ����û��ռ佫epoll_event�ṹcopy���ں˿ռ�.
268. */
269. if (ep_op_has_event(op) &&
270. copy_from_user(&epds, event, sizeof(struct epoll_event)))
271. goto error_return;
272.
273. /* Get the "struct file *" for the eventpoll file */
274. /* ȡ��struct file�ṹ, epfd��Ȼ��������fd, ��ô�ں˿ռ�
275. * �ͻ�����֮���ڵ�һ��struct file�ṹ
276. * ����ṹ��epoll_create1()��, �ɺ���anon_inode_getfd()���� */
277. error = -EBADF;
278. file = fget(epfd);
279. if (!file)
280. goto error_return;
281.
282. /* Get the "struct file *" for the target file */
283. /* ������Ҫ������fd, ����ȻҲ�и�struct file�ṹ, ����2����Ҫ�����Ŷ */
284. tfile = fget(fd);
285. if (!tfile)
286. goto error_fput;
287.
288. /* The target file descriptor must support poll */
289. error = -EPERM;
290. /* ����������ļ���֧��poll, �Ǿ�û����.
291. * ��֪��ʲô�����, �ļ��᲻֧��poll��?
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
302. /* epoll�����Լ������Լ�... */
303. if (file == tfile || !is_file_epoll(file))
304. goto error_tgt_fput;
305.
306. /*
307. * At this point it is safe to assume that the "private_data" contains
308. * our own data structure.
309. */
310. /* ȡ�����ǵ�eventpoll�ṹ, ������epoll_create1()�еķ��� */
311. ep = file->private_data;
312.
313. /* �������Ĳ����п����޸����ݽṹ����, ��֮~ */
314. mutex_lock(&ep->mtx);
315.
316. /*
317. * Try to lookup the file inside our RB tree, Since we grabbed "mtx"
318. * above, we can be sure to be able to use the item looked up by
319. * ep_find() till we release the mutex.
320. */
321. /* ����ÿһ��������fd, �ں˶��з�Ƭһ��epitem�ṹ,
322. * ��������Ҳ֪��, epoll�ǲ������ظ����fd��,
323. * �����������Ȳ��Ҹ�fd�ǲ����Ѿ�������.
324. * ep_find()��ʵ����RBTREE����, ��C++STL��map���һ����, O(lgn)��ʱ�临�Ӷ�.
325. */
326. epi = ep_find(ep, tfile, fd);
327.
328. error = -EINVAL;
329. switch (op) {
330. /* �������ǹ������ */
331. case EPOLL_CTL_ADD:
332. if (!epi) {
333. /* ֮ǰ��findû���ҵ���Ч��epitem, ֤���ǵ�һ�β���, ����!
334. * �������ǿ���֪��, POLLERR��POLLHUP�¼��ں����ǻ���ĵ�
335. * */
336. epds.events |= POLLERR | POLLHUP;
337. /* rbtree����, �����ep_insert()�ķ���
338. * ��ʵ�Ҿ���������insert�Ļ�, ֮ǰ��findӦ��
339. * �ǿ���ʡ����... */
340. error = ep_insert(ep, &epds, tfile, fd);
341. } else
342. /* �ҵ���!? �ظ����! */
343. error = -EEXIST;
344. break;
345. /* ɾ�����޸Ĳ������Ƚϼ� */
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
371. /* ����һ��eventpoll�ṹ */
372. static int ep_alloc(struct eventpoll **pep)
373. {
374. int error;
375. struct user_struct *user;
376. struct eventpoll *ep;
377.
378. /* ��ȡ��ǰ�û���һЩ��Ϣ, �����ǲ���root��, ������fd��Ŀ�� */
379. user = get_current_user();
380. error = -ENOMEM;
381. ep = kzalloc(sizeof(*ep), GFP_KERNEL);
382. if (unlikely(!ep))
383. goto free_uid;
384.
385. /* ��Щ���ǳ�ʼ���� */
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
409. * ep_insert()��epoll_ctl()�б�����, �����epollfd�������һ������fd�Ĺ���
410. * tfile��fd���ں�̬��struct file�ṹ
411. */
412. static int ep_insert(struct eventpoll *ep, struct epoll_event *event,
413. struct file *tfile, int fd)
414. {
415. int error, revents, pwake = 0;
416. unsigned long flags;
417. struct epitem *epi;
418. struct ep_pqueue epq;
419.
420. /* �鿴�Ƿ�ﵽ��ǰ�û����������� */
421. if (unlikely(atomic_read(&ep->user->epoll_watches) >=
422. max_user_watches))
423. return -ENOSPC;
424. /* ��������slab�з���һ��epitem */
425. if (!(epi = kmem_cache_alloc(epi_cache, GFP_KERNEL)))
426. return -ENOMEM;
427.
428. /* Item initialization follow here ... */
429. /* ��Щ������س�Ա�ĳ�ʼ��... */
430. INIT_LIST_HEAD(&epi->rdllink);
431. INIT_LIST_HEAD(&epi->fllink);
432. INIT_LIST_HEAD(&epi->pwqlist);
433. epi->ep = ep;
434. /* ���ﱣ����������Ҫ�������ļ�fd������file�ṹ */
435. ep_set_ffd(&epi->ffd, tfile, fd);
436. epi->event = *event;
437. epi->nwait = 0;
438. /* ���ָ��ĳ�ֵ����NULLŶ... */
439. epi->next = EP_UNACTIVE_PTR;
440.
441. /* Initialize the poll table using the queue callback */
442. /* ��, ��������Ҫ���뵽poll�������� */
443. epq.epi = epi;
444. /* ��ʼ��һ��poll_table
445. * ��ʵ����ָ������poll_wait(ע�ⲻ��epoll_wait!!!)ʱ�Ļص�����,�����ǹ�����Щ
events,
446. * ep_ptable_queue_proc()�������ǵĻص���, ��ֵ������event������ */
447. init_poll_funcptr(&epq.pt, ep_ptable_queue_proc);
448.
449. /*
450. * Attach the item to the poll hooks and get current event bits.
451. * We can safely use the file* here because its usage count has
452. * been increased by the caller of this function. Note that after
453. * this operation completes, the poll callback can start hitting
454. * the new item.
455. */
456. /* ��һ���ܹؼ�, Ҳ�Ƚ��Ѷ�, ��ȫ���ں˵�poll���Ƶ��µ�...
457. * ����, f_op->poll()һ����˵ֻ�Ǹ�wrapper, �������������pollʵ��,
458. * ��UDP��socket������, ������������ĵ�������: f_op->poll(), sock_poll(),
459. * udp_poll(), datagram_poll(), sock_poll_wait(), �����õ���������ָ����
460. * ep_ptable_queue_proc()����ص�����...(����ĵ���·��...).
461. * �����һ��, ���ǵ�epitem�͸����socket����������, ������״̬�仯ʱ,
462. * ��ͨ��ep_poll_callback()��֪ͨ.
463. * ���, ������������ѯ��ǰ��fd�ǲ����Ѿ���ɶevent�Ѿ�ready��, �еĻ�
464. * �Ὣevent����. */
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
477. /* �������ÿ���ļ��Ὣ���м����Լ���epitem������ */
478. spin_lock(&tfile->f_lock);
479. list_add_tail(&epi->fllink, &tfile->f_ep_links);
480. spin_unlock(&tfile->f_lock);
481.
482. /*
483. * Add the current item to the RB tree. All RB tree operations are
484. * protected by "mtx", and ep_insert() is called with "mtx" held.
485. */
486. /* ���㶨��, ��epitem���뵽��Ӧ��eventpoll��ȥ */
487. ep_rbtree_insert(ep, epi);
488.
489. /* We have to drop the new item inside our item list to keep track of it */
490. spin_lock_irqsave(&ep->lock, flags);
491.
492. /* If the file is already "ready" we drop it inside the ready list */
493. /* ���������, ������Ǽ�����fd�Ѿ����¼�����, �Ǿ�Ҫ����һ�� */
494. if ((revents & event->events) && !ep_is_linked(&epi->rdllink)) {
495. /* ����ǰ��epitem���뵽ready list��ȥ */
496. list_add_tail(&epi->rdllink, &ep->rdllist);
497.
498. /* Notify waiting tasks that events are available */
499. /* ˭��epoll_wait, �ͻ�����... */
500. if (waitqueue_active(&ep->wq))
501. wake_up_locked(&ep->wq);
502. /* ˭��epoll��ǰ��epollfd, Ҳ������... */
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
541. * �ú����ڵ���f_op->poll()ʱ�ᱻ����.
542. * Ҳ����epoll����pollĳ��fdʱ, ������epitem��ָ����fd����������.
543. * �����İ취����ʹ�õȴ�����(waitqueue)
544. */
545. static void ep_ptable_queue_proc(struct file *file, wait_queue_head_t *whead,
546. poll_table *pt)
547. {
548. struct epitem *epi = ep_item_from_epqueue(pt);
549. struct eppoll_entry *pwq;
550.
551. if (epi->nwait >= 0 && (pwq = kmem_cache_alloc(pwq_cache, GFP_KERNEL))) {
552. /* ��ʼ���ȴ�����, ָ��ep_poll_callbackΪ����ʱ�Ļص�����,
553. * �����Ǽ�����fd����״̬�ı�ʱ, Ҳ���Ƕ���ͷ������ʱ,
554. * ָ���Ļص��������ᱻ����. */
555. init_waitqueue_func_entry(&pwq->wait, ep_poll_callback);
556. pwq->whead = whead;
557. pwq->base = epi;
558. /* ���շ���ĵȴ����г�Ա���뵽ͷ��, ͷ����fd���е� */
559. add_wait_queue(whead, &pwq->wait);
560. list_add_tail(&pwq->llink, &epi->pwqlist);
561. /* nwait��¼�˵�ǰepitem���뵽�˶��ٸ��ȴ�������,
562. * ����Ϊ���ֵ���Ҳֻ����1... */
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
576. * ����ǹؼ��ԵĻص�����, �����Ǽ�����fd����״̬�ı�ʱ, ���ᱻ����.
577. * ����key������һ��unsigned long����ʹ��, Я������events.
578. */
579. static int ep_poll_callback(wait_queue_t *wait, unsigned mode, int sync, void *key
)
580. {
581. int pwake = 0;
582. unsigned long flags;
583. struct epitem *epi = ep_item_from_wait(wait);//�ӵȴ����л�ȡepitem.��Ҫ֪����
�����̹��ص�����豸
584. struct eventpoll *ep = epi->ep;//��ȡ
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
603. /* û�����ǹ��ĵ�event... */
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
614. * ���￴���������е�ѽ�, ��ʵ�ɵ�����Ƚϼ�:
615. * �����callback�����õ�ͬʱ, epoll_wait()�Ѿ�������,
616. * Ҳ����˵, �˿�Ӧ�ó����п����Ѿ���ѭ����ȡevents,
617. * ���������, �ں˽��˿̷���event��epitem��һ������������
618. * ������, ������Ӧ�ó���, Ҳ������, ��������һ��epoll_wait
619. * ʱ���ظ��û�.
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
630. /* ����ǰ��epitem����ready list */
631. if (!ep_is_linked(&epi->rdllink))
632. list_add_tail(&epi->rdllink, &ep->rdllist);
633.
634. /*
635. * Wake up ( if active ) both the eventpoll wait list and the ->poll()
636. * wait list.
637. */
638. /* ����epoll_wait... */
639. if (waitqueue_active(&ep->wq))
640. wake_up_locked(&ep->wq);
641. /* ���epollfdҲ�ڱ�poll, �Ǿͻ��Ѷ�����������г�Ա. */
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
671. /* ����ط��б�Ҫ˵��һ��:
672. * �ں˶�Ӧ�ó����ȡ�Ĳ�����"���Բ�����",
673. * �����ں˸�Ӧ�ó���֮������ݽ�������copy, ������(Ҳʱ��Ҳ�ǲ���...)ָ����
��.
674. * epoll_wait()��Ҫ�ں˷������ݸ��û��ռ�, �ڴ����û������ṩ,
675. * �����ں˻���һЩ�ֶ�����֤��һ���ڴ�ռ��ǲ�����Ч��.
676. */
677. if (!access_ok(VERIFY_WRITE, events, maxevents * sizeof(struct epoll_event)))
{
678. error = -EFAULT;
679. goto error_return;
680. }
681.
682. /* Get the "struct file *" for the eventpoll file */
683. error = -EBADF;
684. /* ��ȡepollfd��struct file, epollfdҲ���ļ��� */
685. file = fget(epfd);
686. if (!file)
687. goto error_return;
688.
689. /*
690. * We have to check that the file structure underneath the fd
691. * the user passed to us _is_ an eventpoll file.
692. */
693. error = -EINVAL;
694. /* ���һ�����ǲ���һ��������epollfd... */
695. if (!is_file_epoll(file))
696. goto error_fput;
697.
698. /*
699. * At this point it is safe to assume that the "private_data" contains
700. * our own data structure.
701. */
702. /* ��ȡeventpoll�ṹ */
703. ep = file->private_data;
704.
705. /* Time to fish for events ... */
706. /* OK, ˯��, �ȴ��¼�����~~ */
707. error = ep_poll(ep, events, maxevents, timeout);
708.
709. error_fput:
710. fput(file);
711. error_return:
712.
713. return error;
714. }
715.
716. /* �������������ִ��epoll_wait�Ľ��̴���˯��״̬... */
717. static int ep_poll(struct eventpoll *ep, struct epoll_event __user *events,
718. int maxevents, long timeout)
719. {
720. int res, eavail;
721. unsigned long flags;
722. long jtimeout;
723. wait_queue_t wait;//�ȴ�����
724.
725. /*
726. * Calculate the timeout by checking for the "infinite" value (-1)
727. * and the overflow condition. The passed timeout is in milliseconds,
728. * that why (t * HZ) / 1000.
729. */
730. /* ����˯��ʱ��, ����Ҫת��ΪHZ */
731. jtimeout = (timeout < 0 || timeout >= EP_MAX_MSTIMEO) ?
732. MAX_SCHEDULE_TIMEOUT : (timeout * HZ + 999) / 1000;
733.
734. retry:
735. spin_lock_irqsave(&ep->lock, flags);
736.
737. res = 0;
738. /* ���ready list��Ϊ��, �Ͳ�˯��, ֱ�Ӹɻ�... */
739. if (list_empty(&ep->rdllist)) {
740. /*
741. * We don't have any available event to return to the caller.
742. * We need to sleep here, and we will be wake up by
743. * ep_poll_callback() when events will become available.
744. */
745. /* OK, ��ʼ��һ���ȴ�����, ׼��ֱ�Ӱ��Լ�����,
746. * ע��current��һ����, ����ǰ���� */
747. init_waitqueue_entry(&wait, current);//��ʼ���ȴ�����,wait��ʾ��ǰ����
748. __add_wait_queue_exclusive(&ep->wq, &wait);//���ص�ep�ṹ�ĵȴ�����
749.
750. for (;;) {
751. /*
752. * We don't want to sleep if the ep_poll_callback() sends us
753. * a wakeup in between. That's why we set the task state
754. * to TASK_INTERRUPTIBLE before doing the checks.
755. */
756. /* ����ǰ��������λ˯��, ���ǿ��Ա��źŻ��ѵ�״̬,
757. * ע�����������"����ʱ", ���Ǵ˿̻�û˯! */
758. set_current_state(TASK_INTERRUPTIBLE);
759. /* ������ʱ��, ready list�����г�Ա��,
760. * ����˯��ʱ���Ѿ�����, ��ֱ�Ӳ�˯��... */
761. if (!list_empty(&ep->rdllist) || !jtimeout)
762. break;
763. /* ������źŲ���, Ҳ��... */
764. if (signal_pending(current)) {
765. res = -EINTR;
766. break;
767. }
768. /* ɶ�¶�û��,����, ˯��... */
769. spin_unlock_irqrestore(&ep->lock, flags);
770. /* jtimeout���ʱ���, �ᱻ����,
771. * ep_poll_callback()�����ʱ������,
772. * ��ô���Ǿͻ�ֱ�ӱ�����, ���õ�ʱ����...
773. * �ٴ�ǿ��һ��ep_poll_callback()�ĵ���ʱ�����ɱ�������fd
774. * �ľ���ʵ��, ����socket����ĳ���豸������������,
775. * ��Ϊ�ȴ�����ͷ�����ǳ��е�, epoll�͵�ǰ����
776. * ֻ�ǵ����ĵȴ�...
777. **/
778. jtimeout = schedule_timeout(jtimeout);//˯��
779. spin_lock_irqsave(&ep->lock, flags);
780. }
781. __remove_wait_queue(&ep->wq, &wait);
782.
783. /* OK ����������... */
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
796. /* ���һ������, ��event����, �Ϳ�ʼ׼������copy���û��ռ���... */
797. if (!res && eavail &&
798. !(res = ep_send_events(ep, events, maxevents)) && jtimeout)
799. goto retry;
800.
801. return res;
802. }
803.
804. /* �����, ����ֱ����һ��... */
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
852. /* ��һ��Ҫע��, ����, ���м�����events��epitem������rdllist����,
853. * ������һ��֮��, ���е�epitem��ת�Ƶ���txlist��, ��rdllist�������,
854. * Ҫע��Ŷ, rdllist�Ѿ��������! */
855. list_splice_init(&ep->rdllist, &txlist);
856. /* ovflist, ��ep_poll_callback()�����ҽ��͹�, ��ʱ�˿����ǲ�ϣ��
857. * ���µ�event���뵽ready list����, ������´��ٴ���... */
858. ep->ovflist = NULL;
859. spin_unlock_irqrestore(&ep->lock, flags);
860.
861. /*
862. * Now call the callback function.
863. */
864. /* ������ص��������洦��ÿ��epitem
865. * sproc ���� ep_send_events_proc, �����ע�͵�. */
866. error = (*sproc)(ep, &txlist, priv);
867.
868. spin_lock_irqsave(&ep->lock, flags);
869. /*
870. * During the time we spent inside the "sproc" callback, some
871. * other events might have been queued by the poll callback.
872. * We re-insert them inside the main ready-list here.
873. */
874. /* ��������������ovflist, ��Щepitem���������ڴ������ݸ��û��ռ�ʱ
875. * ���������¼�. */
876. for (nepi = ep->ovflist; (epi = nepi) != NULL;
877. nepi = epi->next, epi->next = EP_UNACTIVE_PTR) {
878. /*
879. * We need to check if the item is already in the list.
880. * During the "sproc" callback execution time, items are
881. * queued into ->ovflist but the "txlist" might already
882. * contain them, and the list_splice() below takes care of them.
883. */
884. /* ����Щֱ�ӷ���readylist */
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
898. /* ��һ��û�д������epitem, ���²��뵽ready list */
899. list_splice(&txlist, &ep->rdllist);
900.
901. /* ready list��Ϊ��, ֱ�ӻ���... */
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
923. /* �ú�����Ϊcallbakc��ep_scan_ready_list()�б�����
924. * head��һ������, �������Ѿ�ready��epitem,
925. * �������eventpoll�����ready list, �������溯���е�txlist.
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
941. /* ɨ����������... */
942. for (eventcnt = 0, uevent = esed->events;
943. !list_empty(head) && eventcnt < esed->maxevents;) {
944. /* ȡ����һ����Ա */
945. epi = list_first_entry(head, struct epitem, rdllink);
946. /* Ȼ������������Ƴ� */
947. list_del_init(&epi->rdllink);
948. /* ��ȡevents,
949. * ע��events����ep_poll_callback()�����Ѿ�ȡ��һ����, Ϊɶ��Ҫ��ȡ?
950. * 1. ���ǵ�Ȼϣ�����õ��˿̵���������, events�ǻ���~
951. * 2. �������е�pollʵ��, ��ͨ���ȴ����д�����events, �п���ĳЩ����ѹ��û
��
952. * ��������ȥ��ȡ. */
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
963. /* ����ǰ���¼����û���������ݶ�copy���û��ռ�,
964. * ����epoll_wait()��Ӧ�ó����ܶ�������һ������. */
965. if (__put_user(revents, &uevent->events) ||
966. __put_user(epi->event.data, &uevent->data)) {
967. /* ���copy�����з�������, ���ж������ɨ��,
968. * ���ѵ�ǰ���������epitem���²��뵽ready list.
969. * ʣ�µ�û�����epitemҲ���ᶪ��, ��ep_scan_ready_list()
970. * ������Ҳ�ᱻ���²��뵽ready list */
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
990. /* �ٺ�, EPOLLET�ͷ�ET�����������һ��֮��ѽ~
991. * �����ET, epitem�ǲ����ٽ��뵽readly list,
992. * ����fd�ٴη�����״̬�ı�, ep_poll_callback������.
993. * ����Ƿ�ET, �����㻹��û����Ч���¼���������,
994. * ���ᱻ���²��뵽ready list, ����һ��epoll_wait
995. * ʱ, ����������, ��֪ͨ���û��ռ�. ��Ȼ������
996. * ��������fdsȷʵû�¼�Ҳû������, epoll_wait�᷵��һ��0,
997. * ��תһ��.
998. */
999. list_add_tail(&epi->rdllink, &ep->rdllist);
1000. }
1001. }
1002. }
1003.
1004. return eventcnt;
1005. }
1006.
1007. /* ep_free��epollfd��closeʱ����,
1008. * �ͷ�һЩ��Դ����, �Ƚϼ� */
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
1043. /* ֮�����ڹر�epollfd֮ǰ����Ҫ����epoll_ctl�Ƴ��Ѿ���ӵ�fd,
1044. * ����Ϊ�����Ѿ�����... */
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
1068. /* OK, eventpoll����Ϊ�Ƚ���Ҫ�ĺ�����ע������... */