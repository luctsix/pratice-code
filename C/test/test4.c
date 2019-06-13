#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int arr[3][4] = {0};	//用来保存三个学生的四门成绩
	int i, j;
	int sum[3] = {0};		//记录每个学生的总成绩
	
	for(i=0;i<3;i++)	//成绩录入
	{
		printf("请输入第%d名学生的成绩:\n", i+1);
		for(j = 0; j < 4; j++)
		{
			printf("请输入第%d门课的成绩:", j+1);
			scanf("%d", &arr[i][j]);

			sum[i] += arr[i][j];
		}
	}
	
	for(i = 0; i<3; i++)	//总分和平均分打印
	{
		printf("第%d名学生的总成绩为%d\t平均分为%.1lf\n", i+1, sum[i], sum[i]/4.0);
	}
	return 0;
}