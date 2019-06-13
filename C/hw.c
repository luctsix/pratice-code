#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[] = {5,100,32,45,21,67,32,68,41,99,13,71};
	int *p = a;
	
	//int n = sizeof(a)/sizeof(int);
	int temp;
	int max = *p;
	int max2 = *(p+1);
	//printf("max = %d, max2 = %d\n", max, max2);
	 
	int i = 0;
	//p += 2;
	//for(i=2; i<n; i++)
	for(p+=2; p!=NULL; p++)//for( p += 2; *p>1 && *p<101; p++) //该循环为什么跳不出来
	{
		printf("这是第%d遍循环\n", ++i);
		if(*p>max)
		{
			temp = max;
			max = *p;
			*p = temp;
		}
		if(*p>max2)
		{
			temp = max2;
			max2 = *p;
			*p = temp;
		}
		//p++;
	}
	
	max2 = max<max2?max:max2;
	printf("第二大的数为：%d\n", max2);
	
	return 0;
}