#include<stdio.h>
#include<math.h>

int MaxDivisor(int x, int y)  //最大公约数
{
	int max, min;
	int i;
	
	max = (x>y)?x:y;
	min = (x<y)?x:y;
	//printf("max = %d, min = %d\n", max, min);
	
	while(1){
		i = max -min;
		max = (min>i)?min:i;
		min = (min<i)?min:i;
		//printf("max = %d, min = %d\n", max, min);
		if(max == min)
			break;
	}
		
	return max;
	
}

void Plus(int a, int b, int c, int d)	//加	通分
{
	printf("testing: %d %d %d %d\n",a,b,c,d);
	
	if(a==0 || b==0 ||c==0 || d==0)
	{
		printf("ERROR\n");
		return;
	}
	int i = MaxDivisor(b, d);
	//printf("i = %d\n", i);		//i =1
	if(i == b && i == d)
	{
		a = a;
		c = c;
	}
	else if(i == b)
	{
		b = d;
		a = a*i;
	}
	else if(i == d)
	{
		d = b;
		c = c * i;
	}
	else{					//bd不是倍数关系，扩大倍数为：：b  d/i		d b/i
		int m = d/i;
		int n = b/i;
		a = a*m;
		b = b*m;
		c = c*n;
		d = d*n;
	}
	a = a+c;
	
	printf("testing: %d %d %d %d\n",a,b,c,d);
	
	if(a>b)
	{
		int k = a/b;
		
		if(a*b < 0 )
		{
			a = fabs(a);
			b = fabs(b);
			k = fabs(k);
			a =a - k*b;
			printf("-%d(%d/%d) \n", k, a , b);
		}
		else{
			a =a - k*b;
			printf("%d(%d/%d)\n", k,a,b);
		}
	}
	else{
		if(a*b < 0 )
		{
			a = fabs(a);
			b = fabs(b);
			printf("%d/%d\n", a, b);
		}
		else{
			printf("%d/%d\n", a,b);
		}
	}	
}
void Subtration(int a, int b, int c, int d)	//减
{
	if(a==0 || b==0 ||c==0 || d==0)
	{
		printf("ERROR\n");
		return;
	}
	int i = MaxDivisor(b, d);
	if(i == b && i == d)
	{
		a = a;
		c = c;
	}
	else if(i == b)
	{
		b = d;
		a = a*i;
	}
	else if(i == d)
	{
		d = b;
		c = c * i;
	}
	else{					//bd不是倍数关系，扩大倍数为：：b  d/i		d b/i
		int m = d/i;
		int n = b/i;
		a = a*m;
		b = b*m;
		c = c*n;
		d = d*n;
	}
	a = a-c;
	
	if(fabs(a)>fabs(b))
	{
		int k = a/b;
		
		if(a*b < 0 )
		{
			a = fabs(a);
			b = fabs(b);
			k = fabs(k);
			a = a - k*b;
			printf("-%d(%d/%d)\n", k, a , b);
		}
		else{
			a = a - k*b;
			printf("%d(%d/%d)\n", k,a,b);
		}
	}
	else{
		if(a*b < 0 )
		{
			a = fabs(a);
			b = fabs(b);
			printf("-%d/%d\n", a, b);
		}
		else{
			printf("%d/%d\n", a,b);
		}
	}
}
void Multiplication(int a, int b, int c, int d)	//乘
{
	if(a==0 || b==0 ||c==0 || d==0)
	{
		printf("ERROR\n");
		return;
	}
	a = a * c;
	b = b * d;
	int i = MaxDivisor(a, b);
	a = a/i;
	b = b/i;
	
	if(a>b)
	{
		int k = a/b;
		
		if(a*b < 0 )
		{
			a = fabs(a);
			b = fabs(b);
			k = fabs(k);
			a = a- k*b;
			printf("-%d(%d/%d)\n", k, a , b);
		}
		else{
			a = a- k*b;
			printf("%d(%d/%d)\n", k,a,b);
		}
	}
	else{
		if(a*b < 0 )
		{
			a = fabs(a);
			b = fabs(b);
			printf("%d/%d\n", a, b);
		}
		else{
			printf("%d/%d\n", a,b);
		}
	}
}
void Divition(int a, int b, int c, int d) //除  a/b  *  d/c
{
	if(a==0 || b==0 ||c==0 || d==0)
	{
		printf("ERROR\n");
		return;
	}
	int temp;
	temp = c;	c = d; 	d = temp;
	a = a * c;
	b = b * d;
	int i = MaxDivisor(a, b);
	a = a/i;
	b = b/i;
	
	if(a>b)
	{
		int k = a/b;
		if(a*b < 0 )
		{
			a = fabs(a);
			b = fabs(b);
			k = fabs(k);
			a = a- k*b;
			printf("-%d(%d/%d)\n", k, a , b);
		}
		else{
			a = a- k*b;
			printf("%d(%d/%d)\n", k,a,b);
		}
	}
	else{
		if(a*b < 0 )
		{
			a = fabs(a);
			b = fabs(b);
			printf("%d/%d\n", a, b);
		}
		else{
			printf("%d/%d\n", a,b);
		}
	}
}

int main()
{
	int a,b,c,d,e,f;
	
	scanf("%d/%d", &a, &b);
	scanf("%d/%d", &c, &d);
	scanf("%d/%d", &e, &f);
	
	printf("%d/%d,%d/%d,%d/%d\n",a,b,c,d,e,f);
	printf("\n");
	
	Plus(a,b,c,d);
	Subtration(a,b,c,d);
	Multiplication(a,b,c,d);
	Divition(a,b,c,d);
	
	printf("\n");
	
	Plus(a,b,e,f);
	Subtration(a,b,e,f);
	Multiplication(a,b,e,f);
	Divition(a,b,e,f);
	
	printf("\n");
	
	Plus(c,d,e,f);
	Subtration(c,d,e,f);
	Multiplication(c,d,e,f);
	Divition(c,d,e,f);
	
	printf("\n");

	return 0;
}

