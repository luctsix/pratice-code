#include<stdio.h>
#include<math.h>

int main()
{
	float x_[20], y_[20];
	int i = 0;
	double sum = 0;
	double a, b, Area;
	
	while(1)
	{
		scanf("%f,%f", &x_[i], &y_[i]);
		
		if(x_[i]==-999)
			break;
		i++;
	}
	i--;
	int k;
	for(k=1; k<=i;k++)
	{
		a = x_[k]+x_[k-1];
		b = y_[k]-y_[k-1];
		
		//printf("%d,%d\n", x_[k],y_[k]);
		sum = sum + a*b;
	}
	
	Area = fabs(sum)/2;
	
	printf("Area = %.1lf\n", Area);
	
	
	
	return 0;
}