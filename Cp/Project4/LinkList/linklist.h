#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ʼ������
void Init_LinkList(void **link);
//��pos����
int InsertByPos_LinkList(void *link, int pos, void *data);
//��������
void Print_LinkList(void *link, void(*PRINT)(void* data));
//�ͷ�����
void Destroy_LinkList(void* link);
//��posɾ��
int DeleteByPos(void *link, int pos);
//�Ƚ�����ɾ��
int DeleteByData(void *link, void *data, int(*MYCOMPARE)(void *d1, void *d2));