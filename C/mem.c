#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

//#define N 100 



void initMap()		//��ʼ������
{
    system("cls");
    printf("************************************************************************\n");
    printf("*       Can not quit while playing, using _ instates while wrong       *\n");
    printf("*   Press any key to start��count time once you press the first key !  *\n");
    printf("************************************************************************\n");
    _getch();
}

void Loadin(char *model, int n)			//��������ַ������У�n����Ҫ�����ַ����ĳ���
{
    memset(model, 0, n*sizeof(char));	//��������

    srand((unsigned int)time(NULL));	//���������
    
    int i = 0;
    while(i<n)
    {
       
        model[i] = rand()%26 +97;		//�������������֮ת����Сд��ĸ
        i++;
    }
    model[i-1] = 0;				//�ַ����������Ϊ���㣬��ֹ���Խ��

    printf("%s\n", model);		//��ӡ�ַ�������Ļ
}

void playingGame()				//����Ϸ����
{
    int n = 0;
    printf("Please select the game's difficulty(10~100): ");
    scanf("%d", &n);		//����n��ȷ��Ҫ���ɵ��ַ����ĳ���
    char model[n];			
    Loadin(model,n);		//�ַ������ɺʹ�ӡ������������������ַ��������model����ı����ͨ����ַ����

    while(1)				
    {
        int i;
        char ch, judge;
        int count = 0;
		
        time_t time_start = time(NULL);		//��ʼ��ʱ����ȡ��ǰϵͳʱ�䲢�浽time_start������
        for(i=0; i < n-1; i++)				//ѭ���Ա�������ַ���model�����Ӧ��Ԫ��
        {
            ch = _getch();					//��ȡ���������ַ�
            
            if(ch != model[i])				//�ж�
                printf("_");
            else{
                printf("%c", ch);
                count++;					//���������ۼӣ������ڼƷֺ�ͳ��׼ȷ�ʣ��ж�ǰ����
            }                
        }
        time_t time_end = time(NULL);		//������ʱ����ȡ��ǰϵͳʱ�䲢�浽time_end������

        int t = time_end - time_start;		//�������뾭����ʱ��
        printf("\n");
       
        printf("the time you have spend is %d s!\n", t);

		//�ж��Ƿ�Ҫ����ѭ����������Ϸ
        printf("Press Esc to quit, or press any else key to keep on playing...\n ");
        char a;
        a = _getch();
		
        if(a == 27)		//Esc ����ASCLL����27
		{		
            break;
		}
		
        printf("\n");	//�������Ĳ���Esc������ѭ�����������ߣ���ʼ��һ����Ϸ
        initMap();
        printf("Please select the game's difficulty(10~100): ");
        scanf("%d", &n);
        Loadin(model,n);
    }

}



int main()
{
    int i;

    initMap();		//��ʼ����Ϸ����
    
    playingGame();	//����Ϸ��������

    return 0;
}