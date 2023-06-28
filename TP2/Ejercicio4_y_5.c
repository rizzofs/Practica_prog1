#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define MAX 50

int cantidad(int v[], int postivos, int Negativos, int ceros);
int mayorElementoVector(int v[]);
int main()
{
    int v[MAX], i, positivos = 0, Negativos = 0, ceros = 0;
    cantidad(v, positivos, Negativos, ceros);
    mayorElementoVector(v);
    return 0;
}

int cantidad(int v[], int positivos, int Negativos, int ceros)
{

    // CARGO EL VECTOR ALEATORIAMENTE CON NUMEROS ENTRE -100 Y 100
    int i;
    srand(time(NULL));
    for (i = 0; i < MAX; i++)
    {
        v[i] = rand() % 201 - 100;
        printf("%d ", v[i]);
    }
    // CALCULO LA CANTIDAD DE PARES, IMPARES Y CEROS
    for (i = 0; i < MAX; i++)
    {
        if (v[i] == 0)
        {
            ceros++;
        }
        if (v[i] < 0)
        {
            Negativos++;
        }
        if (v[i] > 0)
        {
            positivos++;
        }
    }
    // MUESTRO LOS RESULTADOS
    printf("\n");
    printf("La cantidad de positivos es: %d\n", positivos);
    printf("La cantidad de negativos es: %d\n", Negativos);
    printf("La cantidad de ceros es: %d\n", ceros);
}
int mayorElementoVector(int v[]){
    int i, mayor;
    mayor = v[0];
    for (i = 0; i < MAX; i++){
        if(v[i] > mayor){
            mayor = v[i];
        }
    }
    printf("\n");
    printf("El mayor elemento del vector es: %d", mayor);
}