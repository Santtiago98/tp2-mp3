#ifndef ERRORS__H
#define ERRORS__H

#include <stdio.h>

#include "main.h"
#include "types.h"
#include "vector.h"
#include "mp3.h"
#include "utils.h"


#define MAX_ERRORS 25

typedef enum 
{
    OK,
    ERROR_NULL_POINTER,
    ERROR_INVALID_ARGUMENTS,
    ERROR_OUT_OF_MEMORY,
    ERROR_CANNOT_OPEN_FILE,
    ERROR_CANNOT_WRITE_FILE,
    ERROR_DISK_SPACE,
    ERROR_CORRUPTED_FILE,
    ERROR_CANNOT_RENAME_FILE,
    ERROR_CANNOT_REMOVE_FILE,
    ERROR_INVALID_STRING,
    ERROR_INEXISTENT_KEY,
    ERROR_DUPLICATED_PRODUCT
}status_t;

status_t print_errors(status_t st);

#endif
