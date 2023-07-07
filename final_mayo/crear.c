#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int dia_mov;
    int cod_cab_mov;
    int cat_vehiculo_mov;
} t_movi;

typedef struct {
    int cod_cab_rec;
    float recauda_rec;
} t_recauda;

typedef struct {
    int cod_cat_pre;
    float precio_cat_pre;
} t_precios;

void crearArchivoMovi() {
    FILE *archivo;
    archivo = fopen("movi.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo movi.txt.\n");
        exit(1);
    }

    // Escribir datos en el archivo
    int i=1;
    while(i<365){
        int aleatorio = rand() % 3;
        //Numero aleatorio entre 1 y 25
        int cabina=rand() % 25 + 1;
        //Numero aleatorio entre 1 y 15
        int vehiculo=rand() % 15 + 1;
        fprintf(archivo, "%i %i %i\n",i,cabina,vehiculo);
        if(aleatorio == 1){
            i++;
        }
    }

    fclose(archivo);
}

void crearArchivoRecauda() {
    FILE *archivo;
    archivo = fopen("recauda.dat", "wb");
    if (archivo == NULL) {
        printf("Error al crear el archivo recauda.dat.\n");
        exit(1);
    }

    // Escribir datos en el archivo
    t_recauda recauda;
    recauda.cod_cab_rec = 1;
    recauda.recauda_rec = 0.0;
    fwrite(&recauda, sizeof(t_recauda), 1, archivo);

    recauda.cod_cab_rec = 2;
    recauda.recauda_rec = 0.0;
    fwrite(&recauda, sizeof(t_recauda), 1, archivo);

    fclose(archivo);
}

void crearArchivoPrecios() {
    FILE *archivo;
    archivo = fopen("precios.dat", "wb");
    if (archivo == NULL) {
        printf("Error al crear el archivo precios.dat.\n");
        exit(1);
    }

    // Escribir datos en el archivo
    int i=1;
    float precio;
    while(i<16){
        fwrite(&i, sizeof(int), 1, archivo);
        //Generar numero aleatorio en precio entre 1 y 1000
        precio = (rand() % 1000) + 1;
        fwrite(&precio, sizeof(float), 1, archivo);
        i++;
    }
}

int main() {
    crearArchivoMovi();
    crearArchivoRecauda();
    crearArchivoPrecios();

    printf("Archivos creados exitosamente.\n");

    return 0;
}
