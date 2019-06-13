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
	//统计牌的情况
	for(i=0; i<n; i++)
	{
		b[i] = a[i]/10;
		c[i] = a[i]%10;
	}
	Sort(&b[0]);				
	
	//correct!		14:43	
	
	for(i=0; i<4; i++)		//统计相同数字的情况
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
		case 1:		//出现一次不相等ret[0],ret[1]
			if((ret[0]==2 && ret[1]==3) ||(ret[0]==3 && ret[1]==2))	//type4:type3+一个Pair
				*r = 4;
			else if((ret[0]==1 && ret[1]==4) ||(ret[0]==4 && ret[1]==1))//type5:四张一样的
				*r = 5;
			break;
		case 2:		//出现过两次不相等 ret[0],ret[1],ret[2]	1 1 3	2 2 1
			if((ret[0]==1&&ret[1]==1&&ret[2]==3) || (ret[0]==1&&ret[1]==3&&ret[2]==1) ||
				(ret[0]==3&&ret[1]==1&&ret[2]==1))	//type3:三张一样的牌	
				*r = 3;
			else if((ret[0]==1&&ret[1]==2&&ret[2]==2) || (ret[0]==2&&ret[1]==1&&ret[2]==2) ||
				(ret[0]==2&&ret[1]==2&&ret[2]==1))	//type2:两组Pair的牌
				*r = 2;
			break;
		case 3:	//出现过三次不相等 ret[0],ret[1],ret[2],ret(3) 1 1 1 2
			/*if((ret[0]==1&&ret[1]==1&&ret[2]==1&&ret[3]==2) || 
				(ret[0]==1&&ret[1]==1&&ret[2]==2&&ret[3]==1) ||
				(ret[0]==1&&ret[1]==2&&ret[2]==1&&ret[3]==1)
				(ret[0]==2&&ret[1]==1&&ret[2]==1&&ret[3]==2))*/	//type1:Pair:两张数字一样的牌	
				*r = 1;
				break;
		case 4:			//所有牌都不一样
			if((b[0]+1 == b[1]) && (b[1]+1 == b[2]) && (b[2]+1 == b[3]) 
				&& (b[3]+1 == b[4]))//type6:数字连续的五张，13，1，2，3，4也算Straight
				{
					if((c[0]== c[1]) && (c[1]== c[2]) && (c[2]== c[3]) 
						&& (c[3] == c[4]))	//type7:连续五张&&花色一样		Straight Flush
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