#include "../HEADERS/ui.h"
#include "../HEADERS/headers.h"

void Dep_Menu_UI()      //登录成功后储蓄卡的操作界面
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
            printf("*       1.CardInfo       2.Deposit          3.Withdraw      *");
        }
        else if(i == 6)
        {            
            printf("*       4.Modifypasswd   5.DetroyAccount    6.Payout        *");
        }
        else if(i == 8)
        {            
            printf("*       7.TransferAccount                   8.Logout        *");
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
    _getch();
}

void Cred_Menu_UI()     //登录成功后信用卡的操作界面
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
            printf("*          1.CardInfo        2.Loan         3.Repay         *");
        }
        else if(i == 6)
        {            
            printf("*          4.Modifypasswd         5.DetroyAccount           *");
        }
        else if(i == 8)
        {            
            printf("*          6.Payout               7.Logout                   *");
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
    _getch();
}
