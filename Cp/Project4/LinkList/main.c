#define _CRT_SECURE_NO_WARNINGS

#include "linklist.h"

typedef struct person
{
	char name[128];
	int age;

}PERSON;

void Print_Person(void *arg)
{
	PERSON *p = (PERSON *)arg;
	printf("%s %d\n", p->name, p->age);
}
int  MyCompare(void *d1, void*d2)
{
	PERSON *p1 = (PERSON*)d1;
	PERSON *p2 = (PERSON*)d2;
	return  (strcmp(p1->name, p2->name) == 0) && (p2->age == p1->age);
}
int main()
{
	PERSON p1 = { "阿卡丽",20 };
	PERSON p2 = { "亚索",40 };
	PERSON p3 = { "EZ",18 };
	PERSON p4 = { "琴女",28 };
	PERSON p5 = { "TIMO",3 };

	void *linklist = NULL;


	//初始化链表
	Init_LinkList(&linklist);
	//按pos插入
	InsertByPos_LinkList(linklist, 0, &p1);	
	InsertByPos_LinkList(linklist, 0, &p2);
	InsertByPos_LinkList(linklist, 0, &p3);
	InsertByPos_LinkList(linklist, 2, &p4);
	InsertByPos_LinkList(linklist, 3, &p5);
	//遍历链表
	Print_LinkList(linklist, Print_Person);

	//DeleteByPos(linklist, 0);
	//DeleteByPos(linklist, 0);

	//DeleteByData(linklist, &p2, MyCompare);

	//Print_LinkList(linklist, Print_Person);

	//释放链表
	//Destroy_LinkList(linklist);


	system("pause");
	return 0;
}