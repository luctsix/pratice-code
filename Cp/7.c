#include<stdio.h>
#include<math.h>

int main()
{
	int vi, vo, vm, mi, mo;
	float _183, _383, _983;
	
	printf("Input: \n");
	scanf("%d", &vi);
	scanf("%d", &vo);
	scanf("%d", &vm);
	scanf("%d", &mi);
	scanf("%d", &mo);
	
	
	_183 = 0.08*vi+0.139*vo+0.135*vm+1.128*mi+1.483*mo;
	_383 = 0.07*vi+0.130*vo+0.121*vm+1.128*mi+1.483*mo;
	_983 = 0.06*vi+0.108*vo+0.101*vm+1.128*mi+1.483*mo;
	
	printf("%.3f\n", _183);
	printf("%.3f\n", _383);
	printf("%.3f\n", _983);
	
	
	if(_183<183.000)
	{
		_183 = 183.000;
	}
	if(_383 < 383.000)
	{
		_383 = 383.000;
	}
	if(_983 < 983.000)
	{
		_983 = 983.000;
	}
	
	printf("Output:\n");
	
	if(_183>_383)
	{
		if(_383>_983)
		{
			printf("983\n");
			printf("%.3f\n", _983);
		}
		else{
			printf("383\n");
			printf("%.3f\n", _383);
		}
	}
	else
	{
		if(_183>_983)
		{
			printf("983\n");
			printf("%.3f\n", _983);
		}
		else{
			printf("183\n");
		printf("%.3f\n", _183);
		}
	}
	
	
	
	
	
	return 0;
}