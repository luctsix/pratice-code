#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem{
    char    *buf;
    int     len;
}Elem;

void init_mem(void **p1)
{
    Elem *p = (Elem*)malloc(sizeof(Elem));
    if(!p)
    {
        return;
    }
    p->len = 0;
    p->buf = (char*)malloc(128); 
    memset(p->buf, 0, 128);
    *p1 = (void*)p;
}

void send_buf(void *p1, char *buf, int len)
{
    Elem* p = (Elem*)p1;
    strcpy(p->buf, buf);
    p->len = len;
}

void recv_buf(void *p1, char *buf, int *len)
{
    Elem *p = (Elem*)p1;
    strcpy(buf, p->buf);
    *len = p->len;
}

void free_buf(void *p1)
{
    Elem* p = (Elem*)p1;
    free(p->buf);
    free(p);
}

