#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

//#define N 100 



void initMap()		//初始化函数
{
    system("cls");
    printf("************************************************************************\n");
    printf("*       Can not quit while playing, using _ instates while wrong       *\n");
    printf("*   Press any key to start，count time once you press the first key !  *\n");
    printf("************************************************************************\n");
    _getch();
}

void Loadin(char *model, int n)			//生成随机字符串序列，n是所要生成字符串的长度
{
    memset(model, 0, n*sizeof(char));	//数组置零

    srand((unsigned int)time(NULL));	//随机数种子
    
    int i = 0;
    while(i<n)
    {
       
        model[i] = rand()%26 +97;		//生成随机数并将之转换成小写字母
        i++;
    }
    model[i-1] = 0;				//字符数组最后以为置零，防止输出越界

    printf("%s\n", model);		//打印字符串到屏幕
}

void playingGame()				//玩游戏函数
{
    int n = 0;
    printf("Please select the game's difficulty(10~100): ");
    scanf("%d", &n);		//输入n以确定要生成的字符串的长度
    char model[n];			
    Loadin(model,n);		//字符串生成和打印函数，传递数组名地址，函数中model数组改变后能通过地址传回

    while(1)				
    {
        int i;
        char ch, judge;
        int count = 0;
		
        time_t time_start = time(NULL);		//开始计时，获取当前系统时间并存到time_start变量中
        for(i=0; i < n-1; i++)				//循环对比输入的字符与model数组对应的元素
        {
            ch = _getch();					//或取键盘输入字符
            
            if(ch != model[i])				//判断
                printf("_");
            else{
                printf("%c", ch);
                count++;					//如果相等则累加，可用于计分和统计准确率，判断前置零
            }                
        }
        time_t time_end = time(NULL);		//结束计时，获取当前系统时间并存到time_end变量中

        int t = time_end - time_start;		//计算输入经过的时间
        printf("\n");
       
        printf("the time you have spend is %d s!\n", t);

		//判断是否要跳出循环，结束游戏
        printf("Press Esc to quit, or press any else key to keep on playing...\n ");
        char a;
        a = _getch();
		
        if(a == 27)		//Esc 键的ASCLL码是27
		{		
            break;
		}
		
        printf("\n");	//如果输入的不是Esc键，则循环继续往下走，开始下一轮游戏
        initMap();
        printf("Please select the game's difficulty(10~100): ");
        scanf("%d", &n);
        Loadin(model,n);
    }

}



int main()
{
    int i;

    initMap();		//初始化游戏界面
    
    playingGame();	//玩游戏函数调用

    return 0;
}