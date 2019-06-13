#include "seqstack.h"

typedef struct seqstack{
    SeqStack array[SEQSTACK_SIZE];
    int      size;
}SEQSTACK;
//初始化栈
SeqStack Init_seqstack(){
    SEQSTACK *stack = NULL;
    stack = (SEQSTACK*)malloc(sizeof(SEQSTACK));
    memset(stack->array, 0x00, sizeof(stack->array));
    //stack->array[0] = NULL;
    stack->size  = 0;

    return (SeqStack)stack;
}
//入栈
int  Push_SeqStack(SeqStack stack, SeqStack data){
    SEQSTACK *mystack = (SEQSTACK*)stack;
    if(mystack->size >= SEQSTACK_SIZE)
        return -1;
    mystack->size++;
    mystack->array[mystack->size-1] = data;
    return 0;
}
//出栈
int  Pop_SeqStack(SeqStack stack){
    SEQSTACK *mystack = (SEQSTACK*)stack;
    if(mystack->size == 0)
        return -1;
    //data = mystack->array[mystack->size-1];
    mystack->size--;
    return 0;
}
//获取栈顶元素
SeqStack GetTop_SeqStack(SeqStack stack){
    SeqStack data = NULL;
    SEQSTACK *mystack = (SEQSTACK*)stack;
    if(mystack->size == 0)
        return NULL;
    data = mystack->array[mystack->size-1];
    return data;
}
//判空
int  IsEmpty_SeqStack(SeqStack stack){
    SEQSTACK *mystack = (SEQSTACK*)stack;
    if(mystack->size == 0)
        return 1;
    else
    {
        return 0;
    }
    
}
//获取栈的大小
int GetSize_SeqStack(SeqStack stack){
    SEQSTACK *mystack = (SEQSTACK*)stack;
    if(mystack->size == 0)
        return -1;
    return mystack->size;
}
//释放
void Destroy_SeqStack(SeqStack stack){
    SEQSTACK *mystack = (SEQSTACK*)stack;
    if(mystack == NULL)
        return;
    free(mystack);
    mystack = NULL;
}