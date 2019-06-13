#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


void write_key_value(char *dst_key, char *dst_value)
{
    int flag = 0;

    FILE* fd = fopen("cfg.ini", "r");
    if(!fd)
    {
        perror("fopen:");
        return;
    }

    struct stat s;
    stat("cfg.ini", &s);

    char buf[s.st_size+128];
    memset(buf, 0, s.st_size+128);


    while(1)
    {
        char tmp[128] = " ";
        char * ret = fgets(tmp, sizeof(tmp), fd);
        
        
        if(ret == NULL)
        {
            break;
        }
        char tmp_key[32] = " ";
        sscanf(tmp, "%[^ =]", tmp_key);

        if(strcmp(tmp_key, dst_key)==0)
        {
            char p[128] = " ";
             sprintf(p, "%s = %s\n", dst_key, dst_value);
             strcat(buf, p);
             flag = 1;
        }
        else
        {
            strcat(buf, tmp);
        }
    }
    printf("flag = %d\n", flag);
    if(flag == 0)
    {
        char p[128] = " ";
        sprintf(p, "%s = %s\n", dst_key, dst_value);
        strcat(buf, p);
    }
    printf("%s", buf);
    fclose(fd);

    fd = fopen("cfg.ini", "w");
    if(!fd)
    {
        perror("fopen:");
        return;
    }
    fputs(buf, fd);
    fclose(fd);
}