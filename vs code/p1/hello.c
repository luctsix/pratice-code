#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void func4()
{
    char arr[100];
    memset(arr, 0, sizeof(arr));

    char src[] = "你好";

    memcpy(arr, src, sizeof(src));
    memmove(arr, src, sizeof(src));
   // memcmp(src, arr);
}

void func1(int *p)
{               
    *p = 200;
}
func2(int *p)
{
    p = (int*)malloc(100*sizeof(int));
    *p = 20;
}

void func3()
{
    int *p;
    p = (int*)malloc(10*sizeof(int));
    int *tmp = p;
    if(!p)
    {
        printf("err\n");
        return ;
    }
    for(int i = 0; i < 10; i++)
    {
        *p = i+1;
        p++;
    }
    free(tmp);

    p = NULL;    
}

int main()
{
    //memset();

    int *p = NULL;
    func2(p);
    p =(int*)malloc(100*sizeof(p));

    func1(p);
    int i, k = 65;    
    for( i = 0; i < 26; i++)
    {
        *p = k;
        k++;
    }
    
    for(i=0; i<26; i++)
        printf("%c ", p[i]);

    free(p);
}