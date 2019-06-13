#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

#define N 500
#define X 20

int main()
{
   // Sleep(300);
   // static_cast<int> 
    system("cls");
    int i, j ,k;
    for(i=1; i<=N; i++)
    {
        for(k=1; k<=i; k++)
            printf(" ");
        printf("*\n");
        Sleep(100);
    }
    for(i = 0; i<=N+1; i++){
        printf("*");
         Sleep(100);
    }
    for(i=N;i>=1;i--)
    {
        for(k = 1;k<=i; k++)
            printf(" ");
        printf("*\n ");
         Sleep(100);
    }


    return 0;
}


//泛型编程
//typora