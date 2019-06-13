#include "../HEADERS/ui.h"
#include "../HEADERS/headers.h"
#include "ui_2.c"

void init_UI_1()        //欢迎界面
{
    system("cls");
    for(int i=0; i<=ROW; i++)
    {
        if(i==3)
        {
            printf("*              Welcome To Lucky's Bank System               *");
        }
        else if(i == 6)
        {            
            printf("*                press to enter the system                  *");
        }
        else
        {
            for(int j=0; j<=LINE; j++)
            {
                if(i==0 || i==ROW || j==0 || j==LINE)
                {
                    printf("*");
                } 
            
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void init_UI_2()        //选择 登录、创建账号或者退出 的界面
{
    system("cls");
    for(int i=0; i<=ROW; i++)
    {
        if(i==2)
        {
            printf("*            Please selete the business you want            *");
        }
        else if(i == 4)
        {             
            printf("*                        1.Lodin                            *");
            
            
        }
        else if(i == 6)
        {            
            printf("*                        2.Create Account                   *");
        }
        else if(i == 8)
        {            
            printf("*                        3.exit                             *");
        }
        else
        {
            for(int j=0; j<=LINE; j++)
            {
                if(i==0 || i==ROW || j==0 || j==LINE)
                {
                    printf("*");
                } 
            
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void show_ui()
{
    hide_cur();
    init_UI_1();
    _getch();
    
    init_UI_2();   
}

