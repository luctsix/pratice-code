#include<stdio.h>
#include<math.h>

#define M 10

void compute(int x1, int y1, int x2, int y2, int *peri,  int *area)
{
	*peri = fabs(x1-x2)+fabs(y1-y2)+fabs(x1-x2)+fabs(y1-y2);
	
	*area = fabs(x1-x2)*fabs(y1-y2);	
}

int main()
{
	int x1[M], y1[M], x2[M], y2[M];
	int k, i = 0;
	int peri[M], area[M];
	
	while(1)		//输入矩形端点的坐标
	{
		scanf("%d,%d,%d,%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		//printf("%d %d %d %d\n", x1[i], y1[i], x2[i], y2[i]);
		if(x1[i] == -1)
			break;
		i++;		
	}
	
	for(k=0; k<=i; k++)
	{
		compute(x1[k], y1[k], x2[k], y2[k],&peri[k],&area[k]);
	}
	
	int maxperi = peri[0];
	int maxarea = area[0];
	
	for(k=1; k<=i; k++)
	{
		if(maxperi<peri[k])
			maxperi = peri[k];
		if(maxarea<area[k])
			maxarea = area[k];
	}
	
	printf("最大的面积为%d\n", maxarea);
	printf("最大的周长为%d\n", maxperi);
	
	return 0;
}