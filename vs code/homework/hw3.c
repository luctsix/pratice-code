#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
void tranverse(char *p, int n)
{
    int i = 0;
    if(n<10)
        *p = n + '0';
    else{
        while(n != 0)
        {
            int t = n / 10;
            p[i++] = t + '0';
            n = n % 10;
        }
        p[i] = '\0';
    }
   
}
*/

int main()
{
    srand((unsigned int)time(NULL));

    FILE *file = fopen("HW3.txt", "w");
    if(!file)
    {
        perror("fopen err");
        return -1;
    }

    for(int i=0; i<500; i++)
    {
       
        int t = rand() % 100;
        char str[10] = {0};
        sprintf(str, "%d", t);
        //tranverse(str, t);

        fputs(str, file);
        fputc('\n', file);
    }

    fclose(file);

    return 0;
}