
#include <stdlib.h>
//#include <string.h>

#include "menu.h"
#include "menu.c"
#include "read.h"
#include "read.c"
#include "write.h"
#include "write.c"

void test()
{
    system("cls");
    while(1)
    {
        menu();
        int ch;
        scanf("%d", &ch);
        getchar();

        switch(ch)
        {
            case 1:
                {printf("请输入要读取的key:");
                char key[16]    = " ";
                char value[16]  = " ";
                fgets(key, sizeof(key), stdin);
                key[strlen(key)-1] = 0;
                //printf("key = %s\n", key);
                get_key_value(key, value);
                printf("%s = %s\n", key, value);
                break;}
            case 2:
                {char wkey[32]    = " ";
                char wvalue[64]  = " ";

                printf("请输入你要写入的key:");
                gets(wkey);

                printf("请输入你要写入的value:");
                gets(wvalue);
                write_key_value(wkey, wvalue);
                break;}
            case 3:
                system("cls");
                break;
            case 4:
                return;
                break;
            default:
                break;
        }
    }
}