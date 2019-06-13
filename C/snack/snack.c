#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define WIDE 60
#define HIGH 20

void hide_cur()
{
	//隐藏控制台光标
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	setConsoleCursorInfo(GetStdHandle(STD_OUTPIT_HANDLE), &cci);
}

void init_wall()
{
	for(int i = 0; i < HIGH; i++)
	{
		for(int j = 0; j < WIDE; j++)
		{
			if(i == HIGH || j == WIDE)
				printf("+");
			else
				printf(" ");			
		}
		if(i == 5)
		{
			printf("2019-2-28 create ");
		}
		if(i == 6)
		{
			printf("上:w");
		}
		if(i == 7)
		{
			printf("下:s");
		}
		if(i == 8)
		{
			printf("左:a");
		}
		if(i == 9)
		{
			printf("右:d");
		}
		printf("\n")
		
	}
}

typedef struct _body{
	int x;
	int y;
}BODY;

//蛇的结构体
typedef struct snake{
	BODY list[WIDE*HIGH];	//身体，身体的每一节坐标都是BODY类型
	int size;			//蛇的身体大小
	BODY food;
	COORD coord;		//光标位置
	int dx;			//蛇x轴移动的方向
	int dy;			//蛇y轴移动的方向
	int score;		//得分
	BODY tail;	
}SNAKE;

void init_food(SNAKE *snake)
{
	srand(time(NULL));//设置随机数种子
	//初始化食物坐标
	snake->food.x = rand()%WIDE;
	snack->food.y = rand()%HIGH;
}
void init_snake(SNAKE *snake)
{
	//初始化蛇头坐标
	snake->list[0].x = WIDE / 2;
	snake->list[0].y = HIGH / 2;
	//初始化蛇尾坐标
	snake->list[1].x = WIDE / 2 - 1;
	snake->list[1].y = HIGH / 2;
	//初始化蛇的身体大小
	snake->size = 2;
	//初始化食物坐标
	init_food(snake);
	//初始化蛇的移动方向
	snake->dx = 1;
	snake->dy = 0;
	//初始化分数
	snake->score = 0;
}

void show_ui(SNAKE *snake)
{
	//显示蛇，注意：每次显示蛇或食物，都要设置显示的位置，（光标的位置）
	for(int i = 0; i<snake->size; i++)
	{
		snake->coord.x = snake->list[i].x;
		snake->coord.y = snake->list[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPIT_HANDLE),snake->coord);
		if(0 == i)
		{
			printf("@");
		}
		else{printf("*");}
	}
	//显示食物
	snake->coord.x = food.x;
	snake->coord.y = food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPIT_HANDLE),snake->coord);
	printf("#");
	//将原来的尾巴显示为空格
	snake->coord.x = snake->tail.x;
	snake->coord.y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPIT_HANDLE),snake->coord);
	printf(" ");
}

void control_snake(SNAKE *snake)
{
	char key = 0;
	while(_kbhit())//判断是否按下键，按下不等于0
	{
		key = getch();
	}
	switch(key)
	{
		case 'a':
			snake->dx = -1;
			snake->dy = 0;
			break;
		case 'w':
			snake->dx = 0;
			snake->dy = -1;
			break;
		case 's':
			snake->dx = 0;
			snake->dy = 1;
			break;
		case 'd':
			snake->dx = 1;
			snake->dy = 0;
			break;
	}
}
//蛇移动
void move_snack(SNAKE *snake)
{
	//记录尾巴的坐标
	snake->tail.x = snake->list[snake->size-1].x;
	snake->tail.y = snake->list[snake->size-1].y;
	//更新蛇的身体，除蛇头
	
	for(int i = snake->size-1; i>0; i--)
	{
		snake->list[i] = snake->list[i-1];////将数组的前一个元素的坐标给后一节
	}
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
}

void snake_eat_food(SNAKE *snake)
{
	//如果蛇头和食物的坐标重合.则吃到了食物
	if(snake->list[0].x == snake->food.x &&
		snake->list[0].y == snake->food.y)
	{
		//原食物消失，生成新的食物
		init_food(snake);
		//蛇的身体增长一节
		snake->size++;
		//分数增加
		snake->score += 10;
	}
}

void game_end(SNAKE *snake)
{
	snake->coord.x = 25;
	snake->coord.y = 25;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPIT_HANDLE),snake->coord);
	printf("game over! the score you get is %d",snake->score);
	sleep(3000);
	exit(0);//退出进程
	
	void snake_eat_body(SNAKE *snake){
		//如果蛇头和蛇的身体的任意一节身体坐标相同,则吃到自己身体
		for(int i = 1; i< snake->size; i++)
		{
			if(snake->list[0].x == snake->list[i].x &&
				snake->list[0].y == snake->list[i].y)
			{
				game_end(snake);
			}
		}
	}
}
//开始游戏
void start_game(SNAKE *snake)
{
	while(snake->list[0].x<60 && snake->list[0],x >=0 &&
		snake->list[0].y<20 &&snake->list[0].y>=0)
		{
			//控制蛇的方向
			control_snake(snake);
			//更新蛇的坐标
			move_snake(snake);
			//蛇移动
			//system("CLS");//清屏
			//init_wall();
			show_ui(snack);
			//蛇是否碰到自己
			snake_eat_body(snake);
			//蛇是否碰到食物-（碰到食物，原食物消失，产生新的食物）
			snake_eat_food(snake);
			sleep(100);//延时0.5s			
		}
		game_end(snake);
}

int main()
{
	hide_cur();
	
	init_wall;
	//申请蛇的结构体
	SNAKE *snake = (SNAKE* )malloc(sizeof(SNAKE));
	show_ui(snake);
	start_game(snake);
	
	system("pause");
	return 0;
}