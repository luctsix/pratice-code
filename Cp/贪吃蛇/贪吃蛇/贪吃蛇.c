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
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void init_wall()
{
	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDE; j++)
		{
			if (i == HIGH || j == WIDE)
			{
				printf("+");
			}
			else {
				printf(" ");
			}
		}
		if (i == 5)
		{
			printf("2019-3-11 crreate ");
		}
		if (i == 6)
		{
			printf("�ϣ�w");
		}
		if (i == 7)
		{
			printf("�£�s");
		}
		if (i == 8)
		{
			printf("��a");
		}
		if (i == 9)
		{
			printf("�ң�d");
		}
		printf("\n");
	}
}

typedef struct _body {
	int x;
	int y;
}BODY;

typedef struct snake {
	BODY list[WIDE*HIGH];
	int size;
	BODY food;
	COORD coord;
	int dx;
	int dy;
	int score;
	BODY tail;
}SNAKE;

void init_food(SNAKE *snake)
{
	srand((unsigned int)time(NULL));
	snake->food.x = rand() % WIDE;
	snake->food.y = rand() % HIGH;
}
void init_snake(SNAKE *snake)
{
	snake->list[0].x = WIDE / 2;
	snake->list[0].y = HIGH / 2;
	snake->list[1].x = WIDE / 2 - 1;
	snake->list[1].y = HIGH / 2;
	snake->size = 2;

	init_food(snake);

	snake->dx = 1;
	snake->dy = 0;
	snake->score = 0;
}

void show_ui(SNAKE *snake)
{
	for (int i = 0; i < snake->size; i++)
	{
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
		if (0 == i)
			printf("@");
		else
			printf("*");
	}
	snake->coord.X = snake->food.x;
	snake->coord.Y = snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("#");
	snake->coord.X = snake->tail.x;
	snake->coord.Y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf(" ");
}

void control_snake(SNAKE *snake)
{
	char key = 0;
	while (_kbhit())
	{
		key = _getch();
	}
	switch (key)
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

void move_snake(SNAKE *snake)
{
	snake->tail.x = snake->list[snake->size - 1].x;
	snake->tail.y = snake->list[snake->size - 1].y;

	for (int i = snake->size - 1; i > 0; i--)
	{
		snake->list[i] = snake->list[i - 1];
	}
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
}

void snake_eat_food(SNAKE *snake)
{
	if (snake->list[0].x == snake->food.x && snake->list[0].y == snake->food.y)
	{
		init_food(snake);
		snake->size++;
		snake->score += 10;
	}
}

void game_end(SNAKE *snake)
{
	snake->coord.X = 25;
	snake->coord.Y = 25;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	Sleep(3000);
	exit(0);
}

void snake_eat_body(SNAKE *snake)
{
	for (int i = 1; i < snake->size; i++)
	{
		if (snake->list[0].x == snake->list[i].x &&
			snake->list[0].y == snake->list[i].y)
		{
			game_end(snake);
		}
	}
}

void start_game(SNAKE *snake)
{
	while (snake->list[0].x < 60 && snake->list[0].x >= 0 &&
		snake->list[0].y < 20 && snake->list[0].y >= 0)
	{
		control_snake(snake);
		move_snake(snake);
		show_ui(snake);
		snake_eat_body(snake);
		snake_eat_food(snake);
		Sleep(100);
	}
	game_end(snake);
}


int main()
{
	hide_cur();

	init_wall();

	SNAKE *snake = (SNAKE*)malloc(sizeof(SNAKE));
	init_snake(snake);
	show_ui(snake);
	start_game(snake);

	system("pause");
	return 0;
}