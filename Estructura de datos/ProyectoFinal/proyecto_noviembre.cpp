#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 500
#define TITLE 150

/*
    Primera parte:
    Estructuras para las listas de las tarjetas
*/

typedef struct Cards{
    char title[TITLE];
    char description[MAX];
    char expiration_date[10];
    char status[MAX];
}Card;

typedef struct Lists{
    
}List;