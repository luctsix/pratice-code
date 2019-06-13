#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

#define MAX_ARRAY_DIM 8 //数组的最大维数

typedef struct{}ElemType;
/*-------------数组的顺序存储表示------------------------------*/
typedef struct{
    ElemType    *base;              //数组元素基址，由InitArray分配
    int         dim;                //数组维数
    int         bounds;             //数组维界基址，由InitArray分配
    int         constant;           // 数组映像函数常量地址，由InitArray分配
}Array;
/*-------------数组的顺序存储表示------------------------------*/

InitArray(&A, n, bound1,...boundn)  //若维数n和各维长度合法，则构造数组A

DestroyArray(&A)                    //销毁数组A

Value(A, &e, index1,...,indexn)     //若各下标不越界，则e赋值为所指定的A的元素值

Assign(&A, e, index1, ..., indexn)  //若下标不越界，则将e的值赋给所指定的A的元素