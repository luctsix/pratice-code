#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *str)//�ַ�����ת
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
	
	printf("������һ���ַ�����");
	scanf("%s", str);
	
	strcpy(str2,str);  //��str2����str�е��ַ�����������str��ת��ıȽ�
	
	reverse(str);	//��ת�ַ���
	
	if(strcmp(str2,str) == 0)	//�ж��Ƿ�Ϊ����
	{
		printf("������ַ���%s�ǻ���\n", str);
	}
	else{
		printf("������ַ���%s���ǻ���\n", str);
	}
	
	return 0;
}