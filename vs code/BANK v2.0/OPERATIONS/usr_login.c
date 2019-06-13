#include "..\HEADERS\headers.h"

void Login(char *usr_name, char *usr_pwd)        
{
    COORD coord;             //控制光标的变量
    
    show_cur();             //显示光标
    int i = 0;
    int j = 0;

    coord.X = 27;           //设置光标位置
    coord.Y = 5;
    while(coord.X != 39)    
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   //设置光标位置到(28,5)
        char ch;
        ch = _getch();      //获取键盘输入
        if(ch == 13)        //如果按Enter键则结束输入
        {
            break;
        }
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 27)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
        }
        if(ch == 27)        //按Esc键退出程序
        {
            exit(0);
        }
        putc(ch,stdout);    //将输入的字符打印到屏幕上
        usr_name[i++] = ch;
        //getchar();
        coord.X += 2;
    }
    coord.X = 27;
    coord.Y = 7;
    while(coord.X != 39)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch;
        ch = _getch();

        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 27)
            {
                Del_char(&coord.X, &coord.Y);
                j--;
                coord.X += 2;
                continue;
            }
        }
        if(ch == 13)        //按Enter键停止输入
        {
            break;
        }
        if(ch == 27)        //按Esc键退出程序
        {
            exit(0);
        }
        putc('*',stdout);
        usr_pwd[j++] = ch;
        //getchar();
        coord.X += 2;
    }
    // coord.X = 0;
    // coord.Y = 13;
    // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    // printf("name = %s\n", usr_name);
    // printf("pwd = %s\n",usr_pwd);
    //_getch();
}