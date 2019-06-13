#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	char name[32];
	char num[16];
	char majority[16];
	char addr[16];
}STU;

int main()
{
	char str[32];
	
	FILE *file = fopen("test.txt", "r");
	if(!file)
	{
		//perror(open);
		return -1;
	}
	//printf("%s\n", stderr);
	
	//fputs("asaddwdsd", file);
	fseek(file, 0,SEEK_SET);
	
/*	//char arr[20];
	//char c = fgetc(file);
	//fgets(arr, sizeof(arr),file);
	//printf("c = %c\n", c);
	//printf("arr = %s\n", arr);
	
	//char name[32]={0},num[32]={0};
	//fprintf(file, "name: zhuzhu\tnum:19941026\n");
	//fseek(file, 0, SEEK_SET);
	//fscanf(file, "name:%s\tnum:%s", name, num);
	
	//printf("name:%s\tnum:%s\n" , name, num);
	*/
	
	
	STU p1;// = {"sizhu", "12345678", "Ocean Pharm", "Liuzhou"};
	memset(&p1, 0, sizeof(p1));
	int ret = fread(&p1,  1, sizeof(p1), file);
	printf("ret = %d\n",ret);
	//strcpy(p1.name, "abc");
	printf("name:%s\nnum:%s\nmajority:%s\naddr:%s\n", p1.name,p1.num, p1.majority, p1.addr);
	
	//int ret = fwrite(&p1, sizeof(p1),1,file);
	
	fclose(file);
	
	return 0;
}