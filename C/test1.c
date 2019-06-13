#include<stdio.h>

int main()
{
	int n = 9;
	int i, j;
	for(i=1; i<=n; i++)
	{
		for(j = 1; j<=i; j++)
		{
			printf("%d * %d = %2d  ", j, i, j*i);
		}
		printf("\n");
	}

	return 0;
}