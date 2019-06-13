//动态数组
#include<iostream>
#include<string>
#include "MyArray.h"

using namespace std;

MyArray::MyArray(){
	this->capacity = 100;
	this->size 	 = 0;
	this->data     = (int*)malloc(capacity*sizeof(int));
}
MyArray::MyArray(const MyArray &r)
{
	this->capacity = r.capacity;
	this->size = r.size;
	this->data = new int[r.capacity];
	memcpy(this->data, r.data, r.capacity*sizeof(int));
}
MyArray::MyArray(int capacity){
	this->capacity = capacity;
	this->size     = 0;
	this->data     = (int*)malloc(capacity*sizeof(int));
}	
int setData(int pos, int val){
	this->data[pos] = val;
}
void MyArray::Insert(int pos, int val)//按位置插入
{
	if(this->size>=capacity)
		return;
	for(int i=size-1; i>=pos; i--)
	{
		this->data[i+1] = this->data[i];
	}
	this->data[pos] = val;
	this->size++;
}
int MyArray::getData(int pos)//获取pos位置的数据
{
	return this->data[pos];
}
void MyArray::Pushback(int val)//尾插
{
	Insert(this->size, val);;
}
int MyArray::getCapacity(){
	return this->capacity;
}
int MyArray::getSize(){
	return this->size;
}
MyArray::~MyArray(){
	delete[]this->data;
}
void MyArray::Print(){
	for(int i=0; i<this->size; i++)
	{
		cout<<this->data[i]<<" ";
	}
	cout<<endl;
}
void MyArray::deleteData_pos(int pos){
	if(this->size==0)
		return;
	for(int i=pos; i<this->size-1; i++)
	{
		this->data[i] = this->data[i+1];
	}
	this->size--;
}
void MyArray::deleteData_val(int val){
	if(this->size == 0)
		return;
	for(int i=0; i<this->size; i++)
	{
		if(this->data[i] == val)
		{
			for( ;i<this->size-1; i++)
			{
				this->data[i] = this->data[i+1];
			}
			this->size--;
			return;
		}
	}
	cout<<"have not found this val"<<endl;
}
void  MyArray::sort(){
	int j;
	for(int i=1; i<this->size; i++)
	{
		int tmp = this->data[i];
		for(j=i-1; j>=0; j--)
		{
			if(tmp<this->data[j])
			{
				this->data[j+1] = this->data[j];
			}
		}
		this->data[j+1] = tmp;
	}
}