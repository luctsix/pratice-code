#include "../HEADERS/headers.h"
//#include "../HEADERS/operation.h"

void Record(PerInfo *p)         //将注册信息存入文件
{
    FILE *file = NULL;
    file = fopen("./FILES/user.txt", "rb+");
    if(!file)
    {
        perror("user.txt fopen err");
        return;
    }
    fseek(file, 0, SEEK_SET);
    // printf("testing.....\n");
    PerInfo p1;
    int i;
    while(1)
    {
        // printf("testing2.....\n");
        int ret = fread(&p1, 1, sizeof(PerInfo), file);
        //printf("p1.name = %s\n", p1.name);
        if(feof(file))
        {
            // printf("testing3.....\n");
            i = 0;
            break;
        }
        //printf("p1.name = %d\n", (bool)(p1.name));
        if(strlen(p1.name) == 0)
        {
            printf("testing4.....\n");
            i = 1;
            break;
        }
    }
    // printf("testing5.....\n");
    if(i == 1)
       fseek(file, -sizeof(PerInfo), SEEK_CUR);

    fwrite(p, 1, sizeof(PerInfo), file);
    // printf("testing6.....\n");
    fclose(file);
}

void fRead(PerInfo *p)          //从文件中读取注册信息
{
    FILE *file = fopen("./FILES/user.txt", "rb");
    if(!file)
    {
        perror("user.txt fopen err");
        return;
    }
    while(1)
    {
        fread(p, 1, sizeof(PerInfo), file);
        if(feof(file))
        {
            break;
        }
    }
    fclose(file);
}

void del_Account(char *p)       //删除文件中的账号信息
{
    PerInfo p2;
    FILE *file = fopen("./FILES/user.txt", "rb+");
    if(!file)
    {
        perror("user.txt fopen err");
        return;
    }
    while(1)
    {
        fread(&p2, 1, sizeof(p2), file);
        if(strcmp(p2.name, p)==0)
        {
            break;
        }
        if(feof(file))
        {
            perror("No this User!");
            return;
        }
    }
    fseek(file, -sizeof(PerInfo), SEEK_CUR);
    memset(&p2, 0, sizeof(PerInfo));
    fwrite(&p2, sizeof(PerInfo), 1, file);

    fclose(file);

}
