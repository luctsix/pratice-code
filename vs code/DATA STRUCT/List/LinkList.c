#include<stdio.h>
#include<stdlib.h>

#define OVERFOLOW -1
#define OK 1
#define Status void

typedef struct A{

}ElemType;

/*----------------- 线性表的链存储结构----链表----------------------------------*/
typedef struct LNode{       //单链表
    ElemType data;  
    struct LNode *next;
}LNode, *LinkList, *Link;

#define MAXSIZE 100         //静态链表  SLink List S
typedef struct {            
    ElemType data;      //S[i].data     S[i].cur
    int cur;
}component, SLinkList[MAXSIZE];

typedef struct DuLNode{     //双向循环链表
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

//定义一个带头节点的线性表类型
typedef struct{
    LNode head, tail;
    int len;
}LiskList;

/*----------------- 线性表的链存储结构----链表----------------------------------*/

Status InitList(LinkList &L);    //构造一个空的线性链表L

Status DetroyList(LinkList &L);     //销毁L

Status ClearList(LinkList &L);      //置空

Status InsFirst(Link h, Link s);     //已知h指向头结点，将s所指结点插入在第一个结点之前

Status DelDirst(Link h, Link &q);      //h指向头结点，删除链表第一个结点并以q返回

Status Append(LinkList &L, Link s); //将指针所指的一串结点链接在L的最后一个结点之后，并改变L的尾指针指向新的尾结点

Status Remove(LinkList &L, Link q); //删除L中的尾结点并以q返回，改变尾指针指向新的尾结点

Status InsBefore(LinkList &L, Link &p, Link s); //已知p指向L中的一个结点，将s所指结点插入到p所指结点之前

Status InsAfter(LinkList &L, Link &p, Link &s); //已知p指向L中的一个结点，将s所指结点插入到p所指结点之后

Status SetCurElem(Link &p, ElemType e); //用e更新p所指结点的值

ElemType GetCurElem(Link p); //返回p所指结点数据元素中的值

Status ListEmpty(LinkList L);   //判空

int ListLength(LinkList L); //返回元素个数

Position GetHead(LinkList L);   //返回头结点位置

Position GetLast(LinkList L);   //返回尾结点位置

Position PriorpPos(LinkList L, Link p); //返回p所指结点的直接前驱的位置

Position NextPos(LinkList L, Link p);   //返回p所指结点的直接后继的位置

Status LocateElem(LinkList L, int i, Link &p);//返回p指示L中第i个结点的位置并返回OK，i不合法返回ERROR

Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
    //返回L中第一个与e满足compare()关系的元素的位置，不存在返回NULL

Status ListTraverse(LinkList L, Status (*visit())); //依次对L的每个元素调用visit()
