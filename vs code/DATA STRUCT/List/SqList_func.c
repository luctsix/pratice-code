#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

#define OVERFLOW -1
#define OK 1

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}SqList;


void InitList(SqList *L)
{
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem)
    {
        perror("malloc err");
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return;
}

void DestroyList(SqList *L)
{
    L->length = 0;
    free(L->elem);
    free(L);
}

int main(){

    SqList *L;   

    InitList(L);

    return 0;
}