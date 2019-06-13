#ifndef _SNAKE_H_
#define _SNAKE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

#define WIDE 60
#define HIGH 20

int count = 0;

typedef struct body{
    int x;
    int y;
}BODY;

typedef struct snake{
    BODY list[WIDE*HIGH];   //身体，每一节都是BODY类型
    int size;               //大小
    BODY food;              //食物坐标
    COORD coord;            //光标的信息位置
    int dx;                 //蛇移动的x轴方向
    int dy;                 //蛇移动的y轴方向
    int score;              //得分
    BODY tail;              //尾巴的位置
}SNAKE;

//函数声明

void hide_cur();    //隐藏光标
void init_wall();   //初始化游戏界面
void init_food(SNAKE *snake);   //生成食物坐标
void init_snake(SNAKE *snake);  //生成蛇

void show_ui(SNAKE *snake);     //渲染游戏
void end_game(SNAKE *snake);

void control_snake(SNAKE *snake);    //控制蛇的移动
void snake_move(SNAKE *snake);          //蛇移动后位置信息的更新
void snake_eat_food(SNAKE *snake);      //吃到食物

void game_end(SNAKE *snake);            //游戏结束 
void snake_eat_body(SNAKE *snake);      //咬到自己的身体
void start_game(SNAKE *snake);      //开始游戏

#endif