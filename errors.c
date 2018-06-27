#include <stdio.h>

#include "errors.h"

/*diccioniario de errores*/
char * errors[MAX_ERRORS]=
{
        "OK",
        "Puntero nulo",
        "Argumentos inválidos",
        "Sin memoria",
        "No se pudo abrir el archivo",
        "No se pudo escribir el archivo",
        "El archivo está corrupto",
        "No se pudo renombrar el archivo",
        "No se pudo borrar el archivo",
        "Arreglo de cadenas inválido",
        "El registro no existe",
        "El registro está duplicado"
};

status_t print_errors(status_t st)
{
        fprintf(stderr,"%s",errors[st]);

        return st;
}
