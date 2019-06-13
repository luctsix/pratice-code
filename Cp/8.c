#include<stdio.h>
#define SUCCESS 0
int main()
{
	int a, b ,c;	//课程编号
	int ha, hb , hc;	//上课小时数
	int ta[10], tb[10], tc[10];
	int i, j;
	int flag = 0;
	
	//第一门课
	printf("please input the first class!\n");
	scanf("%d", &a);
	scanf("%d", &ha);
	for(i = 0; i<ha;i++)
	{
		scanf("%d", &ta[i]);
	}
	printf("%d, %d\n", ta[0],ta[1]);
		
	//第二门课
	printf("please input the second class!\n");
	scanf("%d", &b);
	scanf("%d", &hb);
	for(i = 0; i < hb; i++)
	{
		scanf("%d", &tb[i]);
	}
	printf("%d, %d\n", tb[0],tb[1]);
	
	//第三门课
	printf("please input the third class!\n");
	scanf("%d", &c);
	scanf("%d", &hc);
	for(i = 0; i < hc; i++)
	{
		scanf("%d", &tc[i]);
	}
	printf("%d, %d\n", tc[0],tc[1]);
	
	for(i = 0; i < ha; i++)
	{
		for(j = 0; j<hb; j++ )
		{
			if(ta[i] == tb[j])
			{
				printf("compare tb[%d] with ta[%d]", j, i);
				printf("%d,  %d, %d\n", a, b, ta[i]);
				flag = 1;
			}
		}
	}
	for(i = 0; i < ha; i++)
	{	
		for(j = 0; j<hc; j++ )
		{
			if(ta[i] == tc[j])
			{
				printf("compare tc[%d] with ta[%d]", j, i);
				printf("%d,  %d, %d\n", a, c, ta[i]);
				flag = 1;
			}
		}
	}
	
	for(i = 0; i < hb; i++)
	{
		for(j = 0; j<hc; j++ )
		{
			if(tb[i] == tc[j])
			{
				printf("compare tb[%d] with tc[%d]", i, j);
				printf("%d,  %d, %d\n", b, c, tb[i]);
				flag = 1;
			}
		}
	}
	
	printf("flag = %d\n", flag);
	
	if(flag == 0)
	{
		printf("correct!\n");
	}
	
	return SUCCESS;
}