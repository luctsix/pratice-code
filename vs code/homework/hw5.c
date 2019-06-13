#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
    char *name;
    int id;
    int name_len;
}Stu;

void Wfile()
{
    Stu s;
    s.id = 1;
    s.name_len = strlen("maker");
    s.name = (char*)malloc(s.name_len+1);
    strcpy(s.name, "maker");

    FILE *fp = fopen("hw5.txt", "wb");
    if(!fp)
    {
        perror("fopen err");
        return ;
    }
    fwrite(&s, sizeof(s), 1, fp);
    fputs(s.name, fp);

    free(s.name);
    fclose(fp);
}

void Rfile()
{
    Stu s;
    FILE *fp = fopen("hw5.txt", "rb");
    printf("testing...\n");
    if(!fp)
    {
        perror("fopen err");
        return;
    }
   
    int ret = fread(&s, 1, sizeof(s), fp);
    printf("ret = %d\n",ret);
    s.name =(char*)malloc(20);
    memset(s.name, 0 , 20);
    int ret2 = fread(s.name, 1, 100, fp);
    printf("ret2 = %d\n", ret2);

    printf("name = %s,age = %d, name_len = %d\n", s.name, s.id, s.name_len);

    free(s.name);
    fclose(fp);
}

int main()
{
    Wfile();
    printf("文件已写完\n");
    Rfile();
    return 0;
}