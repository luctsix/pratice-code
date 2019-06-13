#include<stdio.h>
#include<conio.h>
#include<string.h>

enum Pork {Black = 0, Red, Block, Flower};

void Sort(int *b)
{
	int i, j;
	for(i = 4;i > 0; i--)
	{
		for(j=0; j<i; j++)
		{
			if(b[j]>b[i])
			{
				int temp;
				temp = b[j];
				b[j] = b[i];
				b[i] = temp;
			}
				
		}
	}
	return;
}

void judge(int a[], int *r)
{
	int b[5];
	int c[5];
	int i, k = 0, n = 5;
	int count = 1, ret[5];
	//ͳ���Ƶ����
	for(i=0; i<n; i++)
	{
		b[i] = a[i]/10;
		c[i] = a[i]%10;
	}
	Sort(&b[0]);				
	
	//correct!		14:43	
	
	for(i=0; i<4; i++)		//ͳ����ͬ���ֵ����
	{
		if(b[i]==b[i+1]) //1 1 2 3 3
			count++;
		else{
			ret[k++] = count;
			count = 1;
		}
	}
	ret[k] = count;
	
	for(i =0; i<=k;i++)
	{
		printf("ret[%d]=%d  ",i, ret[i]);
	}
	printf("\n");
	printf("k = %d\n", k);
	
	//correct		14:47
	
	switch(k)
	{
		case 1:		//����һ�β����ret[0],ret[1]
			if((ret[0]==2 && ret[1]==3) ||(ret[0]==3 && ret[1]==2))	//type4:type3+һ��Pair
				*r = 4;
			else if((ret[0]==1 && ret[1]==4) ||(ret[0]==4 && ret[1]==1))//type5:����һ����
				*r = 5;
			break;
		case 2:		//���ֹ����β���� ret[0],ret[1],ret[2]	1 1 3	2 2 1
			if((ret[0]==1&&ret[1]==1&&ret[2]==3) || (ret[0]==1&&ret[1]==3&&ret[2]==1) ||
				(ret[0]==3&&ret[1]==1&&ret[2]==1))	//type3:����һ������	
				*r = 3;
			else if((ret[0]==1&&ret[1]==2&&ret[2]==2) || (ret[0]==2&&ret[1]==1&&ret[2]==2) ||
				(ret[0]==2&&ret[1]==2&&ret[2]==1))	//type2:����Pair����
				*r = 2;
			break;
		case 3:	//���ֹ����β���� ret[0],ret[1],ret[2],ret(3) 1 1 1 2
			/*if((ret[0]==1&&ret[1]==1&&ret[2]==1&&ret[3]==2) || 
				(ret[0]==1&&ret[1]==1&&ret[2]==2&&ret[3]==1) ||
				(ret[0]==1&&ret[1]==2&&ret[2]==1&&ret[3]==1)
				(ret[0]==2&&ret[1]==1&&ret[2]==1&&ret[3]==2))*/	//type1:Pair:��������һ������	
				*r = 1;
				break;
		case 4:			//�����ƶ���һ��
			if((b[0]+1 == b[1]) && (b[1]+1 == b[2]) && (b[2]+1 == b[3]) 
				&& (b[3]+1 == b[4]))//type6:�������������ţ�13��1��2��3��4Ҳ��Straight
				{
					if((c[0]== c[1]) && (c[1]== c[2]) && (c[2]== c[3]) 
						&& (c[3] == c[4]))	//type7:��������&&��ɫһ��		Straight Flush
						*r = 7;
					else
						*r = 6;
				}
			 else if(b[0]==1 && b[4]==13)
			 {
				 if((b[1]==2 && b[2]==11) || (b[2]==3 && b[3]==12) || (b[3]==4))
				 {
					 if((c[0] == c[1]) && (c[1] == c[2]) && (c[2] == c[3]) 
							&& (c[3] == c[4]))
						*r = 7;
					else
						*r = 6;
				 }
			 }
			 break;
		default:
			break;
	}	
	
	
	
}



int main()
{
	int data[5];
	int n;
	int r;
	
	scanf("%d %d %d %d %d", &data[0], &data[1],&data[2],&data[3],&data[4]);
	/*
	for(n=0; n<5; n++){
		
		printf("%d ", data[n]);
	}
	printf("\n");
	*/
	judge(&data[0], &r);
	
	printf("r = %d", r);
	
	return 0;
}

//page 27