#include "CSocketProtocol.h"

void set_cs(CS *cs, CSINITMEM cinit, CSSEND csend, CSRECV crecv, CSFREE cfree)
{
    cs->cinit = cinit;
    cs->csend = csend;
    cs->crecv = crecv;
    cs->cfree = cfree;
}