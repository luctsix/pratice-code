#ifndef _HEADERS_H_
#define _HEADERS_H_

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<windows.h>

#define SUCCESS 0
#define N 32
#define M 10
#define ROW 10
#define LINE 60

enum CardType{CARD, CREDITCARD};
enum MarrigeState{YES, NO};

typedef struct Bank{        
    
}Bank, *bank;

typedef struct Card{        //银行卡的信息结构
    char account[N];
    char usr_name[N];
    char usr_pwd[N];
    double banlance;
}Card;

typedef struct PersonalInformation{     //个人信息结构
    char name[M];
    char age[M];
    char idnum[N];
    char addr[N];
    char ismarry;
    char tel[N];
    char code[M];
    char birthday[M];
    Card card;
}PerInfo, *perinfo;

/*----------------------------------------------------------*/
void show_cur();     //显示光标
void hide_cur();     //隐藏光标
void Del_char(short *x, short *y);     //删除输入错误的字符

/*----------------------------------------------------------*/

void hide_cur()     //隐藏光标
{
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void show_cur()     //显示光标
{
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Del_char(short *x, short *y)     //删除输入错误的字符
{
    //printf("i am here\n");
    //printf("x = %d; y = %d\n", coord.X, coord.Y);
    COORD coord;
    *x -= 2;
    coord.X = *x;
    coord.Y = *y;
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putc('_', stdout); 
    //coord.X = *x -2;
    coord.Y = *y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    *x -= 2;
}



#endif