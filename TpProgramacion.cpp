//
// Created by Usuario on 2/10/2026.
//

#include "TpProgramacion.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 2

int menu(){
    int opcion;

    do{
        printf("\n========== MENU ==========\n");
        printf("1 - Listado de pagos en efectivo y promedio\n");
        printf("2 - Listado de pagos en credito y promedio\n");
        printf("3 - Fin\n");
        printf("==========================\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 3){
            printf("Error. Opcion invalida.\n");
        }

    } while (opcion < 1 || opcion > 3);

    return opcion;
}
bool validarMonto(double monto){
    bool valido = false;

    if (monto > 0)
    {
        valido = true;
    }

    return valido;
}
bool validarMedio(char medio){
    bool valido = false;

    if (medio == 'E' || medio == 'e' ||
        medio == 'C' || medio == 'c'){
        valido = true;
    }
    return valido;
}

double cargarMonto(){
    double monto;

    do{
        printf("Ingrese el monto: $");
        scanf("%lf", &monto);

        if (!validarMonto(monto)){
            printf("Error. El monto debe ser mayor a cero.\n");
        }

    } while (!validarMonto(monto));

    return monto;
}
char cargarMedio(){
    char medio;

    do{
        printf("Ingrese medio de pago (E = Efectivo / C = Credito): ");
        scanf(" %c", &medio);

        if (!validarMedio(medio)){
            printf("Error. Medio de pago invalido.\n");
        }

    } while (!validarMedio(medio));

    return medio;
}

void listarEfectivo(double montos[], char medios[]){
    int i;
    int cantidadEfectivo = 0;

    double sumaEfectivo = 0;
    double promedioEfectivo;

    printf("\n========== PAGOS EN EFECTIVO ==========\n");

    for (i = 0; i < MAX; i++){
        if (medios[i] == 'E' || medios[i] == 'e'){
            printf("Pago %d: $%.2lf\n", i + 1, montos[i]);

            sumaEfectivo = sumaEfectivo + montos[i];

            cantidadEfectivo++;
        }
    }

    if (cantidadEfectivo > 0){
        promedioEfectivo = sumaEfectivo / cantidadEfectivo;

        printf("\nPromedio de pagos en efectivo: $%.2lf\n",
               promedioEfectivo);
    }else{
    	printf("No hay pagos en efectivo.\n");
    }
}
void listarCredito(double montos[], char medios[]){
    int i;
    int cantidadCredito = 0;

    double sumaCredito = 0;
    double promedioCredito;

    printf("\n========== PAGOS EN CREDITO ==========\n");

    for (i = 0; i < MAX; i++){
        if (medios[i] == 'C' || medios[i] == 'c'){
            printf("Pago %d: $%.2lf\n", i + 1, montos[i]);

            sumaCredito = sumaCredito + montos[i];

            cantidadCredito++;
        }
    }

    if (cantidadCredito > 0){
        promedioCredito = sumaCredito / cantidadCredito;

        printf("\nPromedio de pagos en credito: $%.2lf\n",
               promedioCredito);
    }else{
        printf("No hay pagos en credito.\n");
    }
}

int main(){
    double montos[MAX];
    char medios[MAX];
    int opcion;

    int i;

    for (i = 0; i < MAX; i++){
        printf("\n========== COBRO %d ==========\n", i + 1);

        montos[i] = cargarMonto();
        medios[i] = cargarMedio();
    }

    do{
        opcion = menu();

        switch (opcion){
            case 1:
                listarEfectivo(montos, medios);
                break;

            case 2:
                listarCredito(montos, medios);
                break;

            case 3:
                printf("\nFin del programa.\n");
                break;
        }

    } while (opcion != 3);

    return 0;
}

