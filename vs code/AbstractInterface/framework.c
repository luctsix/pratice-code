#include "framework.h"
#include "send_recv.h"
#include "sendrecv.c"

/*
void init_mem(void **p1);
void send_buf(void *p1, char *buf, int len);
void recv_buf(void *p1, char *buf, int *len);
void free_buf(void *p1);    
*/
void framework(CS *cs,  CSINITMEM cinit, CSSEND csend, CSRECV crecv, CSFREE cfree)
{
    set_cs(cs, cinit, csend, crecv, cfree);

    void *p;
    cs->cinit(&p);

    char s_buf[] = "hello";
    int  s_len = strlen(s_buf);

    cs->csend(p, s_buf, s_len);

    char r_buf[128] = "";
    int  r_len      = 0;
    cs->crecv(p, r_buf, &r_len);
    printf("recv = %s\n", r_buf);

    cs->cfree(p);
}