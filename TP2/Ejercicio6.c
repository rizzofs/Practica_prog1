#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define TAM 50
#define COLUMNAS 10
#define FILAS 5

/*Imprimir y sumar los elementos que ocupan las posiciones 
impares de una tabla numerica de 50 elementos*/

int posiciones_impares(int tabla[COLUMNAS][FILAS]);

int main(){
    int tabla[COLUMNAS][FILAS];
    int suma=posiciones_impares(tabla);
    printf("La suma de los elementos que ocupan las posiciones impares es: %d", suma);
    return 0;
}

int posiciones_impares(int tabla[COLUMNAS][FILAS]){
    int i, j;
    srand(time(NULL));
    //CARGO LA MATRIZ
    for(i = 0; i < COLUMNAS; i++){
        for(j = 0; j < FILAS; j++){
            tabla[i][j] = rand() % 100;
        }
    }
    //IMPRIMO LA MATRIZ
    int suma = 0;
    for(i = 0; i < COLUMNAS; i++){
        for(j = 0; j < FILAS; j++){
            if(i % 2 != 0){
                suma += tabla[i][j];
            }
            printf("%5d ", tabla[i][j]);
        }
        printf("\n");
    }
    return suma;
}