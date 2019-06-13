#include "../HEADERS/ui.h"
#include "../HEADERS/headers.h"


void Login_UI()       //打印登录输入用户名和密码界面
{
    system("cls");
    for(int i=0; i<=ROW; i++)
    {
        if(i==3)
        {
             printf("*         Please enter your USERNAME and PASSWORD           *");
        }
        else if(i == 5)
        {
             printf("*                 USERNAME:_ _ _ _ _ _                      *");

        }
        else if(i == 7)
        {
             printf("*                 PASSWORD:_ _ _ _ _ _                      *");

        }
        else
        {
            for(int j=0; j<=LINE; j++)
            {
                if(i==0 || i==ROW || j==0 || j==LINE)
                {
                    printf("*");
                } 
            
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("NOTE:You can press Esc to exit!\n");
}


void Register_UI()      //注册输入用户信息
{
    for(int i=0; i<=ROW; i++)
    {
        if(i == 2)
        {
            printf("*         Please fill the form with your infomation         *");
        }
        else if(i == 4)
        {
            printf("*         NAME:_ _ _ _ _ _   AGE:_ _     ISMARRIGE: _       *");
        }
        else if(i == 5)
        {
            printf("*         BIRTHDAY:_ _ _ _ _ _ _ _     CODE:_ _ _ _ _ _     *");                
        }
        else if(i == 6)
        {
            printf("*         TEL:_ _ _ _ _ _ _ _ _ _ _                         *");                
        }
        else if(i == 7)
        {
            printf("*         ID:_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _            *");
        }
        else if(i == 8)
        {
            printf("*         ADDR:_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _            *");
        }
        else
        {
            for(int j=0; j<=LINE; j++)
            {
                if(i==0 || i==ROW || j==0 || j==LINE)
                {
                    printf("*");
                }
            
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("NOTE1:please enter the 'Enter' key to finish your input!\n");
    printf("NOTE2:you can exit with press the key 'Esc'\n");
}

void Input_Per_Info(PerInfo *p)   //输入用户信息
{
    system("cls");
    show_cur();
    Register_UI();      //注册输入用户信息
    COORD coord;
    int i;
A:              //输入姓名
    i = 0;
    coord.X = 15;
    coord.Y = 4;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 15)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto A;
            }
        }
        if(ch == 13)
        {
            break;
        }
        if(ch ==27)
        {
            exit(0);
        }
        p->name[i++] = ch;
        putc(ch, stdout);
        coord.X += 2;
    }
B:              //年龄
    i = 0;
    coord.X = 33;
    coord.Y = 4;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 33)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto B;
            }
        }
        if(ch == 13)
        {
            break;
        }
        if(ch ==27)
        {
            exit(0);
        }
        p->age[i++] = ch;
        putc(ch, stdout);
        coord.X += 2;
    }
C:              //婚姻状态  0，1
    i = 0;
    coord.X = 52;
    coord.Y = 4;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 52)
            {
                coord.X--;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                putc('_', stdout); 
                //coord.X = *x -2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                continue;
            }
            else
            {
                goto C;
            }
        }
        if(ch == 13)
        {
            break;
        }
        if(ch ==27)
        {
            exit(0);
        }
        p->ismarry = ch;
        putc(ch, stdout);
        coord.X ++;
    }
D:              //出生日期
    i = 0;
    coord.X = 19;
    coord.Y = 5;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 19)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto D;
            }
        }
        if(ch == 13)
        {
            break;
        }
        if(ch ==27)
        {
            exit(0);
        }
        p->birthday[i++] = ch;
        putc(ch, stdout);
        coord.X += 2;
    }
E:              //邮编
    i = 0;         
    coord.X = 44;
    coord.Y = 5;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 44)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto E;
            }
        }
        if(ch == 13)
        {
            break;
        }
        if(ch ==27)
        {
            exit(0);
        }
        p->code[i++] = ch;
        putc(ch, stdout);
        coord.X += 2;
    }
F:              //电话号码
    i = 0;          
    coord.X = 14;
    coord.Y = 6;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 14)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto F;
            }
        }
        if(ch == 13)
        {
            break;
        }
        if(ch ==27)
        {
            exit(0);
        }
        p->tel[i++] = ch;
        putc(ch, stdout);
        coord.X += 2;
    }
G:              //ID
    i = 0;        
    coord.X = 13;
    coord.Y = 7;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 13)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto G;
            }
        }
        if(ch == 13)
        {
            break;
        }
        if(ch ==27)
        {
            exit(0);
        }
        p->idnum[i++] = ch;
        putc(ch, stdout);
        coord.X += 2;
    }
H:              //住址，籍贯
    i = 0;  
    coord.X = 15;
    coord.Y = 8;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 15)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto H;
            }
        }
        if(ch == 13)
        {
            break;
        }
        if(ch ==27)
        {
            exit(0);
        }
        p->addr[i++] = ch;
        putc(ch, stdout);
        coord.X += 2;
    }

    coord.X = 0;
    coord.Y = 14;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    // printf("name:%s\n", p->name);
    // printf("age:%s\n",p->age);
    // printf("%c", p->ismarry);
    // printf("bir:%s\n", p->birthday);
    // printf("code:%s\n", p->code);
    // printf("tel:%s\n", p->tel);
    // printf("ID:%s\n", p->idnum);
    // printf("adde:%s\n", p->addr);
    // _getch();

}

void Verify_Per_Info(PerInfo p)   //用户检查输入的信息是否有误
{
    // printf("name:%s\n", p.name);
    // printf("age:%s\n",p.age);
    // printf("%c", p.ismarry);
    // printf("bir:%s\n", p.birthday);
    // printf("code:%s\n", p.code);
    // printf("tel:%s\n", p.tel);
    // printf("ID:%s\n", p.idnum);
    // printf("adde:%s\n", p.addr);
    // _getch();
    system("cls");
    hide_cur();
    Register_UI();      //注册输入用户信息
    COORD coord;
    
    int i = 0;  //输入姓名
    coord.X = 15;
    coord.Y = 4;
    while(p.name[i])
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putc(p.name[i++], stdout);
        coord.X += 2;
    }

    i = 0;      //年龄
    coord.X = 33;
    coord.Y = 4;
    while(p.age[i])
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putc(p.age[i++], stdout);
        coord.X += 2;
    }

    i = 0;          //婚姻状态  0，1
    coord.X = 52;
    coord.Y = 4;
    // while(1)
    // {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putc(p.ismarry, stdout);
        coord.X += 2;
    // }

    i = 0;          //出生日期
    coord.X = 19;
    coord.Y = 5;
    while(p.birthday[i])
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putc(p.birthday[i++], stdout);
        coord.X += 2;
    }

    i = 0;          //邮编
    coord.X = 44;
    coord.Y = 5;
    while(p.code[i])
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putc(p.code[i++], stdout);
        coord.X += 2;
    }

    i = 0;          //电话号码
    coord.X = 14;
    coord.Y = 6;
    while(p.tel[i])
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putc(p.tel[i++], stdout);
        coord.X += 2;
    }

    i = 0;          //ID
    coord.X = 13;
    coord.Y = 7;
    while(p.idnum[i])
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putc(p.idnum[i++], stdout);
        coord.X += 2;
    }

    i = 0;         //住址，籍贯
    coord.X = 15;
    coord.Y = 8;
    while(p.addr[i])
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putc(p.addr[i++], stdout);
        coord.X += 2;
    }
}

void GenerateCardID(PerInfo *p)  
{   
    strncpy(p->card.account, "6227", 5);
    srand((unsigned int)time(NULL));
    int i;
    for(i=4; i<16; i++)
    {
        char n = rand()%10 +'0';
        p->card.account[i] = n;
    }
    p->card.account[i] = '\0';
}

void Register_Usr_UI()       //注册登录输入用户名和密码界面
{
    system("cls");
    for(int i=0; i<=ROW; i++)
    {
        if(i==3)
        {
             printf("*        Please setting your USERNAME and PASSWORD          *");
        }
        else if(i == 5)
        {
             printf("*                 USERNAME:_ _ _ _ _ _                      *");

        }
        else if(i == 7)
        {
             printf("*                 PASSWORD:_ _ _ _ _ _                      *");

        }
        else
        {
            for(int j=0; j<=LINE; j++)
            {
                if(i==0 || i==ROW || j==0 || j==LINE)
                {
                    printf("*");
                } 
            
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("NOTE:You can press Esc to exit!\n");
}

void Register_Usr_Pwd(PerInfo *p)        
{
    Register_Usr_UI();
    COORD coord;             //控制光标的变量
    
    show_cur();             //显示光标
    int i;
    int j;
A:
    i = 0; 
    coord.X = 27;           //设置光标位置
    coord.Y = 5;
    while(coord.X != 39)    
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   //设置光标位置到(28,5)
        char ch;
        ch = _getch();      //获取键盘输入
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 27)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto A;
            }
        }
        if(ch == 13)        //如果按Enter键则结束输入
        {
            break;
        }
        if(ch == 27)        //按Esc键退出程序
        {
            exit(0);
        }
        putc(ch,stdout);    //将输入的字符打印到屏幕上
        p->card.usr_name[i++] = ch;
        //getchar();
        coord.X += 2;
    }
B:
    j = 0;
    coord.X = 27;
    coord.Y = 7;
    while(coord.X != 39)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        char ch;
        ch = _getch();
        if(ch == 8)         //按退格键删除
        {
            if(coord.X > 27)
            {
                Del_char(&coord.X, &coord.Y);
                i--;
                coord.X += 2;
                continue;
            }
            else
            {
                 goto B;
            }
        }
        if(ch == 13)        //按Enter键停止输入
        {
            break;
        }
        if(ch == 27)        //按Esc键退出程序
        {
            exit(0);
        }
        putc('*',stdout);
        p->card.usr_pwd[j++] = ch;
        //getchar();
        coord.X += 2;
    }
    // coord.X = 0;
    // coord.Y = 13;
    // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    // printf("name = %s\n", usr_name);
    // printf("pwd = %s\n",usr_pwd);
    //_getch();
}
