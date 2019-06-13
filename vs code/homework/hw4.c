#include<stdio.h>
#include<stdlib.h>

void Bubblesort(int *a, int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main()
{
    FILE *file = fopen("HW3.txt", "r");
    if(!file)
    {
        perror("fopen err");
        return -1;
    }

    char *str;
    str = (char*)malloc(10);
    int a[1024];
    int b, i = 0;

    while(1)
    {
        fgets(str, sizeof(str), file);
        if(feof(file))
        {
            break;
        }
        sscanf(str, "%d", &a[i++]);
    }

    Bubblesort(a, 500);

    for(int n = 0; n<i; n++)
    {
        printf("%3d", a[n]);
        if(n%5 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}