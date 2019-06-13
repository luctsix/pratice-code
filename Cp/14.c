#include<stdio.h>
#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15
int a[100];
static int count = 0;

void Transfer(int n, int m)
{
	int i = 0;
	while(n)
	{
		if(n%m>=10)
		{
			switch(n%m)
			{
				case 10:
					a[i] = 'A';
					break;
				case 11:
					a[i] = 'B';
					break;
				case 12:
					a[i] = 'C';
					break;
				case 13:
					a[i] = 'D';
					break;
				case 14:
					a[i] = 'E';
					break;
				case 15:
					a[i] = 'F';
					break;
				default:
					break;
			}
		}	
		else
			a[i] = n%m;			//a[0]
		n = n/m;		
		i++;
		count++;			//count == 1
	}
	/*i--
	for(j = 0; j<i; j++)
	{
		ret += a[j]*
	}
	*/
}



int main()
{
	int n, m ;
	
	
	
	printf("请输入所要转换的进制：");
	scanf("%d", &m);
	printf("请输入一个十进制整数：");
	scanf("%d", &n);
	
	Transfer(n,m);
	
	//int i = 0;
	while(count)
	{
		if(a[count-1]>=10)
			printf("%c", a[count-1]);
		else
			printf("%d", a[count-1]);
		//i++;
		count--;
	}
	printf("\n");
	
	
	//printf("Output:\n");
	//printf("转换后的%d进制数为: %d\n", k);
	
	
	
	
	
	
	return 0;
}