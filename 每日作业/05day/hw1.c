#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>


//1��ѭ������ṹ����Ϣ��������ageС��0ʱ�����������
//2����ѯ�����û���Ϣ
//3������Ҫɾ����������Ȼ����ļ�����Ӧ�����ֵĽṹɾ��
//4��������ʹ�õڶ����ļ���ֻ��һ���ļ�������������
//5����Ҫʹ�õ��ļ����Ĳ�������fwrite��fread
typedef struct student
{
	char name[20];
	int age;
}Stu_t;

void menu();
void w_file(Stu_t *s);
void catch();
void delete(char *str);

int main()
{
	system("cls");
	while(1)
	{
		menu();
		printf("input��");
		int n;
		scanf("%d", &n);
		getchar();
		//printf("n=%d\n",n);
		switch(n)
		{
			case 1:
				while(1)
				{
					Stu_t s;
					memset(&s, 0, sizeof(Stu_t));
					printf("������ѧ����������");
					scanf("%s",s.name);
					//printf("name = %s\t", s.name);
					getchar();
					printf("������ѧ�������䣺");
					scanf("%d", &(s.age));
					//printf("age:%d\n", s.age);
					//getchar();
					if(s.age<0)
					{
						break;
					}
					w_file(&s);
				}
				break;
			case 2:
				catch();
				//system("pause");
				break;
			case 3:
				printf("������Ҫɾ�����û�����");
				char str[20] = {0};
				scanf("%s", str);
				delete(str);
				break;
			case 4:
				//goto A;
				system("cls");
				break;
			case 5:
				return 0;
			default:
				break;
		}	
	}
	return 0;
}

void delete(char *str)
{
	FILE *file = fopen("test.txt", "r");
	if(!file)
	{
		perror("fopen err");
		return;
	}
	int i = 0;

	Stu_t **s = (Stu_t**)malloc(sizeof(Stu_t*));
	*s = (Stu_t*)malloc(sizeof(Stu_t));
	memset(*s, 0, sizeof(Stu_t));
	Stu_t *s1 = (Stu_t*)malloc(sizeof(Stu_t));
	
	while(1)
	{
		memset(s1, 0, sizeof(Stu_t));
		
		fread(s1, 1, sizeof(Stu_t), file);
		//printf("name:%s\tage:%d\n", s1->name, s1->age);
		//printf("%s\n", s.name);
		if(feof(file))
		{
			//printf("2\n");
			break;
		}
		
		if(strcmp(str, s1->name) != 0)
		{
			
			i++;
			s = (Stu_t**)realloc(s, (1+i)*sizeof(Stu_t*));
			s[i] = (Stu_t*)malloc(sizeof(Stu_t));
			memset(s[i], 0, sizeof(Stu_t));
			strcpy(s[i-1]->name, s1->name);
			s[i-1]->age = s1->age;
		}
	}
	fclose(file);
	
	file = fopen("test.txt", "w");
	if(!file)
	{
		perror("fopen:");
		return;
	}
	for(int j=0; j<i; j++)
	{
		fwrite(s[j], 1, sizeof(Stu_t), file);
	}
	
	fclose(file);
	for(int j=0; j<i; j++)
	{
		free(s[j]);
	}
	free(s1);
	free(s);
}
void catch()
{
	FILE *file = fopen("test.txt", "r");
	if(!file)
	{
		perror("fopen:");
		return;
	}
	
	while(1)
	{
		Stu_t s;
		fread(&s, 1, sizeof(Stu_t), file);
		//fscanf(file,"name:%s\tage:%d\n",s.name,&s.age);
		if(feof(file))
		{
			break;
		}
		printf("name:%s\tage:%d\n",s.name,s.age);
		
	}
	fclose(file);
}
void w_file(Stu_t *s)
{
	//printf("name:%s\tage:%d\n",s.name, s.age);
	FILE *file = fopen("test.txt", "a");
	if(!file)
	{	
		perror("fopen:");
		return;
	}
	//fprintf(file,"name:%s\tage:%d\n",s->name, s->age);
	int ret = fwrite(s, 1, sizeof(Stu_t), file);
	if(!ret)
	{
		perror("fwrite err");
		return;
	}
	fclose(file);	
}

void menu()
{
	printf("**************************\n");
	printf("* 1 ������Ϣ\n");
	printf("* 2 ��ѯ��Ϣ\n");
	printf("* 3 ɾ���û�\n");
	printf("* 4 �����Ļ\n");
	printf("* 5 �˳�����\n");
	printf("**************************\n");
}

