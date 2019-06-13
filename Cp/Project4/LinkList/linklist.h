#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//初始化链表
void Init_LinkList(void **link);
//按pos插入
int InsertByPos_LinkList(void *link, int pos, void *data);
//遍历链表
void Print_LinkList(void *link, void(*PRINT)(void* data));
//释放链表
void Destroy_LinkList(void* link);
//按pos删除
int DeleteByPos(void *link, int pos);
//比较数据删除
int DeleteByData(void *link, void *data, int(*MYCOMPARE)(void *d1, void *d2));