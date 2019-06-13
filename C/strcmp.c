#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int strcmp1(char str1[], char str2[])
{
	
	int i;
	if(str1[0] == '0' || str2[0] == '0')
	{
		printf("Input Error!\n");
		return -2;
	}
	for(i=0; str1[i]!='\0' || str2[i]!='\0'; i++)
	{
		if(str1[i] == str2[i])
			continue;
		else if(str1[i] > str2[i])
			return 1;
		else 
			return -1;
	}
	return 0;
}

int main()
{
	char str1[20] = {0};
	char str2[20] = {0};
	int ret;
	
	system("cls");
	
	printf("请输入第一个字符串str1：");
	scanf("%s", str1);
	getchar();
	printf("请输入第二个字符串str2：");
	scanf("%s", str2);

	ret = strcmp1(str1, str2);
	if(ret == 0)
		printf("str1 = str2\n");
	else if(ret == -1)
		printf("str1 < str2\n");
	else if(ret == 1)
		printf("str1 > str2\n");
	
	return 0;
}
