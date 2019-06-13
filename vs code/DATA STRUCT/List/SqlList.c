#include<stdio.h>
#include<stdlib.h>

#define OVERFOLOW -1
#define OK 1

typedef struct A{

}ElemType;

/*------------------线性表的动态分配顺序存储结构---顺序表------------------------*/
#define LIST_INIT_SIZE 100      //线性表存储空间的初始分配量
#define LISTINCREMENT 10        //线性表存储空间的分配增量
typedef struct {
    ElemType *elem;     //存储空间基址
    int length;         //当前长度
    int listsize;       //当前分配的存储量，以sizeof(ElemType)为单位
}SqList;

Status InitList_Sq(SqList &L){
    //构造一个空的线性表L
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem) exit(OVERFOLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}   

/*------------------线性表的动态分配顺序存储结构---顺序表------------------------*/


int InitList(SqList L)   //构造一个空的线性表L
{
    L.elem = (SqList*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) exit(OVERFOLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;  
}

DestroyList(&L) //销毁L

ClearList(&L)   //将线性表置为空表

ListEmpty(L)       //判空，空为true

ListLength(L)       //返回L中的元素个数

GetElem(L, i, &e)   //用e返回L中的第i个元素

LocateElem(L, e, compare() )    //返回L中第一个与e满足compare()关系的数据元素的位序。不存在则return 0.

PrioElem(L, cur_e, &pre_e)  //若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义

NextElem(L, cur_e, &next_e) //若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义若

ListInsert(&L, i, e)    //在L中第i个位置之前插入新的元素e，长度加1

ListDelete(&L, i, &e)   //delete L中的第i个元素，并用e返回其值，长度减1

ListTraverse(L, visit() )   //依次对L中的每个元素调用visit()，一旦调用失败，则操作失败

int main()
{


    return 0;
}