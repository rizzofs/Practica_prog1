#include "../../Los_includes.h"

typedef struct {
    int dia;
    int cod_cab;//(1-25)
    int cat_vehiculo;//(1-15)
}t_movimientos;

typedef struct {
    int cod_cab_rec;//("1-25)
    float recauda_rec;
}t_recauda;

typedef struct {
    int cod_cat_pre;//(1-15)
    float precio_cat_pre;
}t_precios;

int main(){
    FILE *archivo_movimientos, *archivo_recauda, *archivo_precios;
    
    archivo_movimientos=fopen("movi.txt", "r");
    archivo_recauda=fopen("recauda.dat", "rb+");
    archivo_precios=fopen("precios.dat", "rb");

    t_movimientos movimientos;
    t_recauda recauda;
    t_precios precios;

    int dia, cod_cab, cat_vehiculo;

    //defino el vector

    float precios_cat[16];
    float recauda_cab[26];
    
    //Pongo todas las cabinas en 0
    for(int i=0; i<26; i++){
        recauda_cab[i]=0;
    }

    while(!feof(archivo_precios)){
        fread(&precios, sizeof(t_precios), 1, archivo_precios);//aca voy a guardar
        int i=precios.cod_cat_pre;
        precios_cat[i]=precios.precio_cat_pre;
    }

    fscanf(archivo_movimientos,"%i %i %i", &dia, &cod_cab, &cat_vehiculo);
    
    int dia_ant;
    float rec_total_dia,rec_total_anio=0;

    while(!feof(archivo_movimientos)){
        dia_ant=dia;
        int cant_veh=0;
        rec_total_dia=0;
        while(!feof(archivo_movimientos)&&(dia_ant==dia)){
            cant_veh++;
            rec_total_dia+=precios_cat[cat_vehiculo];
            recauda_cab[cod_cab]+=precios_cat[cat_vehiculo];
            fscanf(archivo_movimientos,"%i %i %i", &dia, &cod_cab, &cat_vehiculo);
        }

        rec_total_anio+=rec_total_dia;
        printf("La cantidad de vehiculos que pasaron por dia es %i\n", cant_veh);
        printf("La recauda por dia es %f\n", rec_total_dia);
    }
    for(int i=1; i<26; i++){
        printf("El total recuadado diariamente por la cabina %i, es %f\n", i, recauda_cab[i]/dia);
    }
    printf("La recauda total del anio es %f\n", rec_total_anio);

    int i= 1;
    while(i<=26){
        fseek(archivo_recauda, i*sizeof(t_recauda), SEEK_SET);
        fseek(archivo_recauda,sizeof(int),SEEK_CUR);
        fwrite(&recauda_cab[i], sizeof(float), 1, archivo_recauda);
        i++;
    }

    fclose(archivo_movimientos);
    fclose(archivo_recauda);
    fclose(archivo_precios);



}
