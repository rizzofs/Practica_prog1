#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod_cab_rec;
    float recauda_rec;
} t_recauda;

typedef struct {
    int cod_cat_pre;
    float precio_cat_pre;
} t_precios;

void imprimirArchivoRecauda() {
    FILE *archivo;
    archivo = fopen("recauda.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo recauda.dat.\n");
        exit(1);
    }

    // Imprimir los datos del archivo
    t_recauda recauda;
    while (fread(&recauda, sizeof(t_recauda), 1, archivo) == 1) {
        printf("Código de cabina: %d\n", recauda.cod_cab_rec);
        printf("Recaudación acumulada: %.2f\n", recauda.recauda_rec);
        printf("---------------------------\n");
    }

    fclose(archivo);
}

void imprimirArchivoPrecios() {
    FILE *archivo;
    archivo = fopen("precios.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo precios.dat.\n");
        exit(1);
    }

    // Imprimir los datos del archivo
    t_precios precios;
    while (fread(&precios, sizeof(t_precios), 1, archivo) == 1) {
        printf("Código de categoría: %d\n", precios.cod_cat_pre);
        printf("Precio: %.2f\n", precios.precio_cat_pre);
        printf("---------------------------\n");
    }

    fclose(archivo);
}

int main() {
    imprimirArchivoRecauda();
    imprimirArchivoPrecios();

    return 0;
}
