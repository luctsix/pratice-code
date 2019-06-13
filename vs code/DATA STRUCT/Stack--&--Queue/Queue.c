#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define OVERFLOW -1
#define OK 1

typedef struct{}QElemType;

/*-----单链队列-----队列的链式存储结构--------*/
typedef struct QNode{
    QElemType   data;
    struct QNode    *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
/*-----单链队列-----队列的链式存储结构--------*/

/*-----循环队列-----队列的顺序存储结构--------*/

#define QMAXSIZE 100
typedef struct{
    QElemType data;
    int front;      //不空指向头元素
    int rear;       //不空指向尾元素的下一个位置
}SqQueue;
/*-----循环队列-----队列的顺序存储结构--------*/


InitQueue(&Q)       //构造一个队列

DestroyQueue(&Q)    //销毁一个队列

ClearQueue(&Q)      //清空一个队列

QueueEmpty(Q)       //判空

QueueLength(Q)      //返回Q的元素个数，即队列的长度

GetHead(Q, &e)      //用e返回Q的队首元素

EnQueue(&Q, e)      //插入元素e为Q的新的队尾元素

DeQueue(&Q, &e)     //删除Q的队头元素，并用e返回其值

QueueTraverse(Q, visit())   //从队头到队尾，依次对Q的每个元素调用函数visit()
