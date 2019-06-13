#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int id;		//数据域
	struct Node *next;	//指针域
}SLIST;

SLIST* SListCreat(){//创建头结点
	SLIST* pHead;
	pHead->next = (SLIST*)malloc(sizeof(SLIST));
	SLIST* q = pHead;
	printf("please enter a int:");
	int n;
	scanf("%d", &n);
	getchar();
	while(n>0)
	{
		
		SLIST* p = (SLIST*)malloc(sizeof(SLIST));
		p->next = NULL;
		p->id = n;
		q->next = p;
		q = q->next;
		printf("please enter a int:");
		scanf("%d", &n);
		getchar();
		
	}
	return pHead;
}

void SListPrint(SLIST* pHead) //遍历所有节点
{
	SLIST* p = pHead->next;
	printf("pHead->");
	while(p)
	{
		printf("%d->", p->id);
		p = p->next;
	}
	printf("NULL(END)\n");	
}

//删除值为x的所有结点
int SListNodeDelPro(SLIST *pHead, int x)
{
	SLIST* p = pHead->next;
	SLIST* q = pHead;
	int flag = 0;
	if(p == NULL)
	{
		printf("链表为空...\n");
		return -1;
	}
	while(p)
	{
		if(p->id == 4)
		{
			q->next = p->next;
			flag++;
		}
		q = p;
		p = p->next;
	}
	if(flag == 0)
	{
		printf("there is not exist a node whose value is %d\n", x);
	}
	return 0;
}

//链表节点排序，交换的是数据域
int SListNodeSort(SLIST *pHead){
	SLIST *p = pHead->next;
	SLIST *q = p->next;
	
	if(!pHead)
	{
		return -1;
	}
	while(p)
	{
		int i;
		q = p->next;
		while(q)
		{
			if(p->id > q->id)
			{
				i 	  = q->id;
				q->id = p->id;
				p->id = i;
			}
			q = q->next;
		}
		//p->id = i;
		p = p->next;
	}
	return 0;
}
//注意，排序，next指针还需要交换

void sort(SLIST* pHead){
	SLIST* p = pHead->next;
	SLIST tmp;
	while(p)
	{
		SLIST* pPre = p;
		SLIST* pCur = p->next;
		
		while(pCur)
		{
			if (pPre->id > pCur->id) //升序
			{
				//交换节点整体
				tmp = *pCur;
				*pCur = *pPre;
				*pPre = tmp;

				//再重新交换一下next指针域
				tmp.next = pCur->next;
				pCur->next = pPre->next;
				pPre->next = tmp.next;
			}
			pCur = pCur->next;
			pPre = pPre->next;
		}
		p = p->next;
	}
}
//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(SLIST *pHead, int x){
	SLIST* p 	= pHead->next;
	SLIST* pPre = pHead;
	SLIST* q = (SLIST*)malloc(sizeof(SLIST));
	q->id = x;	q->next = NULL;
	while(p)
	{
		if(p->id > x)
		{
			pPre->next = q;
			q->next    = p;
			return 0;
		}
		p = p->next;
		pPre = pPre->next;
	}
	pPre->next = q;
	return 0;
}

//翻转链表的节点（不是排序，是翻转），交换的是指针域
//例如：原链表为A->B->C->D,使链表逆置成为D->C->B->A
int SListNodeReverse(SLIST *pHead){
	if(!pHead)
	{
		return -1;
	}
	SLIST* p   = pHead->next;
	SLIST* q   = p->next;
	p->next = NULL;
	SLIST* tmp = (SLIST*)malloc(sizeof(SLIST));
	while(q)
	{
			tmp = q;
			q = q->next;
			tmp->next = p;
			pHead->next = tmp;
			p = tmp;
	}
	return 0;
}

int SListDestroy(SLIST* pHead){	//释放所有节点
	SLIST* p = pHead->next;
	SLIST* q = NULL;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(pHead);
	return 0;
}

int main()
{
	SLIST *pHead = NULL;

	pHead = SListCreat(); //创建头结点
	printf("\n创建头结点后\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeDelPro(pHead, 4);//删除所有值为4的结点
	printf("\n删除所有值为4的结点\n");
	SListPrint(pHead); //遍历所有节点

	//SListNodeSort(pHead);//链表节点排序
	sort(pHead);
	printf("\n链表节点排序\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeInsertPro(pHead, 5);//升序插入5
	printf("\n升序插入5后\n");
	SListPrint(pHead); //遍历所有节点

	//翻转链表的节点（不是排序，是翻转）
	SListNodeReverse(pHead);
	printf("\n翻转链表的节点\n");
	SListPrint(pHead); //遍历所有节点

	SListDestroy(pHead);//释放所有节点
	pHead = NULL;

	return 0;
}
