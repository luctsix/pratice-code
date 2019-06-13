#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[100];
    FILE *file = fopen("99.txt", "w");

    if(!file)
    {
        perror("fopen err");
        return -1;
    }

    for(int i=1; i<=9; i++)
    {
        memset(str, 0, 100);
        for(int j=1; j<=i; j++)
        {
            sprintf(str,"%s  %d*%d=%2d", str, j, i, i*j);
        }
        sprintf(str,"%s\n", str);
        fputs(str, file);
        printf("%s", str);
    }

    fclose(file);

    return 0;
}