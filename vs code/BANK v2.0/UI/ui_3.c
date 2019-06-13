#include "../HEADERS/ui.h"
#include "../HEADERS/headers.h"

void selete_Card()        //登入成功后选择信用卡 or 储蓄卡进行操作
{
    system("cls");
    for(int i=0; i<=ROW; i++)
    {
        if(i==2)
        {
            printf("*       Please selete the card you want to operate          *");
        }
        else if(i == 4)
        {             
            printf("*                      1.DepositCard                        *");   
        }
        else if(i == 6)
        {            
            printf("*                      2.CreditCard                         *");
        }
        else if(i == 8)
        {            
            printf("*                      3.Exit                               *");
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
