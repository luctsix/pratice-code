/***********************
0-2h	30元/0.5h	<0.5h以0.5h记
2<x<4	40元/0.5h   
x>4		60元/0.5

a[i][2]
while(1)

	scanf("%d:%d",a[i][0], a[i][1])；
	if(a[i][0]>24 && a[i][1]>0 || a[i][1]>60 ||)
		ret = 1;
	if(a[i][0]== -1 ||a[i][1]==-1)
		break;
	
a[i][0]:a[i][1]
a[i+1][0]:a[i+1][1]

if(a[i+1][1]<a[i][1])
	a[i+1][0]--;
	a[i+1][1] += 60；
min = a[i+1][0]-a[i][0]a[i+1][1]-a[i][1]

*********************/

#include<stdio.h>
#include<stdlib.h>

int Cost(int n)
{
	int cost;
	if(!n)
	{
		printf("Wrong!!!\n"); 
		exit;
	}
	if(n%30 != 0)
	{
		n = n/30+1;
		printf("n = %d\n", n);
	}
	else{
		n = n/30;
	}
	
	while(n)
	{
		if(n>0 && n<=4)		//0--120
		{
			return cost = 30*n;
		}
		else if(n>4 && n<=8)			//120-240
		{
			return cost = 30*4 +40*(n-4);
		}
		else{
			return cost = 30*4+40*4+60*(n-8);
		}
	}	
}

int main()
{
	int h[10], m[10];
	int k, j, i = 0;
	int ret[10] = {0};
	int min = 0;
	int cost;
	
	while(1)
	{
		scanf("%d:%d",&h[i], &m[i]);
		if(h[i]>=24 || m[i]>60 || h[i]<0)		
		{
			ret[i] = 1;
			printf("error! Input wrong form!\n");
		}
		printf("h[%d]=%d, m[%d]=%d\n", i, h[i], i, m[i]);
		if(h[i]== -1 || m[i]==-1)
			break;
		i++;
	}
	
	for(k=1; k<i; k++)		//计算停车的分钟数
	{
		if(ret[k] == 1)
			break;
		if(m[k]<m[k-1])
		{
			h[k]--;
			m[k] += 60;
			printf("h[%d]=%d, m[%d]=%d\n", k,h[k],k,m[k]);
			min = 60*(h[k]-h[k-1])+m[k]-m[k-1];
		}
		else{
			min = 60*(h[k]-h[k-1])+m[k]-m[k-1];
		}	
	}
	printf("min=%d\n", min);
	
	cost = Cost(min);
	
	printf("cost:%d", cost);
	
	
	return 0;
}