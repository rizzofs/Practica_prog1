#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#define MAX 10

int sumatoriaPosiciones_pares_impares(int v1[], int v2[]);//prototipo

int main(){
    int v1[MAX], v2[MAX];
    sumatoriaPosiciones_pares_impares(v1, v2);
    return 0;
}

int sumatoriaPosiciones_pares_impares(int v1[], int v2[]){
    //CARGO LOS VECTORES ALEATORIAMENTE
    srand(time(NULL));
    int i;

    for(i=0; i<MAX; i++){
        v1[i] =1 +  rand() % 1000;
        v2[i] =1 +  rand() % 1000;
    }

    //SUMO LOS VALORES PARES DEL VECTOR 1 Y LOS IMPARES DEL VECTOR 2

    int posicion_pares=0;
    int posicion_impares=0;
    for(i=0; i<MAX; i++){
        if(v1[i]%2 == 0){
            posicion_pares+=v1[i];
        }
        if(v2[i]%2 == 1){
            posicion_impares+=v2[i];
        }
    }
    printf("La sumatoria de los valores pares del vector 1 es: %d\n", posicion_pares);
    printf("La sumatoria de los valores impares del vector 2 es: %d\n", posicion_impares);
    printf("La sumatoria de los valores pares del vector 1 y las impares del vector 2 es: %d\n", posicion_pares+posicion_impares); 
}           

        

    

