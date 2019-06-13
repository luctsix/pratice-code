#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int main()
{
    int a[5];
	int sum = 0, total;
	double ave, fc, bzc;

	for(int i = 0; i<5; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}

	ave = sum/5;
	for(int i = 0; i<5; i++)
	{
		total += (a[i]-ave)*(a[i]-ave);
	}
	fc = total/5;

	bzc = sqrt(fc);

	printf("平均值：%.2f\n", ave);
	printf("方差：%.2f\n", fc);
	printf("标准差：%.2f\n", bzc);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int main()
{
    int a[5];
	int sum = 0, total;
	double ave, fc, bzc;

	for(int i = 0; i<5; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}

	ave = sum/5;
	for(int i = 0; i<5; i++)
	{
		total += (a[i]-ave)*(a[i]-ave);
	}
	fc = total/5;

	bzc = sqrt(fc);

	printf("平均值：%.2f\n", ave);
	printf("方差：%.2f\n", fc);
	printf("标准差：%.2f\n", bzc);

    return 0;
}
