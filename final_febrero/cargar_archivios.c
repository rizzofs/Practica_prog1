#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int mes; //(2-12)
    int legajo;
    char nombre_alumno[20];
    float promedio;
    int cod_carrera;
} t_termino;

typedef struct {
    int mes; //(2-12);
    int cant_graduados;
} t_grad_mes;

typedef struct {
    int cod_carrera;
    char nombre_carrera[20];
    int cant_total_grad;
} t_carreras;

void generarDatosAleatorios() {
    FILE* arch1, * arch2, * arch3;
    int i, mes, legajo, cod_carrera, cant_graduados, cant_total_grad;
    float promedio;
    char nombre_alumno[20], nombre_carrera[20];
    t_termino termino;
    t_grad_mes graduados_mes;
    t_carreras carreras;

    srand(time(NULL));

    arch1 = fopen("termino.txt", "w");
    arch2 = fopen("grad_mes.dat", "wb");
    arch3 = fopen("carreras.dat", "wb");

    if (arch1 == NULL || arch2 == NULL || arch3 == NULL) {
        printf("Error al abrir los archivos de salida.\n");
        exit(1);
    }

    for (i = 0; i < 100; i++) {
        mes = rand() % 11 + 2; // Mes entre 2 y 12
        legajo = i + 1;
        sprintf(nombre_alumno, "Alumno%d", i + 1);
        promedio = (float)(rand() % 301) / 10; // Promedio entre 0 y 30
        cod_carrera = rand() % 5 + 1; // Código de carrera entre 1 y 5

        fprintf(arch1, "%d %d %s %.1f %d\n", mes, legajo, nombre_alumno, promedio, cod_carrera);
    }

    for (i = 2; i < 12; i++) {
        graduados_mes.mes = i;
        graduados_mes.cant_graduados = rand() % 21; // Cantidad de graduados entre 0 y 20
        fwrite(&graduados_mes, sizeof(t_grad_mes), 1, arch2);
    }

    for (i = 1; i <= 5; i++) {
        carreras.cod_carrera = i;
        sprintf(carreras.nombre_carrera, "Carrera%d", i);
        cant_total_grad = rand() % 51 + 50; // Cantidad total de graduados entre 50 y 100
        carreras.cant_total_grad = cant_total_grad;
        fwrite(&carreras, sizeof(t_carreras), 1, arch3);
    }

    fclose(arch1);
    fclose(arch2);
    fclose(arch3);

    printf("Archivos generados con datos aleatorios.\n");
}

int main() {
    generarDatosAleatorios();
    return 0;
}
