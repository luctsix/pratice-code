#include<stdio.h>
#include<stdlib.h>

void f1(int x1, int y1, int x2, int y2, double *m, double *b )
{
	
	*m = floor((y1-y2)/(x1-x2)*100)/100;
	*b = floor((x2*y1-x1*y2)/(x2-x1)*100)/100;
}

void f2(int x1, int y1, int x2, int y2, int *m1, int *m2,int *b1, int *b2)
{
	*m1 = y1-y2;
	*m2 = x1-x2;
	*b1 = x2*y1-x1*y2;
	*b2 = x2-x1;	
}

int main()
{
	int x1, y1, x2, y2;
	double m, b;
	int m1, m2, b1, b2;
	
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	if(x1 == x2)
	{
		printf("x =%d\n",x1);
		printf("x =%d\n",x1);
		return 0;
	}	
	else if(y1 == y2)
	{
		printf("y =%d\n",y1);
		printf("y =%d\n",y1);
		return 0;
	}
	else if(x1==y1 && x2==y2)
	{
		printf("y = x\n");
		printf("y = x\n");
		return 0;
	}
	
	f1(x1,y1,x2,y2,&m,&b);
	f2(x1,y1,x2,y2,&m1,&m2,&b1,&b2);
	
	

	printf("y=%.2lfx+%.2lf\n",m, b);
	printf("y=%d/%dx+%d/%d\n",m1, m2 ,b1, b2);
	
	
	
	return 0;
}