/*******************
015.
	���ɂ�"С�M������"���� 800 X 600 ҕ�������Ƅӣ�����߅����؏���
	һ���돽30���ڶ����돽60��
	һ�������½��Ƅӣ���һ�������Ͻ��Ƅӡ�
	ÿ�Ƅ�һ�ٲ��t[�S�C]׃�Q�ɫ��ÿ�κ��� delay ���®��D�����x��һ���Ƅӡ�
�������¿Ɉ��Йn���нY��
https://youtu.be/fUZwgllNEho
���Լ���ʽ�a��
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