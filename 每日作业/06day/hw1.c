#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int id;		//������
	struct Node *next;	//ָ����
}SLIST;

SLIST* SListCreat(){//����ͷ���
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

void SListPrint(SLIST* pHead) //�������нڵ�
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

//ɾ��ֵΪx�����н��
int SListNodeDelPro(SLIST *pHead, int x)
{
	SLIST* p = pHead->next;
	SLIST* q = pHead;
	int flag = 0;
	if(p == NULL)
	{
		printf("����Ϊ��...\n");
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

//����ڵ����򣬽�������������
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
//ע�⣬����nextָ�뻹��Ҫ����

void sort(SLIST* pHead){
	SLIST* p = pHead->next;
	SLIST tmp;
	while(p)
	{
		SLIST* pPre = p;
		SLIST* pCur = p->next;
		
		while(pCur)
		{
			if (pPre->id > pCur->id) //����
			{
				//�����ڵ�����
				tmp = *pCur;
				*pCur = *pPre;
				*pPre = tmp;

				//�����½���һ��nextָ����
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
//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
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

//��ת����Ľڵ㣨���������Ƿ�ת������������ָ����
//���磺ԭ����ΪA->B->C->D,ʹ�������ó�ΪD->C->B->A
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

int SListDestroy(SLIST* pHead){	//�ͷ����нڵ�
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

	pHead = SListCreat(); //����ͷ���
	printf("\n����ͷ����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeDelPro(pHead, 4);//ɾ������ֵΪ4�Ľ��
	printf("\nɾ������ֵΪ4�Ľ��\n");
	SListPrint(pHead); //�������нڵ�

	//SListNodeSort(pHead);//����ڵ�����
	sort(pHead);
	printf("\n����ڵ�����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeInsertPro(pHead, 5);//�������5
	printf("\n�������5��\n");
	SListPrint(pHead); //�������нڵ�

	//��ת����Ľڵ㣨���������Ƿ�ת��
	SListNodeReverse(pHead);
	printf("\n��ת����Ľڵ�\n");
	SListPrint(pHead); //�������нڵ�

	SListDestroy(pHead);//�ͷ����нڵ�
	pHead = NULL;

	return 0;
}
