#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m, n;
	int i = 1;
	int k;
	
	scanf("%d", &m);
	getchar();
	scanf("%d", &n);
	printf("m=%d, n=%d\n", m,n);
	
	switch(m)
	{
		case 1:
			while(i<=n)
			{
				for(k = 0; k<i; k++)
				{
					printf("*");
				}
				for(k = 0; k<n-i; k++)
				{
					printf(".");
				}
				printf("\n");
				i++;
			}
			break;
		case 2:
			while(i <= n)
			{
				for(k = 0; k<n-i;k++)
					printf(".");
				for(k = 0; k<i;k++)
					printf("*");
				printf("\n");
				i++;
			}
			break;
		
		default:
			break;
	}
	
	
	return 0;
}