#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

/* Escribir una función que acepte como parámetro un vector que contiene
números positivos, que puede contener valores duplicados, y reemplace
cada elemento repetido por -1 (menos uno). El procedimiento debe
retornar el vector modificado y la cantidad de veces que fue modificado.
*/

int vectorRepetido(int vec[]);

int main(){
    int vec[10] = {1,2,3,4,3,6,3,8,9,10};
    int v2[10]={};

    printf("Vector Original: ");
    for(int i=0; i<10; i++){
        printf("%d ",vec[i]);
    }

    printf("\n");

    v2[10]=vectorRepetido(vec);
    int contador=0;
    printf("Vector Modificado: ");
    for(int i=0; i<10; i++){
        printf("%d ",v2[i]);
        if(v2[i]==-1){
            contador++;
        }
        
    }
    printf("\n");
    printf("Cantidad de veces que fue modificado: %d",contador);
    return 0;
}



int vectorRepetido(int vec[]){
    int vaux[10]={};

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(vec[i]==vec[j] && i!=j){
                vaux[i]=-1;
            }
            else{
                vaux[i]=vec[i];
            }
        }
    }
    return vaux[10];
}
