#include<stdio.h>
#include<stdlib.h>
typedef void Status;
 
/*-------------二叉树的顺序存储存储表示---------------------*/
typedef struct{} TElemType;

#define MAX_TREE_SIZE 100       //二叉树的最大根节点
typedef TElemType sqBiTree[MAX_TREE_SIZE];  //0号单元存储根节点
SqBiTree bt;

/*-------------二叉树的顺序存储存储表示---------------------*/

/*-------------二叉树的二叉链表存储表示---------------------*/
typedef struct BiTNode{
    TElemType       data;
    struct BiTNode  *lchild, *rchild;   //左右孩子的指针
}BiTNode, *BiTree;

/*-------------二叉树的二叉链表存储表示---------------------*/

/*-------------二叉树的二叉线索存储表示---------------------*/
typedef enum PointerTag{Link, Thread};   //Link == 0指针, Tread == 1 线索
typedef struct BiThrNode{
    TElemType           data;
    struct BiThrNode    *lchild, *rchild;
    PointerTag          LTag, RTag;;    //左右标志
}BiThrNode, *BiThrTree;
//以双向线索链表为存储结构时对二叉树进行遍历的算法
Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType))
{
    BiThrNode *p = T->lchild;   //p指向根结点
    while(p!=T){                //空树或者遍历结束时， p==T
        while(p->LTag == Link)  p = p->lchild;
        if(!Visit(p->data))     return ERROR;       //访问其左子树为空的结点
        while(p->RTag == Thread && p->rchild!=T)
        {
            p =p->rchild;
            Visit(p->data);     //访问后继结点
        }
        p = p->rchild;
    }
    return OK;
}
//中序遍历建立中序线索化链表
void InTreading(BiThrTree p){
    if(p){
        InTreading(p->lchild);  //左子树线索化
        if(!p->lchild)  {p->LTag = Thread; p->lchild = pre;}    //前驱线索
        if(!pre->rchild){pre->RTag = Thread; pre->rchild = p;}  //后继线索
        pre = p;        //保持pre指向p的前驱
        InThreading(p->rchild); //右子树线索化
    }
}
Status InOrderThreading(BiThrTree &  ThrT, BiThrTree T)
{
    if(!(ThrT = (BiThrNode *)malloc(sizeof(BiThrNode)))     exit(OVERFLOW);
    Thrt->LTag = Link;  Thrt->RTag = Thread;        //头结点
    ThrT->rchild = ThrT;             //右指针回指
    if(!T)  ThrT->lchild = ThrT;     //若二叉树为空，左指针回指
    else{
        ThrT->lchild = T; pre = ThrT;
        InThreading(T);     //中序遍历进行中序线索化
        pre->rchild = ThrT; pre->RTag = Thread;
        ThrT->rchild = pre;
    }
    return OK;
}

/*-------------二叉树的二叉线索存储表示---------------------*/

/*-------------先序遍历递归算法---------------------*/
Status PreOrderTraverse(BiTree T, Status(* Visit)(TElemType e))
{
    if(T)
    {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild), Visit)
                if(PreOrderTraverse(T->rchild),Visit)   return OK;
        Return ERROR;
    }else   return OK;
}

/*-------------先序遍历建立二叉树的二叉链表---------------------*/
Status CreateBiTree(BiTree &T)
{
    scanf(&ch);
    if(ch == ' ')  T = NULL;
    else{
        if(!(T = (BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
        T-data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

/*-------------中序遍历非递归算法---------------------*/
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    BiTree p;
    InitStack(S); 
    Push(S,T);      //根节点入栈
    while(!StackEmpty(S)){
        while(GetTop(S,p) && p) Push(S, p->lchild); //向左走到尽头
        Pop(S, p);
        if(!StackEmpty(S))
        {
            Pop(S,p);
            if(!Visit(p->data)) return ERROR;
            Push(S,p->rchild);
        }
    }
}

Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    InitStack(S);
    p = T;
    while(p || !StackEmpty(S))
    {
        if(p)       //根指针进栈，遍历左子树
        {
            Push(S, p);
            p = p->lchild;
        }
        else{       //根指针退栈，访问根节点，遍历右子树
            Pop(S,p);
            if(!Visit(p->data)) return ERROR;
            p = p->rchild;
        }
    }
    return OK;
}

