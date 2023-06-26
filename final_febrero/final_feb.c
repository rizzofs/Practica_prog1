#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct
{
    int mes; //(2-12)
    int legajo;
    char nombre_alumno[20];
    float promedio;
    int cod_carrera;
} t_termino;

typedef struct
{
    int mes; //(2-12);
    int cant_graduados;
} t_grad_mes;

typedef struct
{
    int cod_carrera;
    char nombre_carrera[20];
    int cant_total_grad;

} t_carreras;

void proceso()
{
    FILE *arch1, *arch2, *arch3;

    arch1 = fopen("termino.txt", "r");
    arch2 = fopen("grad_mes.dat", "rw");
    arch3 = fopen("carreras.dat", "rw");

    t_termino termino;
    t_grad_mes graduados_mes;
    t_carreras carreras;

    // Variables de los archivos
    int mes, legajo, cod_carrera, cant_graduados, cant_total_grad;
    float promedio;
    char nombre_alumno[20], nombre_carrera[20];

    // Declaro vector para almacenar los meses
    int i;
    int meses[11];

    // Variables propias
    int cod_carrera_anterior, cant_grad_carrera, cant_grad_mes, clave;

    for (i = 2; i < 12; i++)
    {
        meses[i] = 0;
    }

    cant_grad_mes = 0;
    fscanf("%i %i %s %f %i", &mes, &legajo, &nombre_alumno, &promedio, &cod_carrera);
    while (!feof(arch1))
    {
        cod_carrera_anterior = cod_carrera;
        cant_grad_carrera = 0;
        while (!feof(arch1) && cod_carrera_anterior == cod_carrera)
        {
            cant_grad_carrera++;
            meses[mes]++;
            fscanf("%i %i %s %f %i", &mes, &legajo, &nombre_alumno, &promedio, &cod_carrera);
        }

        printf("\n >Carrera: %i", cod_carrera_anterior);
        printf("\n Total graduados: %i ", cant_grad_carrera);
        cant_grad_mes += cant_grad_carrera;

        // 2) Actualizar carreras.dat

        clave = cod_carrera_anterior;
        fseek(arch3, sizeof(t_carreras) * clave, SEEK_SET);
        fread(&carreras, sizeof(t_carreras), 1, arch3);
        carreras.cant_total_grad += cant_grad_carrera;
        fseek(arch3, sizeof(t_carreras) * clave, SEEK_CUR - 1);
        fwrite(&carreras, sizeof(t_carreras), 1, arch3);
    }

    printf("\n Total General de Graduados %i", cant_total_grad);

    //Actualizar GradMes
    for (i = 2; i < 12; i++)
    {
        fseek(arch2, sizeof(t_grad_mes)*i, SEEK_SET);
        fread(&graduados_mes, sizeof(t_grad_mes), 1, arch2);
        graduados_mes.cant_graduados += meses[i];
        fseek(arch2, sizeof(t_grad_mes)*i, SEEK_CUR - 1);
        fwrite(&graduados_mes, sizeof(t_grad_mes), 1, arch2);
    }
    
    fclose(arch1);
    fclose(arch2);
    fclose(arch3);
}

int main(){
    proceso();
}
