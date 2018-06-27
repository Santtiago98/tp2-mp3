#include <stdio.h>
#include "utils.h"


void swap (void *a, void *b)
{
    void * aux;

    if(a==b)
        return;
    aux = a;
    a = b;
    b = aux;
}
