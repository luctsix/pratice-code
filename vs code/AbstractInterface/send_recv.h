#ifndef __SEND_RECV_H_
#define __SEND_RECV_H_

void init_mem(void **p1);
void send_buf(void *p1, char *buf, int len);
void recv_buf(void *p1, char *buf, int *len);
void free_buf(void *p1);

#endif