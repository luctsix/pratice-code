#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *file;

    file = fopen("test1.txt", "w+");
 
    if(!file)
    {
        perror("open err!\n");
        return -1;
    }

    // fputc(1, file);
    // fseek(file, 0, SEEK_SET);

    char ch = fgetc(file);
    printf("ch = %d\n", ch);

    if(feof(file)){     //文件的结尾和纯文本最后的-1
        printf("i am here\n");
        fclose(file);
        return -1;        
    }

    fputs("hello, world\n", file);
    fputc('a'   ,file);
    fputc('c', file);
    printf("%p\n", file);
    printf("%d\n", *file);  //打印出来是什么

    fclose(file);

    return 0;
}