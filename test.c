#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#define DEFAULT_LINES 10

// Aqui se definen los modos en los que se puede ejecutar test.c
enum tModes{
    MODE_HEAD,
    MODE_TAIL,
    MODE_LONGLINES,
    ERR_NUM_PARAMS,
    ERR_FORMAT,
    ERR_FUNCTION
};

enum tModes check_params(int argc, char *argv[]);

int main(int argc, char *argv[]){

    int num_lines;

    if (argc == 3){
        num_lines = atoi(argv[2]);
    } else {
        num_lines = DEFAULT_LINES;
    }

    switch(check_params(argc, argv)){
        case MODE_HEAD:
            if (head(num_lines) != 0) return 1;
            return 0;
        case MODE_TAIL:
            if (tail(num_lines) != 0) return 1;
            return 0;
        case MODE_LONGLINES:
            if (longlines(num_lines) != 0) return 1;
            return 0;
        case ERR_NUM_PARAMS:
            fprintf(stderr, "ERROR: No se ha introducido un numero valido de parametros\n");
            return 1;
        case ERR_FORMAT:
            fprintf(stderr, "ERROR: El segundo argumento contiene un tipo de dato erronero (se esperaba un entero mayor que 0)\n");
            return 1;
        case ERR_FUNCTION:
            fprintf(stderr, "ERROR: No se ha detectado ninguna funcion\n");
            return 1;
        default:
            return 1;
    }
}

enum tModes check_params(int argc, char *argv[]){

    // Checkaa si hay algo mal con la llamada a la funcion
    if ( argc > 3 || argc == 1 ) return ERR_NUM_PARAMS;
    if ( argc == 3 && atoi(argv[2]) <= 0) return ERR_FORMAT;

    if (strcmp(argv[1], "-head") == 0) return MODE_HEAD;
    if (strcmp(argv[1], "-tail") == 0) return MODE_TAIL;
    if (strcmp(argv[1], "-longlines") == 0) return MODE_LONGLINES;

    return ERR_FUNCTION;
}