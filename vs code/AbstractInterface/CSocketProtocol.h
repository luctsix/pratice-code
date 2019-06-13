#ifndef __CSOCKETPROTOCOL_H_
#define __CSOCKETPROTOCOL_H_

typedef void (*CSINITMEM)(void **p);
typedef void (*CSSEND)(void *p, char *send_buf, int send_len);
typedef void (*CSRECV)(void *p, char *recv_buf, int *recv_len);
typedef void (*CSFREE)(void *p);

typedef struct cs{
    CSINITMEM   cinit;
    CSSEND      csend;
    CSRECV      crecv;
    CSFREE      cfree;
}CS;

void set_cs(CS *cs, CSINITMEM cinit, CSSEND csend, CSRECV crecv, CSFREE cfree);

#endif

