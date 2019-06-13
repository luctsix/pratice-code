#include<stdio.h>

int my_atoi(char *str)//"+123"
{
	int i, sum = 0;
	if(str == NULL)
	{
		printf("stderr: Input Error!\n");
		return -1;
	}
	if(*str == '+')
	{
		str++;
		while(*str)//''-'0'
		{
			i = *str - '0';
			sum = sum*10 + i;//123  1  2  3
			str++;
		}
		return sum;
	}
	else if(*str == '-')
	{
		str++;
		while(*str)
		{
			i = *str - '0';
			sum = sum*10 + i;
			str++;
		}
		return -sum;
		
	}
	else{
		while(*str)
		{
			i = *str - '0';
			sum = sum*10 + i;
			str++;
		}
		return sum;
	}
}

int main()
{
	char str[20];
	int n;
	
	printf("请输入需要转化的字符串：");
	gets(str);
	
	n = my_atoi(str);
	
	printf("n = %d\n", n);
	
	return 0;
}