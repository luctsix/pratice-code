#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	typedef int(*ARR)[4];
	ARR a;
	a = (ARR)malloc(3 * sizeof(int[4]));
	
	
	int count = 0;

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			//(*(a+i)+j) = (int*)malloc(sizeof(int));
			*(*(a+i)+j) = ++count;
		}
	}
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			printf("a[%d][%d]=%d ", i, j, *(*(a+i)+j));
		}
		printf("\n");
	}
	
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			//(*(a+i)+j) = (int*)malloc(sizeof(int));
			free(*(a+i)+j);
		}
	}
	free(a);
	a = NULL;
	
	
	
	return 0;
}