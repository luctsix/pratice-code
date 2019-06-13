#include<stdio.h>
#include<stdlib.h> 

void my_strcpy(char *str1, char *str2)
{
	if(*str1 == '\0'){
		printf(" Input Error!\n");
		exit;
	}

	while(*str1!='\0'){
		*str2 = *str1;
		str2++;
		str1++;
	}
	*str2 = '\0';
	//printf("str2 = %s\n", str2);

}


int main()
{
	char str1[20];
	char str2[20];
	
	
	puts("ÇëÊäÈë²âÊÔµÄ×Ö·û´®£º");
	gets(str1);
	
	my_strcpy(str1, str2);
	
	printf("str2 = %s\n", str2);
	
	return 0;
}
