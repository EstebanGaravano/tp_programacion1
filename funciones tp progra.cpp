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

// LEER CARACTER
char leerCaracter() {
    char linea[100];
    leerCadena(linea, 100);
    return linea[0];
}

// CARGAR LOS DATOS DE UN AUTO
void cargarAuto(Auto *a) {
    int opcion;

    printf("\nIngrese la marca: ");
    leerCadena(a->marca, 50);

    printf("Ingrese el modelo: ");
    leerCadena(a->modelo, 50);

    printf("Ingrese el combustible (N/D/E): ");
    a->combustible = leerCaracter();

    printf("Ingrese el anio: ");
    a->anio = leerEntero();

    printf("Ingrese el precio: ");
    a->precio = leerDouble();

    printf("Esta disponible? (1: Si / 0: No): ");
    opcion = leerEntero();

    while (opcion != 0 && opcion != 1) {
        printf("Ingrese 1 para Si o 0 para No: ");
        opcion = leerEntero();
    }

    a->disponible = (opcion == 1);
}

// MOSTRAR UN AUTO
void mostrarAuto(Auto a) {
    printf("\n-----------------------------\n");
    printf("Marca: %s\n", a.marca);
    printf("Modelo: %s\n", a.modelo);
    printf("Combustible: %c\n", a.combustible);
    printf("Anio: %d\n", a.anio);
    printf("Precio: %.2f\n", a.precio);

    if (a.disponible) {
        printf("Disponible: Si\n");
    } else {
        printf("Disponible: No\n");
    }

    printf("-----------------------------\n");
}

// GUARDAR UN AUTO EN EL ARCHIVO
void guardarAuto(Auto a) {
    FILE *archivo;

    archivo = fopen(ARCHIVO, "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
    } else {
        fprintf(archivo, "%s|%s|%c|%d|%.2f|%d\n",
                a.marca, a.modelo, a.combustible,
                a.anio, a.precio, a.disponible);

        fclose(archivo);
        printf("\nAuto guardado correctamente.\n");
    }
}

// LISTAR TODOS LOS AUTOS
void listarAutos() {
    FILE *archivo;
    Auto a;
    char linea[250];
    int cantidad = 0;

    archivo = fopen(ARCHIVO, "r");

    if (archivo == NULL) {
        printf("\nNo se pudo abrir el archivo o aun no existe.\n");
    } else {
        while (fgets(linea, 250, archivo) != NULL) {
            if (sscanf(linea, "%49[^|]|%49[^|]|%c|%d|%lf|%d",
                       a.marca, a.modelo, &a.combustible,
                       &a.anio, &a.precio, (int *)&a.disponible) == 6) {
                mostrarAuto(a);
                cantidad++;
            }
        }

        if (cantidad == 0) {
            printf("\nNo hay autos registrados.\n");
        }

        fclose(archivo);
    }
}

// LISTAR AUTOS SEGUN UNA CONDICION
// Condicion: precio mayor a 30.000.000
void listarPorCondicion() {
    FILE *archivo;
    Auto a;
    char linea[250];
    int cantidad = 0;
    int disponible;

    archivo = fopen(ARCHIVO, "r");

    if (archivo == NULL) {
        printf("\nNo se pudo abrir el archivo.\n");
    } else {
        while (fgets(linea, 250, archivo) != NULL) {
            if (sscanf(linea, "%49[^|]|%49[^|]|%c|%d|%lf|%d",
                       a.marca, a.modelo, &a.combustible,
                       &a.anio, &a.precio, &disponible) == 6) {

                a.disponible = (disponible == 1);

                if (a.precio > 30000000) {
                    mostrarAuto(a);
                    cantidad++;
                }
            }
        }

        if (cantidad == 0) {
            printf("\nNo hay autos que cumplan la condicion.\n");
        }

        fclose(archivo);
    }
}
