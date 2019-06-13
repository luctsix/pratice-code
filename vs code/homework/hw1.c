#include<stdio.h>
#include<stdlib.h>

typedef struct Student{
    char name[50];
    unsigned int age;
    int score;
}Student;

void BubbleSort(Student *s, int n)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(s[j].age>s[j+1].age) //比较年龄
            {
                Student tmp = s[j];     //直接交换整个结构体
                s[j] = s[j+1];
                s[j+1] = tmp;
            }
            else if(s[j].age == s[j+1].age) //如果年龄相同
            {
                if(s[j].score>s[j+1].score) //比较分数
                {
                    Student tmp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = tmp;
                }
            }
        }
    }
}

int main()
{
    Student s[5] = {
        {"老大", 50, 59},
        {"老四", 20, 90},
        {"老二", 40, 60},
        {"老三", 40, 70},
        {"老幺", 18, 99}
    };

    BubbleSort(s, 5);

    printf("排名如下：\n");
    for(int i=0; i<5; i++)
        printf("%s\n", s[i].name);

    return 0;
}