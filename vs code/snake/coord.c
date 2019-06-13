#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

#define ROW 10
#define LINE 60

void hide_cur()
{
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void show_cur()
{
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Print()
{
    system("cls");
    for(int i=0; i<=ROW; i++)
    {
        if(i==3)
        {
            printf("*          Please enter your Account and Password           *");
        }
        else if(i == 5)
        {
             printf("*                   Account:_ _ _ _ _ _                     *");

        }
        else if(i == 7)
        {
            printf("*                  Password:_ _ _ _ _ _                     *");

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

int main()
{
    COORD coord;
    Print();
    //hide_cur();
    show_cur();

    coord.X = 28;
    coord.Y = 5;
    while(coord.X != 40)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch;
        ch = _getch();
        putc(ch,stdout);
        //getchar();
        coord.X += 2;
    }
    coord.X = 28;
    coord.Y = 7;
    while(coord.X != 40)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch;
        ch = _getch();
        putc('*',stdout);
        //getchar();
        coord.X += 2;
    }
    

    //system("pause");
    char ch;
    scanf("%c", &ch);
    _getch();
    _getch();
    
    return 0;
}