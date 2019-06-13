#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char a1;
	double a = 0, b = 0, c = 0, d = 0;
	printf("请输入名字和四门成绩：");
	scanf("%c %lf %lf %lf %lf", &a1,&a,&b,&c,&d);
	//printf("a1 = %c\n", a1);
	//printf("a=%lf, b=%lf, c=%lf, d=%lf\n", a, b, c, d);

	double i, f;
	i = a + b + c + d;
	f = i / 4;
	printf("学生的总成绩是：%lf\n 平均成绩是：%lf", i, f);

	system("pause");
	return 0;
}