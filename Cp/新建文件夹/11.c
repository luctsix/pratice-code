#include<stdio.h>
#include<stdlib.h>

 int isTriangle(int a, int b, int c)
 {
	int i;
	int ret;

	if(a+b<=c || a+c<=b || b+c<=a) 	//非三角
		ret = 0;
	else if(a==b && b==c)		//等边
		ret = 1;
	else if(a==b && b!=c || b==c && c!=b || a==c&& c!=b)  //等腰
		ret = 2;
	else if(a*a+b*b==c*c || a*a==b*b+c*c || c*c+b*b==a*a)	//直角
		ret = 3;
	else if(a*a+b*b>c*c || a*a<b*b+c*c || c*c+b*b>a*a)		//钝角
		ret = 4;
	else if(a*a+b*b<c*c || a*a>b*b+c*c || c*c+a*a<b*b)		//锐角
		ret = 5;				
	return ret;
 }

 int main()
{
	unsigned int a[10], b[10], c[10];
	int x;
	int c1;
	int i = 0;
	int flag[10];
	
	printf("Input: \n");
	
	while(i<6)			//未能实现按-1停止输入
	{
		scanf("%d %d %d", &a[i], &b[i],&c[i]);
		//printf("第%d组：%d, %d, %d\n", i+1, a[i], b[i], c[i]);		
		//scanf("%d", &c1);
		//if(c1== -1)
		//break;
		i++;
	}
	for(x=0; x<i; x++)
	{
		printf("a[%d]=%d, b[%d]=%d, c[%d]=%d\n", x+1, a[x],x+1, b[x],x+1, c[x]);
	}
	
	printf("input successfully....\n");
	for(x = 0; x<i; x++)
	{
		printf("第%d个三角形！\n", x+1);
		flag[x] = isTriangle(a[x],b[x],c[x]);
		switch(flag[x])
		{
			case 0:
				printf("Not Triangle\n");
				break;
			case 1:
				printf("Regular Triangle\n");
				break;
			case 2:
				printf("Isoscceles Triangle\n");
				break;
			case 3:
				printf("(Right Triangle\n");
				break;
			case 4:
				printf("(Obtuse Triangle\n");
				break;
			case 5:
				printf("Acute Triangle\n");
				break;
			default:
				break;
		}
	}
	
	return 0;
}
