#include <stdio.h>

/*Crear una función que reciba dos números enteros como parámetros,
realice la suma aritmética de ambos y retorne el resultado de la suma. Los
números que serán usados como parámetros de dicha función deben ser
ingresados por teclado en la función principal, y deben ser enteros en un
rango entre 10 y 99 (en el caso de que los números no estuviesen en dicho
rango, deben ser pedidos nuevamente al usuario). Además, la función
principal debe mostrar por pantalla el resultado de la función.
*/

int suma(int a, int b);
int main()
{
    int a, b;
    printf("Ingrese dos numeros enteros: \n");
    scanf("%d %d", &a, &b);
    printf("La suma es: %d", suma(a, b));
    return 0;
}
int suma(int a, int b)
{

    if (a >= 10 && a <= 99 && b >= 10 && b <= 99)
    {
        return a + b;
    }
    else
    {
        printf("Ingrese dos numeros enteros: ");
        scanf("%d %d", &a, &b);
        return a + b;
    }
}

                    