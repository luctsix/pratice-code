/*
算法分析：
	1.输入测试案例n，和每组案例的线段组数m
	2.依次输入每组的个线段的数值，以a[]和b[]分别存储线段两端的端点数值
	3.计算每个案例的覆盖长度，注意重复计算问题，并分别输出
	4.end
*/


#include<stdio.h>
#include<stdlib.h>

int getLen(int *a, int *b, int m)
{
	int j;
	for(j = 0; j<m; j++)
	{
		printf("a[%d]=%d  b[%d]=%d\n", j, a[j], j, b[j]);
	}
	int i = 1;
	int len = 0;
	
	len = b[0] - a[0]; // 第一条线段的长度
	//printf("len = %d", len);
	
	 //判断前后两线段的位置关系
	
	while(i<=m)
	{
		if(a[i]>b[i-1])
		{
			len = len + b[i]-a[i];
		}
		else{
			len = b[i] - a[0];
		}
		i++;
	}
	printf("%d\n", len);
	
	return len;
}

int main()
{
	int n, m;		//n组测试案例、、m个线段
	int a[10], b[10];	//分别存线段的两个端点
	int l, k, i = 0, j = 1;
	int lenth[10];
	int len;
	
	printf("please input the group number: \n");
	scanf("%d", &n);
	
	printf("n = %d\n", n);
	for(l = 0; l<n; l++)
	{		
		scanf("%d", &m);	//第l 个案例的m条线段
		for(k=0; k<m; k++)  //输入m条线段的端点信息
		{
			printf("please input the terminal point's info!\n");
			scanf("%d  %d", &a[k], &b[k]);
			//scanf("%d", &b[k]);
			//getch();
		}				//每组案例输完后即计算长度，并储存在l数组，后面依次输出；
		//printf("a[0]=%d, b[0]=%d\n", a[0], b[0]);
		//lenth[i] = getLen(&a[10], &b[10], m);
		if(m == 1)
		{	
			lenth[l] = b[0] - a[0]; // 第一条线段的长度
			continue;
		//printf("len = %d", len);
		}
		//判断前后两线段的位置关系
		//printf("%d\n", len);
		else{			//  m>1
			len = b[0] - a[0];
			i = 1;
			while(i<m)							//头端点	a  i-1  i
			{									//尾端点    b  i-1  i
				if(a[i]>=b[i-1])
				{
					len = len + b[i]-a[i];
				}
				else if(b[i]>b[i-1]){		//a[i]<b[i-1]
					len = len+b[i] - b[i-1];
				}
				else if(b[i]<b[i-1])
				{
					len += 0;
				}
				i++;
			}
		}
		lenth[l] = len;
	}
	
	for(i = 0; i < n; i++)
	{
		printf("%d\n", lenth[i]);
	}
		
	return 0;	
}