#include "snake.h"
#include "func.c"


int main()
{
    system("cls");
    hide_cur();
    //show_cur();
    init_wall();    //初始化游戏界面
    SNAKE *snake = (SNAKE*)malloc(sizeof(SNAKE)); 

    init_snake(snake);
    show_ui(snake);
    
    start_game(snake);
    //_getch();
    //system("pause");
    //system("cls");
    return 0;
}