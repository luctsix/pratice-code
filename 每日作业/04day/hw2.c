#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 16

//结构体类型，每个导师有三个学生
typedef struct Teacher
{
	char *tName; //导师名字，需要动态分配空间
	char **stu;  //三个学生，需要动态分配空间，堆区数组
	int age;
}Teacher;

//在createTeacher中分配空间 teacher:n1  stu:n2
int createTeacher(Teacher **p/*out*/, int n1, int n2){
	Teacher *tmp = NULL;
	tmp = (Teacher*)malloc(n1*sizeof(Teacher));
	if(!tmp)	{return -1;}
	for(int i=0; i<n1; i++)
	{
		tmp[i].tName = (char*)malloc(N);
		if(!tmp[i].tName)	{return -1;}
		memset(tmp[i].tName, 0, N);
		
		tmp[i].stu = (char**)malloc(n2*sizeof(char*));
		if(!(tmp[i].stu))	{return -1;}
		for(int j=0; j<n2; j++)
		{
			tmp[i].stu[j] = (char*)malloc(N);
			if(!tmp[i].stu[j])	{return -1;}
			memset(tmp[i].stu[j], 0, N);
		}		
	}
	*p = tmp;
	return 0;
}

//给成员赋值
void initTeacher(Teacher *p, int n1, int n2){
	for(int i=0; i<n1; i++)
	{
		char str[N] = {0};
		printf("please input the teacher[%d]'s name:", i);
		scanf("%s", str);
		getchar();
		strncpy(p->tName,str,sizeof(str));
		printf("please input the teacher[%d]'s age:", i);
		int n;
		scanf("%d", &n);
		p->age = n;
		
		for(int j=0; j<n2; j++)
		{
			char str2[N] = {0};
			printf("\t please input the teacher %s's student[%d]'s name:", str, j);
			scanf("%s", str2);
			strncpy(p->stu[j],str2,sizeof(str2));
		}
		p++;
	}
}

//打印结构体成员信息
void printTeacher(Teacher *p, int n1, int n2){
	for(int i=0; i<n1; i++)
	{
		printf("teacher[%d]:%s\n", i, p[i].tName);
		printf("\t teacher[%d] age: %d\n", i, p[i].age);

		for(int j=0; j<n2; j++)
		{
			printf("\t student[%d] name:%s\n", j, p[i].stu[j]);
		}
	}
}

//根据导师名字排序, 降序
void sortTeacher(Teacher *p, int n){	
	int k = 0;
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			//printf("before swap:1p->name:%s\tq->tName:%s\n",p[i].tName,p[j].tName);
			//printf("before swap:*(p->stu) = %s, *(q->stu) = %s\n", p[i].stu[k],p[j].stu[k]);
			//printf("p=%p\tq=%p\n",p[i],p[j]);
			if(strcmp(p[i].tName, p[j].tName) < 0)
			{
				//swap(&p, &q);
				//static int cnt = 0;
				//printf("\n 这是第%d次swap\n", ++cnt);
				
				char str1[64];
				memset(str1,0,64);
				//printf("p->name:%s\tq->tName:%s\n",p[i].tName,p[j].tName);

				strcpy(str1,p[i].tName);		//	交换姓名
				strcpy(p[i].tName,p[j].tName);
				strcpy(p[j].tName,str1);
				//printf("swap: p->name:%s\tq->tName:%s\n",p[i].tName,p[j].tName);
				
				int n;					//交换年龄
				n =p[i].age;
				p[i].age = p[j].age;
				p[j].age = n;
				
				for(k=0; k<3; k++)		//交换学生
				{
					char str2[64];
					memset(str2, 0, 64);
					//printf("1.str2=%s\t*(p->stu)=%s\t*((*q)->stu)=%s\n",str2,p[i].stu[k],p[j].stu[k]);
					strcpy(str2,p[i].stu[k]);
					strcpy(p[i].stu[k],p[j].stu[k]);
					strcpy(p[j].stu[k],str2);
					//printf("2.str2=%s\t*(p->stu)=%s\t*((*q)->stu)=%s\n",str2,p[i].stu[k],p[j].stu[k]);
				}
				//printf("------------swap end---------------\n");
			}
			//printf("\n******i am cutting line***********\n");
		}
		//printf("-------------------\n");
	}
}

//释放空间，在函数内部把p赋值为NULL
void freeTeacher(Teacher **p, int n1, int n2){
	Teacher* tmp = *p;
	if(*p == NULL)	return;
	for(int i=0; i<n1; i++)
	{
		for(int j=0; j<n2; j++)
		{
			free(*(tmp->stu));
			(tmp->stu)++;
		}
		free(tmp->stu);
		free((tmp->tName));
		tmp++;
	}
	free(tmp);
	
	*p = NULL;
	//printf("testing...\n");
}

int main(void){
	int ret = 0;
	int n1 = 3; //导师个数
	int n2 = 3; //学生
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //给成员赋值

	//打印成员，排序前
	printf("排序前：\n");
	printTeacher(p, n1, n2);

	//根据导师名字排序, 降序
	sortTeacher(p, n1);
	
	//打印成员，排序后
	printf("\n排序后：\n");
	printTeacher(p, n1, n2);

	//释放空间，在函数内部把p赋值为NULL
	freeTeacher(&p, n1, n2);
	if(p)
	{
		printf("free err\n");
	}

	return 0;
}
