#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int arr[3][4] = {0};	//������������ѧ�������ųɼ�
	int i, j;
	int sum[3] = {0};		//��¼ÿ��ѧ�����ܳɼ�
	
	for(i=0;i<3;i++)	//�ɼ�¼��
	{
		printf("�������%d��ѧ���ĳɼ�:\n", i+1);
		for(j = 0; j < 4; j++)
		{
			printf("�������%d�ſεĳɼ�:", j+1);
			scanf("%d", &arr[i][j]);

			sum[i] += arr[i][j];
		}
	}
	
	for(i = 0; i<3; i++)	//�ֺܷ�ƽ���ִ�ӡ
	{
		printf("��%d��ѧ�����ܳɼ�Ϊ%d\tƽ����Ϊ%.1lf\n", i+1, sum[i], sum[i]/4.0);
	}
	return 0;
}