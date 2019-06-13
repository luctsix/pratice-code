#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

//#define N 100 



void initMap()
{
    system("cls");
    printf("************************************************************************\n");
    printf("*       Can not quit while playing, using _ instates while wrong       *\n");
    printf("*   Press any key to start，count time once you press the first key !  *\n");
    printf("************************************************************************\n");
    _getch();
}

void Loadin(char *model, int n)
{
    memset(model, 0, n*sizeof(char));

    srand((unsigned int)time(NULL));
    
    int i = 0;
    while(i<n)
    {
       
        model[i] = rand()%26 +97;
        i++;
    }
    model[i-1] = 0;

    printf("%s\n", model);
}

void playingGame()
{
    int n = 0;
    printf("Please select the game's difficulty(10~100): ");
    scanf("%d", &n);
    char model[n];
    Loadin(model,n);

    while(1)
    {
        int i;
        char ch, judge;
        int count = 0;

        time_t time_start = time(NULL);
        for(i=0; i < n-1; i++)
        {
            ch = _getch();
            
            if(ch != model[i])
                printf("_");
            else{
                printf("%c", ch);
                count++;
            }                
        }
        time_t time_end = time(NULL);

        int t = time_end - time_start;
        printf("\n");
       
        printf("the time you have spend is %d s!\n", t);

        printf("Press Esc to quit, or press any else key to keep on playing...\n ");
        char a;
        a = _getch();
        //getchar();
        if(a == 27){
            break;}
            printf("\n");
        initMap();
        printf("Please select the game's difficulty(10~100): ");
        scanf("%d", &n);
        Loadin(model,n);
    }

}

int main()
{
    int i;

    initMap();
    
    playingGame();

    return 0;
}