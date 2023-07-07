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

int main()
{
    int vector[10] = {1, 2, 3, 4, 5, 3, 7, 3, 9, 10};
    int i, j, k, contador = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (vector[i] == vector[j])
            {
                vector[j] = -1;
                contador++;
            }
        }
    }
    printf("El vector es: ");
    for (k = 0; k < 10; k++)
    {
        printf("%d ", vector[k]);
    }
    printf("\n");
    printf("El vector modificado es: ");
    for (k = 0; k < 10; k++)
    {
        if (vector[k] != -1)
        {
            printf("%d ", vector[k]);
        }
    }
    printf("\n");
    printf("Se modificaron %d veces", contador);
    return 0;
}

