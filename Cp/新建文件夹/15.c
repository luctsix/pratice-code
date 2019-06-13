/*******************
015.
	劃兩個"小組吉祥物"，在 800 X 600 視窗不斷移動，遇到邊界會回彈。
	一個半徑30，第二個半徑60。
	一個往右下角移動，另一個往右上角移動。
	每移動一百步則[隨機]變換顏色。每次呼叫 delay 重新畫圖，定義為一次移動。
參考以下可執行檔執行結果
https://youtu.be/fUZwgllNEho
，以及程式碼。
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define RADIUS1 30
#define RADIUS2 60
#define STEP 10
#define DELAY_TIME 50

int main() {
	srand(time(NULL));
	initwindow(800,600);
	draw(1,1,0,1);
	getch();
	closegraph( );
}
************/


#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>


int main()
{
	initwindow(800 , 600);
	
	
	return 0;
}