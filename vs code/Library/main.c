#include<stdio.h>

FILE *fm, *ft, *fb;

void main()
{
    int ch, ch1, ch2, ch3;
    fm = fopen("member.dat", "a+");     //人
    ft = fopen("trans.dat", "a+");
    fb = fopen("book.dat", "a+");   //书

    mainscr();

    while(1)
    {
    bk:
    showmenu(mainmenu, 5, 10, 35);
    ch = getchoice(mainmenu, "MBRHE", 10, 35, 5)
    }
}
