#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

int isHuiwen(int n)
{
	//printf("testing..\n");
	int j=0, i=n;
	int key;
	//printf("i=%d\n", i);
	while(n)
	{
		//printf("i=%d\n", i);
		j = 10*j + n%10;
		n = n/10;
	}
	if(j == i)
	{	
		return key = 1;
		//printf("testing...");
	}
	else 
		return key = 0;
}

int main()
{
	int n, m;
	int i;
	int key;
	int count=0;
	
	system("cls");
	
	printf("please input two integers:");
	scanf("%d %d", &n, &m);
	//getch();
	printf("n=%d, m=%d\n", n, m);
	
	printf("the hui wen number between %d & %d:", n, m);
	for(i=n; i<=m; i++)
	{
		//printf("i=%d\n", i);
		key = isHuiwen(i);
		if(key == 1)
		{
			printf("%d  ", i);
			count++;
			if(count%5 == 0)
				printf("\n");
		}
	}
	printf("\n");	
	
	return 0;
}