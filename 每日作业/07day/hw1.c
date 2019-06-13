/*有个莲花池里起初有一只莲花，每过一天莲花的数量就会翻一倍。
**假设莲花永远不凋谢，30天的时候莲花池全部长满了莲花, 
**请问第23天的莲花占莲花池的几分之几？*/

#include<stdio.h>

int fun(int n)
{
	if(n == 23)
		return 1;
	return 2*fun(n-1);
}
int main()
{
	int i = 30;
	
	int n = fun(i);
	
	printf("1 / %d\n", n);
	
	return 0;
}



