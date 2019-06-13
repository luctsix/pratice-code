#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char s[90];
	int length = 0;
	int k;
	
	printf("Sample Input:\n");
	scanf("%d", &n);
	getchar();
	gets(s);
	length = strlen(s);
	printf("length = %d\n", length);
	
	printf("Sample Output:\n");
	for(k = 0; k<length; k++)
	{
		switch(s[k])
		{
			case 'R':
				break;
			case 'N':
				break;
			case 'L':
				break;
		}
	}
	
	
	return 0;
}