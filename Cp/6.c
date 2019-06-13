#include<stdio.h>

int main()
{
	unsigned int x, y ,z;
	float rx, ry, rz;
	int sum;
	
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	
	if(x <= 10){
		rx = 1.00;
	}else if(10<x<=20)
	{
		rx = 0.90;
	}else if(20<x<=30){
		rx = 0.85;
	}else {
		rx = 0.80;
	}
	
	if(y <= 10){
		rx = 1.00;
	}else if(10<y<=20)
	{
		ry = 0.95;
	}else if(20<y<=30){
		ry = 0.85;
	}else {
		ry = 0.80;
	}
	
	if(z <= 10){
		rz = 1.00;
	}else if(10<z<=20)
	{
		rz = 0.85;
	}else if(20<z<=30){
		rz = 0.80;
	}else {
		rz = 0.70;
	}
	
	sum = 380*x*rx + 1200*y*ry + 180*z*rz;
	
	printf("%d", sum);
	
	
	
	
	return 0;
}