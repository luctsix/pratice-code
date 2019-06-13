#ifndef __SEQSTACK_H_
#define __SEQSTACK_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SEQSTACK_SIZE 1024
typedef void* SeqStack;


//初始化栈
SeqStack Init_seqstack();
//入栈
int  Push_SeqStack(SeqStack stack, SeqStack data);
//出栈
int  Pop_SeqStack(SeqStack stack);
//获取栈顶元素
SeqStack GetTop_SeqStack(SeqStack stack);
//判空
int  IsEmpty_SeqStack(SeqStack stack);
//获取栈的大小
int GetSize_SeqStack(SeqStack stack);
//释放
void Destroy_SeqStack(SeqStack stack);


#endif