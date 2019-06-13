#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *str)//字符串逆转
{
	int n = strlen(str)-1;
	int i =0;
	char c;
	
	while(i < n)
	{
		c = str[i];
		str[i] = str[n];
		str[n] = c;
		i++;
		n--;
	}
}

int main()
{
	char str[20] = {0};
	char str2[20] = {0};
	
	printf("请输入一个字符串：");
	scanf("%s", str);
	
	strcpy(str2,str);  //用str2保存str中的字符串，用于与str反转后的比较
	
	reverse(str);	//逆转字符串
	
	if(strcmp(str2,str) == 0)	//判断是否为回文
	{
		printf("输入的字符串%s是回文\n", str);
	}
	else{
		printf("输入的字符串%s不是回文\n", str);
	}
	
	return 0;
}