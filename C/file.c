/****************************************
typedef struct
{	
short	 		level; //������"��"����"��"�ĳ̶�
unsigned 		flags; //�ļ�״̬��־
char			fd; //�ļ�������
unsigned char 	hold; //���޻���������ȡ�ַ�
short 			bsize; //�������Ĵ�С
unsigned char 	*buffer;//���ݻ�������λ��
unsigned 		ar; //ָ�룬��ǰ��ָ��
unsigned		istemp; //��ʱ�ļ���ָʾ��
short 			token; //������Ч�Եļ��
}FILE;
*****************************************/



#include<stdio.h>
//#include<file.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	FILE *file = NULL;
	
	//char 
	
	file = fopen("./test.txt","w");
	if(!file)
	{
		perror(open);
		return -1;
	}
	//fgets(, sizeof(),file);
	fprintf(file,"asdjlaskj");
	
	fclose(file);
	
	return 0;
	
}