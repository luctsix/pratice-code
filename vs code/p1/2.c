#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i = 10;

void func(int **x1, int **y1);

void func(int **p1, int **p2)
{
    int *tmp1 = (int*)malloc(sizeof(int));
    int *tmp2 = (int*)malloc(sizeof(int));

    printf("tmp1 = %p\ntmp2 = %p\n", tmp1, tmp2);
    int n, m;
     scanf("%d %d", &n, &m);

    *tmp1 = n;
    *tmp2 = m;

    *p1 = tmp1;
    *p2 = tmp2;
}

int main()
{
    int *p1 = NULL;
    int *p2 = NULL;

    printf("i = %d\n", i);
    func(&p1, &p2);
    
    for(int i=0;i<5;i++)
        printf("思心%d\n",i);

    printf("p1 = %d\np2 = %d\n", *p1, *p2);

    return 0;
}