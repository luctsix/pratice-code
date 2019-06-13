#include "..\HEADERS\headers.h"

#define NUM 100

bool LoginVerify(char *account, char *pwd)
{
    // printf("account:%s\n", account);
    // printf("pwd:%s\n", pwd);
    // _getch();
    
    FILE *fap = fopen("./FILES/user.txt", "rb");
    if(!fap)
    {
        perror("fap fopen err");
        return FALSE;
    }

    PerInfo p;
    memset(&p, 0, sizeof(PerInfo));

    fseek(fap, 0, SEEK_SET);
    while(1)
    {        
        fread(&p, 1, sizeof(PerInfo), fap);
        if(strcmp(account, p.card.usr_name)==0 
                    && strcmp(pwd, p.card.usr_pwd)==0 )
        {
            fclose(fap);
            return TRUE;
        }
        if(feof(fap))
        {
            break;
        }
    }

    fclose(fap);
    return FALSE;
}