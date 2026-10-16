#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ARCHIVO "autos.txt"

// ESTRUCTURA
typedef struct {
    char marca[50];
    char modelo[50];
    char combustible;
    int anio;
    double precio;
    bool disponible;
} Auto;


