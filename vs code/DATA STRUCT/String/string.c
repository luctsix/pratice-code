#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*-------------串的定长顺序存储表示---------------*/
#define MAXSTRING 255
typedef unsigned char  SString[MAXSTRING+1]

/*-------------串的定长顺序存储表示---------------*/

/*-------------串的堆分配存储表示---------------*/
typedef struct{
    char  *ch;      //若为空串，则按串长分配存储区，否则ch为NULL
    int length;
}HString;
/*-------------串的堆分配存储表示---------------*/

/*-------------串的块链存储表示---------------*/
#define CHUNKSIZE 80    //用户自定义的块大小
typedef struct Chunk{
    char    ch[CHUNKSIZE];
    int     curlen;
}Chunk;
typedef struct{
    Chunk *head, *tail; //串的头和尾指针
    int    curlen;      //串的当前长度
}LString;
/*-------------串的块链存储表示---------------*/


StrAssign(&T, chars)    //生成一个其值等于chars的串T

StrCopy(&T, S)          //由串S复制得T

StrEmpty(S)             //判空，空为true

StrCompare(S，T)        //若S>T, 返回值大于0； 相等则返回值等于0；S<T，返回值小于0

StrLength(S)            //返回S中的元素个数，即串长

ClearString(S)          //清空

Concat(&T, S1, S2)      //用串返回S1和S2连接而成的串

SubString(&Sub, S, pos, len)    //用sub返回s的第pos起的长度为len子串

Index(S, T, pos)        //若主串S存在和串T相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则return 0

Replace(&S, T, V)       //用V代替主串S中出现的所有与T相等的不重叠的子串

StrInsert(&S, pos, T)   //在串S的第pos个字符之前插入串T

StrDelete(&S, pos, len) //从主串S中第pos个字符起长度为len的字符

DestroyString(&S)       //销毁S
