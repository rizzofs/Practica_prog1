#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>

/*Realizar una funcion que determine si dos vectores cargados con
numeros naturales de igual cantidad de elementos son iguales.*/

bool vectoresIguales(int v1[], int v2[], int tam);

int main()
{
    int tam = 10;
    int v1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int v2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool iguales;
    iguales = vectoresIguales(v1, v2, tam);
    if (iguales==TRUE)
    {
        printf("Los vectores son iguales");
    }
    else
    {
        printf("Los vectores no son iguales");
    }

    return 0;
}

bool vectoresIguales(int v1[], int v2[], int tam)
{
    bool iguales = false;
    int i;
    for (i = 0; i < tam; i++)
    {
        if (v1[i] == v2[i])
        {
            iguales = true;

        }
        else{
            iguales = false;
        }
    }
    return iguales;
}
