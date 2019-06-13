#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define OVERFLOW -1
#define OK 1

typedef struct{}SElemType;

/*----------顺序栈的定义---------------*/
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S)
{
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S)  exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
/*----------顺序栈的定义---------------*/

InitStack(&S)       //构造一个空栈

DestroyStack(&S)    //销毁S

ClearStack(&S)      //清空S

StackEmpty(S)       //判空

StackLength(S)      //返回栈的元素个数，即栈的长度

GetTop(S, &e)       //用e返回栈顶元素

Push(&S, e)        //插入元素e为新的栈顶元素，入栈

Pop(&S, &e)         //删除栈顶元素，用e返回其值

StackTraverse(S, visit());  //从栈底到栈顶依次对S的每个元素调用visit()