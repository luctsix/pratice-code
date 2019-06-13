#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Init_DynamicArray(void **myarray, int n);
int DelByPos_DynamicArray(void *myarray, int pos);
int DelByData_DynamicArray(void *myarray, void *data, int(*MyCompare)(void*d1, void*d2));
int InsertByPos_DynamicArray(void *myarray, int pos, void *data);
int InsertByTail_DynamicArray(void *myarray, void *data);
int InsertByHeader_DynamicArray(void *myarray, void *data);
int Getsize_DynamicArray(void *myarray);
int GetCapacity_DynamicArray(void *myarray);
void Print_DynamicArray(void *array, void MyPrint(void *arg));
void Print_Person(void *arg);
void Destroy_DynamicArray(void *array);
int  MyCompare(void *d1, void*d2);
