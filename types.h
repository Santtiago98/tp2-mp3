#ifndef TYPES__H
#define TYPES__h

#include <stdio.h>

#include "main.h"
#include "errors.h"
#include "vector.h"
#include "mp3.h"
#include "utils.h"

#define MAX_FORMATS 3
#define MAX_SORTING_CRITERION 3
#define MAX_OUTPUT_FORMAT 2

char * formats[MAX_FORMATS]=
        {
                "csv",
                "xml",
                "html"
        };

char * sort_criterion[MAX_SORTING_CRITERION] =
        {
                "title",
                "artist",
                "genre"
        };

int (*comparators[MAX_SORTING_CRITERION])(const void *,const void *)=
        {
                compare_by_title,
                compare_by_artist,
                compare_by_genre
        };

status_t (* export_as[MAX_FORMATS]) (FILE * fo, void * track)=
        {
                ADT_Track_print_to_csv,
                ADT_Track_print_to_xml,
                ADT_Track_print_to_html
        };

typedef status_t (* destructor_t) (void **);
typedef int (* comparator_t) (const void *, const void *);
typedef status_t (* printer_t) (FILE * fo, void * p);

#endif
