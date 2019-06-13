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
	//���ؿ���̨���
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
			printf("��:w");
		}
		if(i == 7)
		{
			printf("��:s");
		}
		if(i == 8)
		{
			printf("��:a");
		}
		if(i == 9)
		{
			printf("��:d");
		}
		printf("\n")
		
	}
}

typedef struct _body{
	int x;
	int y;
}BODY;

//�ߵĽṹ��
typedef struct snake{
	BODY list[WIDE*HIGH];	//���壬�����ÿһ�����궼��BODY����
	int size;			//�ߵ������С
	BODY food;
	COORD coord;		//���λ��
	int dx;			//��x���ƶ��ķ���
	int dy;			//��y���ƶ��ķ���
	int score;		//�÷�
	BODY tail;	
}SNAKE;

void init_food(SNAKE *snake)
{
	srand(time(NULL));//�������������
	//��ʼ��ʳ������
	snake->food.x = rand()%WIDE;
	snack->food.y = rand()%HIGH;
}
void init_snake(SNAKE *snake)
{
	//��ʼ����ͷ����
	snake->list[0].x = WIDE / 2;
	snake->list[0].y = HIGH / 2;
	//��ʼ����β����
	snake->list[1].x = WIDE / 2 - 1;
	snake->list[1].y = HIGH / 2;
	//��ʼ���ߵ������С
	snake->size = 2;
	//��ʼ��ʳ������
	init_food(snake);
	//��ʼ���ߵ��ƶ�����
	snake->dx = 1;
	snake->dy = 0;
	//��ʼ������
	snake->score = 0;
}

void show_ui(SNAKE *snake)
{
	//��ʾ�ߣ�ע�⣺ÿ����ʾ�߻�ʳ���Ҫ������ʾ��λ�ã�������λ�ã�
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
	//��ʾʳ��
	snake->coord.x = food.x;
	snake->coord.y = food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPIT_HANDLE),snake->coord);
	printf("#");
	//��ԭ����β����ʾΪ�ո�
	snake->coord.x = snake->tail.x;
	snake->coord.y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPIT_HANDLE),snake->coord);
	printf(" ");
}

void control_snake(SNAKE *snake)
{
	char key = 0;
	while(_kbhit())//�ж��Ƿ��¼������²�����0
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
//���ƶ�
void move_snack(SNAKE *snake)
{
	//��¼β�͵�����
	snake->tail.x = snake->list[snake->size-1].x;
	snake->tail.y = snake->list[snake->size-1].y;
	//�����ߵ����壬����ͷ
	
	for(int i = snake->size-1; i>0; i--)
	{
		snake->list[i] = snake->list[i-1];////�������ǰһ��Ԫ�ص��������һ��
	}
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
}

void snake_eat_food(SNAKE *snake)
{
	//�����ͷ��ʳ��������غ�.��Ե���ʳ��
	if(snake->list[0].x == snake->food.x &&
		snake->list[0].y == snake->food.y)
	{
		//ԭʳ����ʧ�������µ�ʳ��
		init_food(snake);
		//�ߵ���������һ��
		snake->size++;
		//��������
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
	exit(0);//�˳�����
	
	void snake_eat_body(SNAKE *snake){
		//�����ͷ���ߵ����������һ������������ͬ,��Ե��Լ�����
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
//��ʼ��Ϸ
void start_game(SNAKE *snake)
{
	while(snake->list[0].x<60 && snake->list[0],x >=0 &&
		snake->list[0].y<20 &&snake->list[0].y>=0)
		{
			//�����ߵķ���
			control_snake(snake);
			//�����ߵ�����
			move_snake(snake);
			//���ƶ�
			//system("CLS");//����
			//init_wall();
			show_ui(snack);
			//���Ƿ������Լ�
			snake_eat_body(snake);
			//���Ƿ�����ʳ��-������ʳ�ԭʳ����ʧ�������µ�ʳ�
			snake_eat_food(snake);
			sleep(100);//��ʱ0.5s			
		}
		game_end(snake);
}

int main()
{
	hide_cur();
	
	init_wall;
	//�����ߵĽṹ��
	SNAKE *snake = (SNAKE* )malloc(sizeof(SNAKE));
	show_ui(snake);
	start_game(snake);
	
	system("pause");
	return 0;
}