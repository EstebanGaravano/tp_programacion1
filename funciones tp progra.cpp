#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char marca[50];
    char modelo[50];
    char combustible;
    int anio;
    double precio;
    bool disponible;
} Auto;

// LEER CADENA
void leerCadena(char cadena[], int tamanio) {
    fgets(cadena, tamanio, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

// LEER ENTERO
int leerEntero() {
    char linea[100];
    int numero;
    int valido = 0;

    while (!valido) {
        leerCadena(linea, 100);

        if (sscanf(linea, "%d", &numero) == 1) {
            valido = 1;
        } else {
            printf("Ingrese un numero entero valido: ");
        }
    }

    return numero;
}

// LEER DOUBLE
double leerDouble() {
    char linea[100];
    double numero;
    int valido = 0;

    while (!valido) {
        leerCadena(linea, 100);

        if (sscanf(linea, "%lf", &numero) == 1) {
            valido = 1;
        } else {
            printf("Ingrese un precio valido: ");
        }
    }

    return numero;
}
