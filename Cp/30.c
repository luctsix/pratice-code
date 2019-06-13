#include<stdio.h>

void  Swap(int *i, int *j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

void BubbleSort(int a[], int n)
{
	int i;
	int j;
	int countB = 0;
	for(j=n-1; j>0; j--)
	{
		for(i = 0; i<j; i++)
		{
			if(a[i]>a[j])
			{
				Swap(&a[i],&a[j]);;
				countB++;
			}
		}
	}
	printf("BubbleSort changed times = %d\n", countB);
	int k;
	for(k = 0; k<n; k++)
	{
		printf("%d  ", a[k]);
	}
	printf("\n");
}

void InsertSort(int a[], int n)
{
	int i, j, k;
	int countI = 0;
	int temp;
	for(i = 1; i<n;i++)
	{
		j = i-1;
		 
	    while(a[i]<a[j] && j>=0)
		{
			j--;
		}
		temp = a[i];
		for(k=i;k>j+1;k--)
		{
			a[k] = a[k-1];
			countI++;
		}
		a[k] = temp;	
	}
	printf("InsertSort changed times = %d\n", countI);
	int si;
	for(si = 0; si<n; si++)
	{
		printf("%d  ", a[si]);
	}
	printf("\n");
}
void SeleteSort(int a[], int n)
{
	int i, j, k;				//		   k
	int temp;					//temp	   t
	int ret;
	int countS = 0;				//		0  1  2  3  4  5  6  7
	for(i = 0; i<=n-1; i++)		//		5  2  7  4  8  1  9  0	
	{							//1.	i  	             j
		temp = a[i];			//
		ret = 0;						//
		for(j=i+1; j<=n-1; j++)	//
		{						//
			if(temp > a[j])		//
			{					//
				temp = a[j];	//
				k = j;
				ret = 1;
			}
		}
		if(ret == 1)
		{
			Swap(&a[i], &a[k]);
			countS++;
		}
	}
	printf("SeleteSort changed times = %d\n", countS);
	int si;
	for(si = 0; si<n; si++)
	{
		printf("%d  ", a[si]);
	}
	printf("\n");
} 

int main()
{
	int a[20];
	int i = 0;
	
	while(1)
	{
		scanf("%d", &a[i]);
		if(a[i] == -999)
			break;
		i++;
	}
	
	int k;
	for(k = 0; k<i; k++)
	{
		printf("%d  ", a[k]);
	}
	printf("\n");
	
	BubbleSort(&a[0], i);
	InsertSort(&a[0], i);
	SeleteSort(&a[0], i);
	
	
	return 0;
}