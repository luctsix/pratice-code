#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, c;
	float x1, x2;
	
	printf("Input\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a);
	x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a);
	
	printf("Output\n");
	printf("%.1f\n",x1);
	printf("%.1f\n",x2);
	
	return 0;
}