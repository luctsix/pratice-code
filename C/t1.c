#include<stdio.h>

void my_sort(int *p, int len)
{
	int i, j;
	
	for(i=0; i<len; i++)
	{
		for(j = 0; j<len-i-1; j++)
		{
			if(p[j]>p[j+1])
			{
				int temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
	
}

int main()
{
	int arr[] = {1,5,3,7,9,0,2,6,4,8};
	
	int len = sizeof(arr)/sizeof(*arr);
	
	my_sort(arr, len);
	
	int i;
	for(i = 0; i< len; i++)
		printf("%d\t", arr[i]);
	
	printf("\n");
	
	return 0;
}