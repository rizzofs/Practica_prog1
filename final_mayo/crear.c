#include <stdio.h>
#include <stdlib.h>

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
    fprintf(archivo, "1 1 1\n");
    fprintf(archivo, "1 2 2\n");
    fprintf(archivo, "2 1 2\n");
    fprintf(archivo, "2 2 1\n");

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
    t_precios precios;
    precios.cod_cat_pre = 1;
    precios.precio_cat_pre = 10.0;
    fwrite(&precios, sizeof(t_precios), 1, archivo);

    precios.cod_cat_pre = 2;
    precios.precio_cat_pre = 15.0;
    fwrite(&precios, sizeof(t_precios), 1, archivo);

    fclose(archivo);
}

int main() {
    crearArchivoMovi();
    crearArchivoRecauda();
    crearArchivoPrecios();

    printf("Archivos creados exitosamente.\n");

    return 0;
}
