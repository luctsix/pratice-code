#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

typedef struct Time{
    int hour;
    int minute;
    int second;
}Time;


int main()
{
     while(1)
    {
        system("cls");
        Time t;
        time_t t0 = time(NULL);

        t.hour = t0 / 60 / 60 % 24 + 8;
        t.minute = t0 / 60 % 60;
        t.second = t0 % 60;
        //printf("%d\n", t0);
        //printf("%02d:%02d:%02d\n", t.hour, t.minute, t.second);

   
        printf("当前时间\n%2d:%2d:%2d\n",t.hour, t.minute, t.second);
        Sleep(1000);
        fflush(stdout);
    }

    return 0;
}
