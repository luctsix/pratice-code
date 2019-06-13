#include<stdio.h>

typedef float   fKeyType;//实型
typedef int     iKeyType;//整型
typedef char    *cKeyType;//字符串型

typedef struct{
    cKeyType    key;    //关键字
}SElemType;

#define EQ(a,b)     ((a)==(b))
#define LT(a,b)     ((a) <(b))
#define LQ(a,b)     ((a)<=(b))

// #define EQ(a,b)     (!strcmp((a),(b)))
// #define LT(a,b)     (strcmp((a),(b))<0)
// #define LQ(a,b)     (strcmp((a),(b))<=0)