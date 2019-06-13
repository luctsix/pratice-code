#include<stdio.h>

void BubbleSort(int *arr, int len)
{
	int i, j,temp;
	for(i=0;i<len;i++)
	{
		for(j=0; j<len-i-1; j++ )
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}

int main()
{
	int arr[] = {2,9,1,8,3,7,4,6,5,0};
	int n = sizeof(arr)/sizeof(*arr);
	int i;
	
	printf("≈≈–Ú«∞£∫");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	
	printf("\n");
	
	BubbleSort(arr, n);
	printf("≈≈–Ú∫Û£∫");

	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	
	printf("\n");
	
	return 0;
}