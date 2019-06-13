#include<stdio.h>


void Add(int a[], int b[],int n, int m)
{
	int c[60] = {0};
	int i = 0;
	for(;n>=0&&m>=0;n--,m--)
	{
		c[i] +=a[n]+b[m];
		if(c[i]>10)		//如果和大于10，
		{
			c[i+1] = 1;		//下一位进一
			c[i] -= 10;		//该位减去10
		}
		i++;
	}
	if(n)
	{
		for(;n>=0;n--)
		{
			c[i] += a[n];
			i++;
		}
	}
	if(m)
	{
		for(;m>=0;m--)
		{
			c[i] += b[m];
			i++;
		}
	}
	int k;
	printf("和：");
	for(k = i-1; k>=0;k--)
	{
		printf("%d",c[k]);
	}
	printf("\n");
}

void Division(int a[], int b[],int n, int m)
{
	int c[60];
	int i = 0;
	if(a[0]>=b[0])
	{
		for(;n>=0,m>=0;n--,m--)
		{
			if(a[n]<b[m])
			{
				a[n]+=10;
				a[n-1]--;
				c[i] = a[n] - b[m];
			}
			else
			{
				c[i] = a[n]-b[m];
			}
			i++;
		}
		int k;
		if(n)
		{
			for(;n>=0;n--)
			{
				c[i] = a[n];
				n--;
				i++;
			}		
		}
		if(m)
		{
			for(;m>=0;m--)
			{
				c[i] = c[i]-b[m];
				c[i+1] = -1;
				m--;
				i++;
			}		
		}
		printf("差：");
		for(k=i-1; k>=0; k--)
		{
			printf("%d", c[k]);
		}
		printf("\n");	
	}
	else
	{
		for(;n>=0,m>=0;n--,m--)
		{
			if(a[n]>b[m])
			{
				b[m]+=10;
				b[m-1]--;
				c[i] = b[m] - a[n];
			}
			else
			{
				c[i] = b[m] - a[n];
			}
			i++;
		}
		int k;
		if(n)
		{
			for(;n>=0;n--)
			{
				c[i] -= a[n];
				c[i+1]--;
				n--;
				i++;
			}		
		}
		if(m)
		{
			for(;m>=0;m--)
			{
				c[i] = b[m];
				c[i+1] = -1;
				m--;
				i++;
			}		
		}
		printf("差：-");
		for(k=i-1; k>=0; k--)
		{
			printf("%d", c[k]);
		}
		printf("\n");	
	}
	
}
void Multiply(int a[], int b[],int n, int m)
{
	int c[60] = {0};		//12  12
	int i ;				//a[0]==1,	a[1]==2
	int k, j, count = 0;				//b[0]==1,  b[1]==2
	int time = 0;			//j = m==2		k = n==2
	for(k=n; k>=0; k--)
	{	
		i = time;
		for(j=m; j>=0; j--)				// 0 1 2 3 4 5 6 7 8
		{								//   1 2 3 4 5 6 7 8 9
			c[i] = c[i] + a[k]*b[j];			//     2 3 4 5 6 7 8 9 10....
			if(c[i]>=10)
			{
				c[i+1] += c[i]/10;
				c[i] = c[i]%10;
			}
			i++;
		}
		count = (count>i)?count:i;
		time++;
	}
	printf("count = %d\n",count);
	printf("积：");
	
	for(k=count-1; k>=0; k--)
	{
		printf("%d", c[k]);
	}
	printf("\n");	
}


int main()
{
	int a[60], b[60];
	int i = 0, j =0;
	while(1)
	{
		
		scanf("%d",&a[i]);
		if(a[i] > 10)
			break;
		i++;
	}
	i--;
	printf("请输入第二个数：\n");
	while(1)
	{
		
		scanf("%d",&b[j]);
		if(b[j] > 20)
			break;
		j++;
	}
	j--;
	
	int k;
	for(k=0; k<=i;k++)
	{
		printf("%d",a[k]);
	}
	printf("\n");
	printf("b[]=");
	for(k=0; k<=j;k++)
	{
		printf("%d",b[k]);
	}
	
	Add(&a[0],&b[0],i,j);
	Division(&a[0],&b[0],i,j);
	Multiply(&a[0],&b[0],i,j);

	return 0;
}