#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 16

//�ṹ�����ͣ�ÿ����ʦ������ѧ��
typedef struct Teacher
{
	char *tName; //��ʦ���֣���Ҫ��̬����ռ�
	char **stu;  //����ѧ������Ҫ��̬����ռ䣬��������
	int age;
}Teacher;

//��createTeacher�з���ռ� teacher:n1  stu:n2
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

//����Ա��ֵ
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

//��ӡ�ṹ���Ա��Ϣ
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

//���ݵ�ʦ��������, ����
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
				//printf("\n ���ǵ�%d��swap\n", ++cnt);
				
				char str1[64];
				memset(str1,0,64);
				//printf("p->name:%s\tq->tName:%s\n",p[i].tName,p[j].tName);

				strcpy(str1,p[i].tName);		//	��������
				strcpy(p[i].tName,p[j].tName);
				strcpy(p[j].tName,str1);
				//printf("swap: p->name:%s\tq->tName:%s\n",p[i].tName,p[j].tName);
				
				int n;					//��������
				n =p[i].age;
				p[i].age = p[j].age;
				p[j].age = n;
				
				for(k=0; k<3; k++)		//����ѧ��
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

//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
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
	int n1 = 3; //��ʦ����
	int n2 = 3; //ѧ��
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //����Ա��ֵ

	//��ӡ��Ա������ǰ
	printf("����ǰ��\n");
	printTeacher(p, n1, n2);

	//���ݵ�ʦ��������, ����
	sortTeacher(p, n1);
	
	//��ӡ��Ա�������
	printf("\n�����\n");
	printTeacher(p, n1, n2);

	//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
	freeTeacher(&p, n1, n2);
	if(p)
	{
		printf("free err\n");
	}

	return 0;
}
