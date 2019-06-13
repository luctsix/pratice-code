#include<stdio.h>
#include<math.h>

int main()
{
	int num1, num2;
	double sum, diff, pro, quo;
	
	printf(" ‰»Î£∫\n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	
	sum = num1 + num2;
	diff = fabs(num1 - num2);
	pro = num1 * num2;
	quo = num1 / num2;
	
	printf("\n ‰≥ˆ£∫\n");
	printf("Sum:%.2f\n", sum);
	printf("Difference:%.2f\n", diff);
	printf("Product:%.2f\n", pro);
	printf("Quotinet:%.2f\n",quo);
	
	return 0;
	
	
}
