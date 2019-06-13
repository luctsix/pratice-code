#define _CRT_SECURE_NO_WARNINGS

#include "linklist.h"
//维护动态数组的结构体

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

	void *array = NULL;
	Init_DynamicArray(&array, 10);
	//插入
	InsertByPos_DynamicArray(array, 0, &p1);
	InsertByPos_DynamicArray(array, 0, &p2);
	InsertByPos_DynamicArray(array, 0, &p3);
	InsertByPos_DynamicArray(array, 2, &p4);
	InsertByPos_DynamicArray(array, 3, &p5);
	//EZ 亚索 琴女 TIMO  阿卡丽 
	Print_DynamicArray(array, Print_Person);
	//DelByPos_DynamicArray(array, 3);
	DelByData_DynamicArray(array, &p2, MyCompare);
	Print_DynamicArray(array, Print_Person);
	Destroy_DynamicArray(array);

	system("pause");
	return 0;
}
