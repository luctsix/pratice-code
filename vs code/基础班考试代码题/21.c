#include<stdio.h>

int main()
{
    int sum;
    int arr[4][5] = {{ 5, 1, 4, 2, 3},
                     { 6, 7,11, 8, 5},
                     { 9,15,14,16,17},
                     {19,21,24,13,16}};

    //找最大值和最小值及其坐标
    int max = arr[0][0], min = arr[0][0];
    int max_i, max_j, min_i, min_j;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(arr[i][j]>max)
            {
                max = arr[i][j];
                max_i = i;
                max_j = j;
            }
            if(arr[i][j]<min)
            {
                min = arr[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }
    printf("最大的数为：%d,角标是(%d, %d)\n", max, max_i, max_j);
    printf("最小的数为：%d,角标是(%d, %d)\n", min, min_i, min_j);

    for(int i=0; i<4; i++)
    {   
        sum = 0;
        for(int j=0; j<5; j++)
        {
            sum += arr[i][j];
        }
        printf("第%d行的和为：%d\n", i+1, sum);
    }

    for(int i=0; i<5; i++)
    {   
        sum = 0;
        for(int j=0; j<4; j++)
        {
            sum += arr[j][i];
        }
        printf("第%d列的和为：%d\n", i+1, sum);
    }

    return 0;
}