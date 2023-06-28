#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define N 10
int desplazar_derecha(int v1[]);//prototipo de funcion

int main(){
    int v1[N]={1,2,3,4,5,6,7,8,9,10};
    desplazar_derecha(v1);
    return 0;
}

int desplazar_derecha(int v1[]){
    int aux;
    aux=v1[0];
    for(int i=0;i<N;i++){
        v1[i]=v1[i+1];
        v1[N]=aux;
    }
    //imprimo el vector desplazado

    for (int i=0;i<N;i++){
        printf("%d ",v1[i]);
    }
}
