#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void add(int n1,int d1,int n2,int d2,int *num, int *deno)
{
	int i, j;
	int max = (d1>d2)?d1:d2;
	int min = (d1<d2)?d1:d2;
	while(1)
	{
		i = max - min;
		max = (min>i)?min:i;
		min = (min<i)?min:i;
		if(max == min)
			break;
	}
	i = d1/max;
	j = d2/max;
	*num = n1*j + n2*i;
	*deno = d1*j ;	
}


void multiply(int n1,int d1,int n2,int d2,int *num, int *deno)
{
	*num = n1*n2;
	*deno = d1 *d2;	
	int i;
	int max = fabs((*num>*deno)?*num:*deno);
	int min = fabs((*num<*deno)?*num:*deno);
	while(1)
	{
		i = max - min;
		max = (min>i)?min:i;
		min = (min<i)?min:i;
		if(max == min)
			break;
	}
	*num = *num/max;
	*deno = *deno/max;	
}


int main()
{
	int n1,d1,n2,d2;
	int num, deno;
	
	scanf("%d/%d", &n1, &d1);
	getchar();
	scanf("%d/%d", &n2, &d2);
	
	if(n1==0 || n2==0 || d1==0 || d2==0)
	{
		printf("ERROR\n");
		printf("ERROR\n");
		return 1;		
	}
	
	add(n1,d1,n2,d2,&num, &deno);
	if(num*deno<0)
	{
		if(fabs(num)>fabs(deno))
		{
			int k = num/deno;
			num = fabs(num);
			deno = fabs(deno);
			k = fabs(k);
			num = num - k*deno;
			printf("-%d(%d/%d)\n", k,num, deno);
		}
		else
		{
			num = fabs(num);
			deno = fabs(deno);
			printf("-%d/%d\n", num, deno);
		}
	}
	else
	{
		if(num>deno)
		{
			int k = num/deno;
			num = num - k*deno;
			printf("%d(%d/%d)\n", k,num, deno);
		}
		else
		{
			printf("%d/%d\n", num, deno);
		}
	}
	
	multiply(n1,d1,n2,d2,&num, &deno);
	if(num*deno<0)
	{
		if(num>deno)
		{
			int k = num/deno;
			num = fabs(num);
			deno = fabs(deno);
			k = fabs(k);
			num = num - k*deno;
			printf("-%d(%d/%d)\n", k,num, deno);
		}
		else
		{
			num = fabs(num);
			deno = fabs(deno);
			printf("-%d/%d\n", num, deno);
		}
	}
	else
	{
		if(num>deno)
		{
			int k = num/deno;
			num = num - k*deno;
			printf("%d(%d/%d)\n", k,num, deno);
		}
		else
		{
			printf("%d/%d\n", num, deno);
		}
	}
	
	return 0;
}