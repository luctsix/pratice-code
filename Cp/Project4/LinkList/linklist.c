#include "linklist.h"


typedef struct node {
	void			*data;
	struct node		*next;
}NODE;

typedef struct linklist {
	NODE	head;
	int		size;
}LinkList;
//��ʼ������
void Init_LinkList(void **link)
{
	LinkList *tmp = (LinkList*)malloc(sizeof(LinkList));
	tmp->head.data = NULL;
	tmp->head.next = NULL;
	tmp->size = 0;
	(*link) = (void*)tmp;
	printf("init successful\n");
	printf("----------------------\n");
}
//��pos����
int InsertByPos_LinkList(void *link, int pos, void *data)
{
	//printf("pos = %d\n", pos);
	LinkList *mylink = (LinkList*)link;
	if (mylink == NULL || data == NULL)
		return -1;
	NODE *pcur = &(mylink->head);

	NODE *pnew = (NODE*)malloc(sizeof(NODE));
	pnew->data = data;
	pnew->next = NULL;
	
	for (int i = 0; i < pos; i++)
	{
		pcur = pcur->next;
	}
	pnew->next = pcur->next;
	pcur->next = pnew;
	return 0;
}
//��������
void Print_LinkList(void *link, void (*PRINT)(void *data))
{
	LinkList *mylink = (LinkList*)link;
	NODE *p = mylink->head.next;
	for (int i = 0; i < mylink->size; i++)
	{
		PRINT(p->data);
		p = p->next;
	}
}
//�ͷ�����
void Destroy_LinkList(void* link)
{
	LinkList *mylink = (LinkList *)link;
	NODE *p = mylink->head.next;
	NODE *tmp = p->next;
	for (int i = 0; i < mylink->size; i++)
	{
		free(p);
		p = tmp;
		tmp = p->next;
	}
	free(mylink);
}
//��posɾ��
int DeleteByPos(void *link, int pos)
{
	LinkList *mylink = (LinkList *)link;
	NODE *pcur = &(mylink->head);
	NODE *pre = mylink->head.next;
	if (mylink == NULL)
		return -1;
	if (pos < 0 || pos >= mylink->size)
		return -1;
	for (int i = 0; i < pos; i++)
	{
		pre = pcur;
		pcur = pcur->next;
	}
	pre->next = pcur->next;
	free(pcur);
	mylink->size--;
	return 0;
}
//�Ƚ�����ɾ��
int DeleteByData(void *link, void *data, int(*MYCOMPARE)(void *d1, void *d2)) {
	LinkList *mylink = (LinkList *)link;
	if (mylink == NULL || data == NULL)
		return -1;
	NODE *p = mylink->head.next;
	NODE *pre = &(mylink->head);
	for (int i = 0; i < mylink->size; i++)
	{
		if (MYCOMPARE(p->data, data))
		{
			pre->next = p->next;
			free(p);
			p = NULL;
			mylink->size--;
			return 0;
		}
		pre = p;
		p = p->next;
	}
	return -1;
}