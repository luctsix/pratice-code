#include<stdio.h>

int Ttriangle(int a, int b, int c)
{
	if(a+b<=c || a+c<=b || b+c<=a )
		return 0;
	if(a*a+b*b==c*c ||a*a+c*c==b*b ||b*b+c*c==a*a)
		return 1;
	if(a*a+b*b<c*c ||a*a+c*c<b*b ||b*b+c*c<a*a)
		return 2;
	if(a*a+b*b>c*c ||a*a+c*c>b*b ||b*b+c*c>a*a)
		return 3;
}

int main()
{
	int ret;
	int a, b, c;
	
	printf("Input:\n");
	scanf("%d  %d %d", &a, &b, &c);
	
	ret = Ttriangle(a, b, c);
	
	printf("Output:\n");
	switch(ret)
	{
		case 0:
			printf("Not Ttriangle\n");
			break;
		case 1:
			printf("Right Ttriangle\n");
			break;
		case 2:
			printf("Obtuse Ttriangle\n");
			break;
		case 3:
			printf("Acute Ttriangle\n");
			break;
		default:
			break;		
	}
	
	return 0;
}