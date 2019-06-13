#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("输入的参数个数不正确！");
        return -1;
    }
    char *src = argv[1];
    char *dst = argv[2];

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    fp1 = fopen(src, "rb");
    if(NULL == fp1)
    {
        perror("fp1 fopen err");
        return -1;
    }

    fp2 = fopen(dst, "wb");
    if(!fp2)
    {
        perror("fp2 fopen err");
        return -1;
    }

    char ch;
    while(1)
    {
        ch = fgetc(fp1);
        if(feof(fp1))
        {
            return -1;
        }
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    printf("文件复制成功！");




    return 0;
}