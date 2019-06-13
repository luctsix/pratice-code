#include<stdio.h>

typedef struct{}TElemType;

/*---------数的双亲存储表示-------------*/
#define MAX_TREE_SIZE 100
typedef struct PTNode{
    TElemType       data;
    int             parent;                 //双亲位置域
}PTNode;
typedef struct{                                 //树结构
    PTNode  nodes[MAX_TREE_SIZE];           //根的位置和结点数
    int     r, n;       
}PTree;
/*---------数的双亲存储表示-------------*/

/*---------数的孩子链表存储表示-------------*/
typedef struct CTNode{                       //孩子结点
    int             child;
    struct CTNode   *next;  
}*ChildPtr;
typedef struct{
    TElemType   data;
    ChildPtr    firstchild;                  //孩子链表头指针
}CTBox;
typedef struct{
    CTBox   nodes[MAX_TREE_SIZE];
    int     n, r;                            //结点数和根的位置
}CTree;
/*---------数的孩子链表存储表示-------------*/
