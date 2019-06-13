#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_key_value(char *src_key, char *src_value)
{
    FILE* fd = fopen("cfg.ini", "r");
    if(!fd)
    {
        perror("fopen:");
        return ;
    }
    while(1)
    {
        char tmp[128] = " ";
       
        char *ret = fgets(tmp, sizeof(tmp), fd);
        char key[32] = " ";
        char value[64] = " ";
        if(ret == NULL)
        {
            break;
        }
        sscanf(tmp, "%[^ =]", key);
        sscanf(tmp, "%*[^=]=%*[ ]%s", value);
        //printf("key = %s\tvalue = %s\n", key, value);

        if(strcmp(src_key, key)==0)
        {
           strcpy(src_value, value);
           return ;
        }
    }
    printf("没有这个键值对\n");

    return ;
}