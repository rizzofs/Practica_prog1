#include <stdio.h>

/*Modificar el programa del ejercicio anterior para que la función calcule,
además del resultado de la suma, el de la resta y el del producto, y ponga
dichos cálculos en argumentos de entrada-salida pasados a la función. En
caso de finalización exitosa, la función deberá retornar cero*/

int resta(int a, int b);
int main()
{
    int a, b;
    printf("Ingrese dos numeros enteros: \n");
    scanf("%d %d", &a, &b);
    printf("La resta entre %d y %d es: %d", a, b, resta(a, b));
    return 0;
}
int resta(int a, int b)
{

    if (a >= 10 && a <= 99 && b >= 10 && b <= 99)
    {
        return a - b;
    }
    else
    {
        printf("Ingrese dos numeros enteros: ");
        scanf("%d %d", &a, &b);
        return a - b;
    }
}