#include<stdio.h>
/*
T = (h/2)(f(p) + f(q) + 2 f(xi)) ,
h = (q-p)/n，h 是 double。
計算 f(x) 的面積，到小數點第五位四捨五入。
*/

double f1(int a, int p, int q, int err)
{
	double ret;
	
	
	return ret;
}

double f1(int a, int p, int q, int err)
{
	double ret;
	
	
	return ret;
}

int main()
{
	int flag[10]={}, a[10], p[10], q[10], err[10];
	int i = 0;
	int k;
	double ret[10];
	
	while(1)
	{
		scanf("%d,%d,%d,%d,%d",&flag[i],&a[i],&p[i],&q[i],&err[i]);
		if(flag[i] == 0)
			break;
		i++;
	}
	for(k=0; k<=i; k++)
	{
		switch(flag[k])
		{
			case 1:
				ret[k] = f1(a[k],p[k],q[k],err[k]);
				break;
			case 2:
				ret[k] = f2(a[k],p[k],q[k],err[k]);
				break;
			default:
				break;
		}
	}
	
	for(k=0; k<=i; k++)
	{
		printf("%.5lf\n", ret[k]);
	}
	
	return 0;
}