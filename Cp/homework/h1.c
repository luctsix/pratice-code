#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int a[4];
	int guess[4];
	int i, k = 0;
	int ret = 0;
	
	srand((unsigned int)time(NULL));
	
	for(i=0;i<4;i++)
	{
		
		a[i] = rand()%10;		
	}

	system("cls");
	while(k<8)
	{
		printf("��������µ�����:");
		scanf("%d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3]);
		for(i=0;i<4;i++)
		{
			
			if(a[i] < guess[i])
			{
				printf("��%d�����´��ˣ�\n", i+1);
				ret = 0;
			}
			else if(a[i] > guess[i])
			{
				printf("��%d������С�ˣ�\n", i+1);
				ret = 0;
			}	
			else
				ret++;
		}
		if(ret == 4)
		{
			printf("��ϲ��¶��ˣ�\n");
			break;
		}
		k++;
	}
	if(k == 8)
	{
		printf("Sorry! ���Ѿ����˰˴���\n");
	}
	
	return 0;
}