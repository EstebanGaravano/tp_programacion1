#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ESTRUCTURA DE AUTOS
typedef struct {
    char marca[50];
    char modelo[50];
    char combustible;
    int anio;
    float precio;
    bool disponible;
} Auto;

// FUNCION PARA CARGAR UN AUTO
Auto cargarAuto() {
    Auto a;
    int opcion;

    printf("\nIngrese la marca: ");
    gets(a.marca);

    printf("Ingrese el modelo: ");
    gets(a.modelo);

    printf("Ingrese combustible (N/D/E): ");
    scanf(" %c", &a.combustible);

    printf("Ingrese el anio: ");
    scanf("%d", &a.anio);

    printf("Ingrese el precio: ");
    scanf("%f", &a.precio);

    printf("Esta disponible? (1=Si / 0=No): ");
    scanf("%d", &opcion);

    while (opcion != 0 && opcion != 1) {
        printf("Error. Ingrese 1 o 0: ");
        scanf("%d", &opcion);
    }

    a.disponible = opcion == 1;

    getchar();

    return a;
}

// FUNCION PARA MOSTRAR UN AUTO
void mostrarAuto(Auto a) {
    printf("\n------------------------\n");
    printf("Marca: %s\n", a.marca);
    printf("Modelo: %s\n", a.modelo);
    printf("Combustible: %c\n", a.combustible);
    printf("Anio: %d\n", a.anio);
    printf("Precio: %.2f\n", a.precio);

    if (a.disponible == true) {
        printf("Disponible: Si\n");
    } else {
        printf("Disponible: No\n");
    }
}

// FUNCION PARA GUARDAR UN AUTO
void guardarAuto(Auto a) {
    FILE *archivo;

    archivo = fopen("autos.txt", "a");

    if (archivo == NULL) {
        printf("\nError al abrir el archivo.\n");
    } else {
        fprintf(archivo, "%s|%s|%c|%d|%.2f|%d\n",
                a.marca,
                a.modelo,
                a.combustible,
                a.anio,
                a.precio,
                a.disponible);

        fclose(archivo);

        printf("\nAuto guardado correctamente.\n");
    }
}

// OPCION 1: AGREGAR AUTO
void agregarAuto() {
    Auto a;

    a = cargarAuto();
    guardarAuto(a);
}

// OPCION 2: LISTAR TODOS LOS AUTOS
void listarAutos() {
    FILE *archivo;
    Auto a;
    int estado;
    int cantidad = 0;

    archivo = fopen("autos.txt", "r");

    if (archivo == NULL) {
        printf("\nNo existe el archivo.\n");
    } else {
        while (fscanf(archivo,
               " %49[^|]|%49[^|]|%c|%d|%f|%d",
               a.marca,
               a.modelo,
               &a.combustible,
               &a.anio,
               &a.precio,
               &estado) == 6) {

            a.disponible = estado == 1;

            mostrarAuto(a);
            cantidad++;
        }

        if (cantidad == 0) {
            printf("\nNo hay autos registrados.\n");
        }

        fclose(archivo);
    }
}

// OPCION 3: LISTAR AUTOS DISPONIBLES
void listarDisponibles() {
    FILE *archivo;
    Auto a;
    int estado;
    int cantidad = 0;

    archivo = fopen("autos.txt", "r");

    if (archivo == NULL) {
        printf("\nNo existe el archivo.\n");
    } else {
        while (fscanf(archivo,
               " %49[^|]|%49[^|]|%c|%d|%f|%d",
               a.marca,
               a.modelo,
               &a.combustible,
               &a.anio,
               &a.precio,
               &estado) == 6) {

            a.disponible = estado == 1;

            if (a.disponible == true) {
                mostrarAuto(a);
                cantidad++;
            }
        }

        if (cantidad == 0) {
            printf("\nNo hay autos disponibles.\n");
        }

        fclose(archivo);
    }
}

// OPCION 4: BUSCAR AUTO POR MODELO
void buscarAuto() {
    FILE *archivo;
    Auto a;
    char buscado[50];
    int estado;
    bool encontrado = false;

    printf("\nIngrese el modelo a buscar: ");
    gets(buscado);

    archivo = fopen("autos.txt", "r");

    if (archivo == NULL) {
        printf("\nNo existe el archivo.\n");
    } else {
        while (fscanf(archivo,
               " %49[^|]|%49[^|]|%c|%d|%f|%d",
               a.marca,
               a.modelo,
               &a.combustible,
               &a.anio,
               &a.precio,
               &estado) == 6) {

            a.disponible = estado == 1;

            if (strcmp(a.modelo, buscado) == 0) {
                mostrarAuto(a);
                encontrado = true;
            }
        }

        if (encontrado == false) {
            printf("\nNo se encontro el modelo.\n");
        }

        fclose(archivo);
    }
}

// OPCION 5: DIVIDIR ARCHIVOS
void dividirArchivo() {
    FILE *origen;
    FILE *disponibles;
    FILE *noDisponibles;
    Auto a;
    int estado;

    origen = fopen("autos.txt", "r");

    if (origen == NULL) {
        printf("\nNo existe el archivo de autos.\n");
    } else {
        disponibles = fopen("disponibles.txt", "w");
        noDisponibles = fopen("no_disponibles.txt", "w");

        if (disponibles == NULL || noDisponibles == NULL) {
            printf("\nError al crear los archivos.\n");
        } else {
            while (fscanf(origen,
                   " %49[^|]|%49[^|]|%c|%d|%f|%d",
                   a.marca,
                   a.modelo,
                   &a.combustible,
                   &a.anio,
                   &a.precio,
                   &estado) == 6) {

                a.disponible = estado == 1;

                if (a.disponible == true) {
                    fprintf(disponibles,
                            "%s|%s|%c|%d|%.2f|%d\n",
                            a.marca,
                            a.modelo,
                            a.combustible,
                            a.anio,
                            a.precio,
                            a.disponible);
                } else {
                    fprintf(noDisponibles,
                            "%s|%s|%c|%d|%.2f|%d\n",
                            a.marca,
                            a.modelo,
                            a.combustible,
                            a.anio,
                            a.precio,
                            a.disponible);
                }
            }

            printf("\nArchivos divididos correctamente.\n");
        }

        if (disponibles != NULL) {
            fclose(disponibles);
        }

        if (noDisponibles != NULL) {
            fclose(noDisponibles);
        }

        fclose(origen);
    }
}

// FUNCION PRINCIPAL
int main() {
    int opcion;

    do {
        printf("\n========== MENU AUTOS ==========\n");
        printf("1. Agregar auto\n");
        printf("2. Listar todos los autos\n");
        printf("3. Listar autos disponibles\n");
        printf("4. Buscar auto por modelo\n");
        printf("5. Dividir archivo\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                agregarAuto();
                break;

            case 2:
                listarAutos();
                break;

            case 3:
                listarDisponibles();
                break;

            case 4:
                buscarAuto();
                break;

            case 5:
                dividirArchivo();
                break;

            case 6:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nOpcion incorrecta.\n");
        }

    } while (opcion != 6);

    return 0;
}
