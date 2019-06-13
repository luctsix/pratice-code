#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
int main(int argc, char* argv[])
{	

	char dst[100];
	int a = 10;
	char src[] = "hello world";
	printf("a = %d, src = %s", a, src);
	printf("\n");
	
	
	int len = sprintf(dst, "a = %d, src = %s", a, src);
	printf("dst = \" %s\"\n", dst);
	printf("len = %d\n", len);

	char src[] = "a = 10, b = 20 ";
	int a, b;
	char c;
	int ret;
	ret = sscanf(src, "%c = %d, b = %d",&c, &a, &b);
	printf("ret = %d\n", ret);
	printf("a = %d, b = %d", a, b);
	printf("\nc = %c", c);

	//char str[] = {"aaaaaasssssssssdcdsfkjfkfjsjbnfksjbd"};
	//char *p = strchr(str, 'd');
	
	// char* p = strstr(str, "dcdsf");
	//printf("%s", p);
	
	char a[100] = "adc*fvcv*ebcy*hghbdfg*casdert";
	char str[] = "     213213";
	char b[] = "21312.434";
	char c[] = "000012312217";
	double j;
	int	i;
	long k;
	k = atol(c);
	i = atoi(str);
	j = atod(b);
	char *s = strtok(a, "*");
	while(s != NULL){
		//printf("%s", s);
		s = strtok(NULL, "*");
	}
	printf("%d\n", i );
	printf("%f\n", j );
	printf("%ld\n", k );
*/
	struct stu{
		char name[50];
		int age;
	};
	
	void input(struct stu p1)
	{
		strcpy(p1.name, "lucky");
		p1.age = 18;
		printf("name = %s\nage = %d\n", p1.name, p1.age);
	}
	int main(){
		struct stu p;
		input(p);
		printf("name = %s\nage = %d", p.name, p.age);
		
		return 0;
		
	}


	

