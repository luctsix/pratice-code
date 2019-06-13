#include "../HEADERS/headers.h"
#include "../HEADERS/ui.h"
#include "../HEADERS/operaton.h"

#include "../UI/ui_1.c"
// #include "../UI/ui_2.c"
#include "../UI/ui_3.c"
#include "../UI/ui_4.c"

#include "usr_login.c"
#include "Loginverify.c"
#include "file_op.c"

void Operating()
{
    char usr_name[N] = {0};
    char usr_pwd[N] = {0};
    PerInfo p;
    memset(&p, 0 , sizeof(p));

    show_ui();
    char key = _getch();

    switch(key)
    {
        COORD coord;
        case '1':
            while(1)
            {
                Login_UI();       //打印登录输入用户名和密码界面
                Login(usr_name, usr_pwd);   //输入用户名密码
                // coord.X = 0;
                // coord.Y = 15;
                // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                // printf("usr_name:%s\nusr_pwd:%s\n",usr_name, usr_pwd);
                if(!LoginVerify(usr_name, usr_pwd))
                {
                    COORD coord;
                    coord.X = 0;
                    coord.Y = 15;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    printf("The usr_name or usr_pwd is wrong\n");
                    printf("Please reinput\n");
                    _getch();
                }
                else
                {
                    break;
                }
            }
            while(1)
            {
                selete_Card();        //登入成功后选择信用卡 or 储蓄卡进行操作
                char key4 = _getch();
                switch(key4)
                {
                    case '1':
                        Dep_Menu_UI();      //登录成功后储蓄卡的操作界面
                        break;
                    case '2':
                        Cred_Menu_UI();     //登录成功后信用卡的操作界面
                        break;
                    case '3':
                        exit(SUCCESS);
                }
            }
            break;
        case '2':
        system("cls");
            Input_Per_Info(&p);   //输入用户信息
            Verify_Per_Info(p);
            _getch();
            Register_Usr_Pwd(&p);
            GenerateCardID(&p);
            //printf("name = %s\npwd = %s\n", p.card.usr_name, p.card.usr_pwd);
            
            Record(&p);

            PerInfo p2;
            fRead(&p2);

            coord.X = 0;
            coord.Y = 17;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            
            printf("name:%s\n", p2.name);
            printf("age:%s\n",p2.age);
            printf("%c", p2.ismarry);
            printf("bir:%s\n", p2.birthday);
            printf("code:%s\n", p2.code);
            printf("tel:%s\n", p2.tel);
            printf("ID:%s\n", p2.idnum);
            printf("adde:%s\n\n", p2.addr);

            printf("usr_name:%s\n", p2.card.usr_name);
            printf("usr_pwd:%s\n", p2.card.usr_pwd);
            printf("account:%s\n", p2.card.account);

            _getch();
            break;
        case '3':
            break;
        default:
            break;
    }

}