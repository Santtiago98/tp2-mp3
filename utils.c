#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "mp3.h"

void swap (void *a, void *b)
{
    void * aux;
///No se puede  poner el if ese que habia puesto antes pq son punteros void
    aux = a;
    a = b;
    b = aux;
}

int ADT_Track_compare_by_artist(const void *e1, const void *e2)
{
    ADT_Track_t *p1=(ADT_Track_t *)e1;
    ADT_Track_t *p2=(ADT_Track_t *)e2;

    return strcmp(p1->artist,p2->artist);
}

int ADT_Track_compare_by_genre(const void *e1, const void *e2)
{
    ADT_Track_t *p1=(ADT_Track_t *)e1;
    ADT_Track_t *p2=(ADT_Track_t *)e2;

    return strcmp(p1->genre,p2->genre);
}

int ADT_Track_compare_by_name(const void *e1, const void *e2)
{
    ADT_Track_t *p1=(ADT_Track_t *)e1;
    ADT_Track_t *p2=(ADT_Track_t *)e2;

    return strcmp(p1->tag,p2->tag);
}
