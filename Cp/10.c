/*
�㷨������
	1.������԰���n����ÿ�鰸�����߶�����m
	2.��������ÿ��ĸ��߶ε���ֵ����a[]��b[]�ֱ�洢�߶����˵Ķ˵���ֵ
	3.����ÿ�������ĸ��ǳ��ȣ�ע���ظ��������⣬���ֱ����
	4.end
*/


#include<stdio.h>
#include<stdlib.h>

int getLen(int *a, int *b, int m)
{
	int j;
	for(j = 0; j<m; j++)
	{
		printf("a[%d]=%d  b[%d]=%d\n", j, a[j], j, b[j]);
	}
	int i = 1;
	int len = 0;
	
	len = b[0] - a[0]; // ��һ���߶εĳ���
	//printf("len = %d", len);
	
	 //�ж�ǰ�����߶ε�λ�ù�ϵ
	
	while(i<=m)
	{
		if(a[i]>b[i-1])
		{
			len = len + b[i]-a[i];
		}
		else{
			len = b[i] - a[0];
		}
		i++;
	}
	printf("%d\n", len);
	
	return len;
}

int main()
{
	int n, m;		//n����԰�������m���߶�
	int a[10], b[10];	//�ֱ���߶ε������˵�
	int l, k, i = 0, j = 1;
	int lenth[10];
	int len;
	
	printf("please input the group number: \n");
	scanf("%d", &n);
	
	printf("n = %d\n", n);
	for(l = 0; l<n; l++)
	{		
		scanf("%d", &m);	//��l ��������m���߶�
		for(k=0; k<m; k++)  //����m���߶εĶ˵���Ϣ
		{
			printf("please input the terminal point's info!\n");
			scanf("%d  %d", &a[k], &b[k]);
			//scanf("%d", &b[k]);
			//getch();
		}				//ÿ�鰸������󼴼��㳤�ȣ���������l���飬�������������
		//printf("a[0]=%d, b[0]=%d\n", a[0], b[0]);
		//lenth[i] = getLen(&a[10], &b[10], m);
		if(m == 1)
		{	
			lenth[l] = b[0] - a[0]; // ��һ���߶εĳ���
			continue;
		//printf("len = %d", len);
		}
		//�ж�ǰ�����߶ε�λ�ù�ϵ
		//printf("%d\n", len);
		else{			//  m>1
			len = b[0] - a[0];
			i = 1;
			while(i<m)							//ͷ�˵�	a  i-1  i
			{									//β�˵�    b  i-1  i
				if(a[i]>=b[i-1])
				{
					len = len + b[i]-a[i];
				}
				else if(b[i]>b[i-1]){		//a[i]<b[i-1]
					len = len+b[i] - b[i-1];
				}
				else if(b[i]<b[i-1])
				{
					len += 0;
				}
				i++;
			}
		}
		lenth[l] = len;
	}
	
	for(i = 0; i < n; i++)
	{
		printf("%d\n", lenth[i]);
	}
		
	return 0;	
}