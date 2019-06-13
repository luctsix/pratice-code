/************

先打印上半部分
	每行先打印n/2个. -> 再打印1,2....n...2,1

**************/

#include<stdio.h>
#include<stdlib.h>

void printSample1(int n)		//n为1-18的奇数
{
	int m1 = n/2+1;			//一半的行数
	int m2 = n/2;			//下半部分的行数
	int i,j,k;
	
	printf("Sample1 Output:\n");
	
	//上半部分m1行
	for(j=1; j<=m1;j++)	//打印一到n/2+1行
	{
		for(k=j;k<=m1-1;k++)	//打印.
		{
			printf(".");
		}
		for(k=1; k<=j; k++)	//打印 1 到 k
		{
			printf("%d",k);
		}
		for(k=j-1; k>=1;k--)		//打印n-1 到 1 
		{
			printf("%d",k);
		}
		
		printf("\n");		//每行打印完换行	
	}
	//下半部分的m2行
	for(j=m2; j>=1; j--)	//下半部分的行数
	{
		for(k=j;k<=m2;k++)
		{	
			printf(".");
		}
		for(k=1;k<=j;k++)
		{
			printf("%d", k);
		}
		for(k=j-1;k>=1;k--)
		{
			printf("%d",k);
		}
		printf("\n");
	}
	
	
}

void printSample2(int n)
{
	int m = 2*n-1;
	int i,j,k;
	
	printf("Sample2 Output:\n");
	for(i=1;i<=n;i++)		//打印n行
	{
		for(j=1;j<i;j++)	//打印.
		{
			printf(".");
		}
		for(k=m;k>=1;k-=2)	//
		{
			printf("%d",k);
		}
		for(k=1;k<=m-2;k+=2)
		{
			printf("%d",k+2);
		}
		m -= 2;
		printf("\n");
	}
}


int main()
{
	int a[10] , b[10];
	int j, i = 0;
	int ret[10] = {0};
	
	system("cls");
	
	printf("Input:\n");
	
	while(1)
	{
		scanf("%d,%d", &a[i], &b[i]);
		//判断输入是否符合规定
		if(a[i]!=1 && a[i]!=2 && a[i]!=-1)
		{
			printf("Input Error!\n");
		}
		switch(a[i])
		{
			case 1:
				if(b[i]<1 || b[i]>18)
				{
					printf("Input error!\n");
					ret[i] = 1;
				}
				else if(b[i]%2==0)
				{
					printf("Input error!\n");
					ret[i] = 1;
				}
				break;
			case 2:
				if(b[i]<1 || b[i]>5)
				{
					printf("input Error!\n");
					ret[i] = 1;
				}	
			default:
				break;
		}
		if(a[i]==-1 || b[i]==-1)
			break;
		if(ret[i]!=1)
			printf("input successfully!\n");
		i++;
	}
	
	
	for(j=0; j<i;j++)
	{
		if(ret[j]== 1)
			continue;
		if(a[j]==1)
			printSample1(b[j]);
		else
		{
			printSample2(b[j]);
		}
	}
	
	return 0;
}