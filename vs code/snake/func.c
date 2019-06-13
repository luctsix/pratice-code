#include "snake.h"

extern int count;

void hide_cur() //  隐藏光标
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

void init_wall()    //初始化游戏界面
{
    for(int i=0; i<= HIGH; i++)
    {
        for(int j=0; j<=WIDE; j++)
        {
            if(i==HIGH || j==WIDE)
            {
                printf("+");
            }
            else
            {
                printf(" ");
            }
        }
        if(i == 5)
        {
            printf("\tcreate in date: 2019-03-18");
        }
        if(i == 6)
        {
            printf("\tmade by LUCKY");
        }
        if(i == 7)
        {
            printf("\t上 : W");
        }
        if(i == 8)
        {
            printf("\t下 : S");
        }
        if(i == 9)
        {
            printf("\t左 : A");
        }
        if(i == 10)
        {
            printf("\t右 : D");
        }
        if(i == 12)
        {
            printf("\t关卡 : ");
        }
        if(i == 13)
        {
            printf("\t分数 : ");
        }
        printf("\n");
    }
}

void init_food(SNAKE *snake)        //生成食物坐标
{
    srand((unsigned int)time(NULL));
    
    snake->food.x = rand() % WIDE;
    snake->food.y = rand() % HIGH; 
}

void init_snake(SNAKE *snake)       //初始化蛇的信息
{
    snake->list[0].x = WIDE / 2;
    snake->list[0].y = HIGH / 2;

    snake->list[1].x = WIDE/2 - 1;
    snake->list[1].y = HIGH/2;

    snake->size = 2;
    snake->score = 0;

    init_food(snake);

    snake->dx = 1;
    snake->dy = 0;
}

void show_ui(SNAKE *snake)          //渲染游戏
{
    for(int i=0; i<snake->size; i++)
    {
        snake->coord.X = snake->list[i].x;
        snake->coord.Y = snake->list[i].y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
        if(i == 0)
        {
            printf("@");
        }
        else
        {
            printf("$");
        }
    }
    //生成食物
    snake->coord.X = snake->food.x;
    snake->coord.Y = snake->food.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
    printf("#");
    //将尾巴位置置为空
    snake->coord.X = snake->tail.x;
    snake->coord.Y = snake->tail.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
    printf(" ");
}

void control_snake(SNAKE *snake)    //控制蛇
{
    char key = 0;
    while(_kbhit())
    {
        key = _getch();
    }
    
    switch(key)
    {
        case 'w':
            snake->dx = 0;
            snake->dy = -1;
            break;
        case 's':
            snake->dx = 0;
            snake->dy = 1;
            break;
        case 'a':
            snake->dx = -1;
            snake->dy = 0;
            break;
        case 'd':
            snake->dx = 1;
            snake->dy = 0;
            break;
        default:
            break;
    }
}

void snake_move(SNAKE *snake)       //蛇移动后的位置信息更新
{
    snake->tail.x = snake->list[snake->size-1].x;
    snake->tail.y = snake->list[snake->size-1].y;

    for(int i=snake->size; i>0; i--)
    {
        snake->list[i] = snake->list[i-1];
    }
    snake->list[0].x += snake->dx;
    snake->list[0].y += snake->dy;
}

void snake_eat_food(SNAKE *snake)   //吃到食物
{
    if(snake->list[0].x == snake->food.x && snake->list[0].y == snake->food.y)
    {
        init_food(snake);
        snake->score += 10;
        snake->size++;
        count++;
        snake->coord.X = 70;
        snake->coord.Y = 13;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
        printf("%d", snake->score);
    }
}

void game_end(SNAKE *snake)     //游戏结束
{
    snake->coord.X = 25;
    snake->coord.Y = 25;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
    printf("Game over!\n");
    Sleep(3000);
    exit(1);
}

void snake_eat_body(SNAKE *snake)
{
    for(int i=1; i<snake->size; i++)
    {
        if(snake->list[0].x == snake->list[i].x && snake->list[0].y==snake->list[i].y)
        {
            game_end(snake);
        }
    }
}

void start_game(SNAKE *snake)
{
    int level = 400;
    int i = 0;
    while(snake->list[0].x>=0 && snake->list[0].x<60 &&
            snake->list[0].y>=0 && snake->list[0].y<20)
    {
        control_snake(snake);
        snake_move(snake);
        show_ui(snake);
        snake_eat_body(snake);
        snake_eat_food(snake);
        if(count == 5)
        {
            count = 0;
            level -=50;
            snake->coord.X = 70;
            snake->coord.Y = 12;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
            printf("%dms", level);
        }
        Sleep(level);
    }
    game_end(snake);
}