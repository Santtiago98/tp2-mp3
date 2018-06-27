#include <stdio.h>

#include "main.h"
#include "errors.h"
#include "types.h"
#include "vector.h"
#include "mp3.h"
#include "utils.h"


int main(int argc, char * argv[])
{
    ADT_Vector_t * vector;
    ADT_Track_t  * track;
    FILE * fi;
    FILE * fo;
    status_t st;
    size_t format;
    size_t sort;
    size_t i;

    if((st = validate_arguments(argc, argv, &format, &sort)) != OK)
    {
        st=print_errors(st);
        return st;
    }
    if((st = ADT_Vector_new(&vector)) != OK)
        return st;
    if((st = ADT_Vector_set_destructor(vector, ADT_Track_delete)) != OK)
    {
        st=ADT_Vector_delete(&vector);
        return st;
    }
    if((st=ADT_Vector_set_comparator(vector,comparators[sort]))!=OK)
    {
        st=ADT_Vector_delete(&vector);
        return st;
    };
    if((st=ADT_Vector_set_printer(vector,export_as[format]))!=OK)
    {
        st=ADT_Vector_delete(&vector);
        return st;
    };
    for (i = MIN_NUMBER_OF_ARGUMENTS; i < argc; i++)
    {
        if((fi = fopen(argv[i],"rb")) == NULL)
            return st;
        if ((st = ADT_Track_new_from_binary_file(fi, &track)) != OK)
        {
            fclose(fi);
            st=print_errors(st);
            ADT_Vector_delete(&vector);
            return st;
        }
        if((st = ADT_Vector_append(&vector, track)) != OK);
        {
            st=print_errors(st);
            ADT_Vector_delete(&vector);
            fclose(fi);
            return ERROR_OUT_OF_MEMORY;
        }
        fclose(fi);
    }
    if ((st = ADT_Vector_sort(vector)) != OK)
    {
        ADT_Vector_delete(&vector);
        st=print_errors(st);
        return st;
    }
    if((fo = fopen(argv[FO_POSITION], "wt")) == NULL)
    {
        ADT_Vector_delete(&vector);
        st=print_errors(st);
        return st;
    }
    if((st=ADT_Vector_print_to_file(fo,vector))!=OK)
    {
        ADT_Vector_delete(&vector);
        if(fclose(fo) == EOF)
        {
            return ERROR_DISK_SPACE;
        }
    }
    if(fclose(fo) == EOF)
    {
        ADT_Vector_delete(&vector);
        return ERROR_DISK_SPACE;
    }
    ADT_Vector_delete(&vector);

    return OK;
}

status_t validate_arguments(int argc, char ** argv, size_t * i, size_t * j)
{
    if(argv==NULL || i ==NULL || j==NULL)
        return ERROR_NULL_POINTER;
    if(argc <= MIN_NUMBER_OF_ARGUMENTS)
        return ERROR_INVALID_ARGUMENTS;
    if(strcmp(argv[FORMAT_FLAG_POS],FORMAT_FLAG))
        return ERROR_INVALID_ARGUMENTS;
    else{
        for (*i = 0; *i < MAX_FORMATS; (*i)++) {
            if (!strcmp(argv[FORMAT_POSITION], formats[*i]))
                break;
        }
        if (*i >= MAX_FORMATS)
            return ERROR_INVALID_ARGUMENTS;
    }
    if(strcmp(argv[SORT_FLAG_POSITION],SORT_FLAG))
        return ERROR_INVALID_ARGUMENTS;
    else{
        for(*j = 0; *j < MAX_SORTING_CRITERION; (*j)++)
        {
            if(!strcmp(argv[SORT_POSITION], sort_criterion[*j]))
                break;
        }
        if(*j >= MAX_SORTING_CRITERION)
            return ERROR_INVALID_ARGUMENTS;
    }
    if(strcmp(argv[FO_FLAG_POSITION],FO_FLAG))
        return ERROR_INVALID_ARGUMENTS;
    return OK;
}

