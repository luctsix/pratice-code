#include "framework.h"
#include "framework.c"
#include "CSocketProtocol.h"
#include "CSocketProtocol.c"

int main()
{
    CS *cs;
    framework(cs, init_mem, send_buf, recv_buf, free_buf);

    return 0;
}

