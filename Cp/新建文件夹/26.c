#include<stdio.h>

static countA = 0;
static countB = 0;

void fun1(int *A, int *B)
{
	int k;
	*A = 0;
	countA = 0;
	printf("A:[]");
	printf("B:[");
	for(k=0; k<countB; k++)
		printf("%d,", B[k]);
	printf("]\n");
}
void fun2(int *A, int *B)
{
	int k;
	*B = 0;
	countB = 0;
	printf("B:[]");
	printf("A:[");
	for(k=0; k<countA; k++)
		printf("%d,", A[k]);
	printf("]\n");
	
}
void fun3(int *A, int *B, int n)
{
	int k;
	A[countA] = n;
	countA++;
	printf("A:[");
	for(k=0; k<countA; k++)
		printf("%d,", A[k]);
	printf("]");
	printf("B:[");
	for(k=0; k<countB; k++)
		printf("%d,", B[k]);
	printf("]\n");
}
void fun4(int *A, int *B, int n)
{
	int k;
	B[countB] = n;
	countB++;
	printf("A:[");
	for(k=0; k<countA; k++)
		printf("%d,", A[k]);
	printf("]");
	printf("B:[");
	for(k=0; k<countB; k++)
		printf("%d,", B[k]);
	printf("]\n");
}
void fun5(int *A, int *B, int n)
{
	int i,k;
	
	for(k=0; k<countA; k++)
	{
		if(A[k] == n)
		{
			for(i=k; k<countA; k++)
				A[k] = A[k+1];
			countA--;
			break;
		}
	}
	printf("A:[");
	for(k=0; k<countA; k++)
		printf("%d,", A[k]);
	printf("]");
	printf("B:[");
	for(k=0; k<countB; k++)
		printf("%d,", B[k]);
	printf("]\n");
}
void fun6(int *A, int *B, int n)
{
	int i,k;
	
	for(k=0; k<countB; k++)
	{
		if(B[k] == n)
		{
			for(i=k; k<countB; k++)
				B[k] = B[k+1];
			countB--;
			break;
		}
	}
	printf("A:[");
	for(k=0; k<countA; k++)
		printf("%d,", A[k]);
	printf("]");
	printf("B:[");
	for(k=0; k<countB; k++)
		printf("%d,", B[k]);
	printf("]\n");
}
void fun7(int *A, int *B)
{
	int i, k;
	printf("[");
	for(k=0; k<countA; k++)
		printf("%d,",A[k]);
	for(k=0; k<countB; k++)
	{
		for(i=0;i<countA;i++)
		{
			if(B[k] == A[i])
				continue;
		}
		printf("%d,", B[k]);
	}
	printf("]\n");
}
void fun8(int *A, int *B)
{
	int i, k;
	printf("[");
	for(k=0; k<countB; k++)
	{
		for(i=0;i<countA;i++)
		{
			if(B[k] == A[i])
				printf("%d,", B[k]);
		}
	}
	printf("]\n");
}
void fun9(int *A, int *B)
{
	int count=0;
	int i,k;
	
	for(i=0; i<countA; i++)
	{
		for(k=0; k<countB; k++)
		{
			if(A[i]==B[k])
				count++;
		}
	}
	if(count == countA)
		printf("1\n");
	else
		printf("0\n");
}

int main()
{
	int A[20], B[20];
	int i, j;
	
	while(1)
	{
		scanf("%d,%d", &i, &j);
		switch(i)
		{
			case 0:
				exit(0);
			case 1:
				fun1(&A[20], &B[20]);
				break;
			case 2:
				fun2(&A[20], &B[20]);
				break;
			case 3:
				fun3(&A[20], &B[20], j);
				break;
			case 4:
				fun4(&A[20], &B[20], j);
				break;
			case 5:
				fun5(&A[20], &B[20], j);
				break;
			case 6:
				fun6(&A[20], &B[20], j);
				break;
			case 7:
				fun7(&A[20], &B[20]);
				break;
			case 8:
				fun8(&A[20], &B[20]);
				break;
			case 9:
				fun9(&A[20], &B[20]);
				break;
			default:
				break;
		}
	}
	return 0;
}