#include<stdio.h>
#include<stdlib.h>

int isPrime(int n)
{
	int i, key;
	for(i = 2; i < n; i++)
	{
		if(n%i == 0)
			return key = 0;
	}
	return key = 1;
}

int main()
{
	int n;	
	int i, k;
	int count = 0;
	
	
	printf("please input a number:");
	scanf("%d", &n);
	
	k = n;
	
	while(n)
	{
		if(isPrime(n) == 1)
		{
			printf("%d字串中最大的质数为%d\n", k , n);
			break;
		}
		n = n/10;
	}
	
	return 0;
}