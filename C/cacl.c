#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int a, int b)
{
	return (a+b);
}
int sub(int a, int b)
{
	return (a-b);
}
int mux(int a, int b)
{
	return (a*b);
}
int dive(int a, int b)
{
	return (a/b);
}

int main()
{
	int a, b;
	char s[20] = {0};
	char src[20] = {0};
	int ret;
	
	while(1)
	{
		system("cls");
		printf("请输入指令和操作数：");
		gets(src);
		//getchar();
		sscanf(src, "%s %d %d", s, &a, &b);
		//printf("%s\n",src);
		//printf("%s\n",s);
		//printf("a = %d, b = %d\n", a ,b);
		if(strcmp(s,"add") == 0)	
		{
			ret = add(a,b);
			printf("a+b = %d\n", ret);
		}
		else if(strcmp(s,"sub") == 0)
		{
			ret = sub(a,b);
			printf("a-b = %d\n", ret);
		}
		else if(strcmp(s,"mux") == 0)
		{
			ret = mux(a,b);
			printf("a*b = %d\n", ret);
		}
		else if(strcmp(s,"dive") == 0)
		{
			ret = dive(a,b);
			printf("a/b = %d\n", ret);
		}
		printf("按任意键继续使用计算器，退出请按q!\n");
		char c;
		scanf("%c", &c);
		getchar();
		if(c == 'q')
			break;
	}
	system("cls");
	
	return 0;
}

