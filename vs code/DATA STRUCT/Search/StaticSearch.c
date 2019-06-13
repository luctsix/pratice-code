#include<stdio.h>
#include<stdlib.h>

typedef struct{}ElemType;
typedef struct{}KeyType;
/*------------顺序表的查找-----------------*/
typedef struct{
    ElemType *elem;
    int length;
}SSTable;

int Search_Seq(SSTable ST, KeyType key)
{
    ST.elem[0].key = key;       //哨兵
    for(i = ST.length; !EQ(ST.elem[i].key, key); --i)；
    
    return i;
}
//平均查找长度  ASL

/*------------顺序表的查找-----------------*/

/*------------有序表的查找------------------*/
    //折半查找
int Search_Bin(SSTable ST, KeyType key)
{
    low = 1; high = ST.length;
    while(low<=high)
    {
        mid = (low + high)/ 2;
        if(EQ(ST.elem[mid].key, key))   return mid;
        else if(LT(key, ST.elem[mid].key))  high = mid -1;
        else    low = mid + 1;
    }
    return 0;
}

/*------------有序表的查找------------------*/

/*-----------------------------静态树表的查找-------------------------------*/
//次优查找树递归算法
void SecondOptimal(BiTree &T, ElemType R[], float sw[], int low, int high)
{
    i = low; min = abs(sw[high]-sw[low]);   dw = (sw[high]+sw[low-1]);
    for(j = low_1; j<high; j++)
        if(abs(dw - sw[j]-sw[j-1]) < min)
        {
            i = j;
            min = abs(dw - sw[j]-sw[j-1]);
        }
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = R[i];
        if(i == low)    T->lchild = NULL;
        else SecondOptimal(T->lchild, R, sw, low, i-1);
        if(i == high)   T->rchild = NULL;
        else SecondOptimal(T->rchild, R, sw, i+1, high);
}
/*------------------------------静态树表的查找------------------------------*/