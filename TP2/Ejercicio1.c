#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define MAX 10
int productoEscalar(int v1[], int v2[]);

int main()
{
    int v1[MAX] = {};
    int v2[MAX] = {};
    productoEscalar(v1, v2);
}

int productoEscalar(int v1[], int v2[])
{
    int i = 0;
    srand(time(NULL));

    // CARGO LOS VECTORES CON NUMEROS ALEATORIOS DE 1 A 12
    for (i = 0; i < MAX; i++)
    {
        v1[i] = 1 + rand() % 12;
        v2[i] = 1 + rand() % 12;
    }

    // IMPRIMO LOS VECTORES
    printf("Vector 1: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", v1[i]);
    }
    printf("\n");
    printf("Vector 2: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", v2[i]);
    }
    printf("\n");

    // CALCULO EL PRODUCTO ESCALAR
    int producto = 0;
    for (i = 0; i < MAX; i++)
    {
        producto += v1[i] * v2[i];
    }
    printf("El producto escalar es: %d", producto);
}
