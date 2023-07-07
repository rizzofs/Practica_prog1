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

int funcion(int vec[], int tam){
    int i, j, cont=0;
    for(i=0; i<tam; i++){
        for(j=i+1; j<tam; j++){
            if(vec[i]==vec[j]){
                vec[j]=-1;
                cont++;
            }
            else{
                continue;
            }
        }
        if(vec[i]==-1){
            continue;
            
}