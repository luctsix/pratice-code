#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	#if 0
	int i = 0;
	char str[64] = {0};
	printf("please input the string:");
	gets(str);
	
	int n = sizeof(str)/sizeof(char);
	for(int j=0; j<n; j++)
	{
		//printf("str[j] = %c\n", str[j]);
		if(str[j]!=' ')
		{
			
			str[i++] = str[j];
		}
	}
	str[i] = '\0';
	#endif
	
	#if 0
	char *str = (char *)malloc(64);
	memset(str, 0, 64);
	printf("please input the string:");
	gets(str);
	printf("str = %s\n", str);
	
	char *p = str, *q = str;
	while(*p++ != '\0')
	{
		if(*p != ' ')
		{
			*q++ = *p;
		}
	}
	*q = '\0';
	#endif
	
	
	
	printf("str = %s\n",  str);
	
	return 0;
}