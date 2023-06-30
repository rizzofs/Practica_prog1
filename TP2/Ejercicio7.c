#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define TAM 10
/*Ingresa 1000 edades en un vector e indicar cual es 
la edad de mayor frecuencia(la que mas se repite)*/

int mayorFrecuencia(int v[]);

int main(){
    int v[TAM];
    int edad=mayorFrecuencia(v);
    printf("La edad de mayor frecuencia es: %d", edad);
    return 0;
}

int mayorFrecuencia(int v[]){
    int mayor=0, frecuencia=0, i;
    //CARGAR EDADES ALEATORIAMENTE ENTRE 1 Y 10
    srand(time(NULL));
    for(i=0; i<TAM; i++){
        v[i]=rand()%10+1;
    }    
    //MUESTRO EL VECTOR
    for(i=0; i<TAM; i++){
        printf("%d ", v[i]);
    }
    //BUSCO LA EDAD DE MAYOR FRECUENCIA
    for(i=0; i<TAM; i++){
        if(v[i]==mayor){
            frecuencia++;
            if(frecuencia>mayor){
                mayor=v[i];
                frecuencia=1;
            }
            else{
                mayor=v[i];
                frecuencia=1;
            }
        }
    }
}