#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char begin[16];
    char end[16];
    double hb, mb, sb;
    double he, me, se;
    double totle_h, totle_m, totle_s;

    scanf("%s", begin);
    scanf("%s", end);

    sscanf(begin, "%lf:%lf:%lf", &hb, &mb,&sb);
    sscanf(end, "%lf:%lf:%lf", &he, &me, &se);

    printf("hb=%ld, mb=%ld, sb=%ld,he=%ld, me=%ld, se=%ld\n",hb, mb, sb, he, me, se);

    totle_h = (he-hb-1) + (me+60-mb-1)/60.0 + (se+60-sb)/3600.0;
    printf("%d\n", totle_h/12.0*360.0);


    printf("begin:%s\nend:%s\n", begin, end);
    return 0;
}