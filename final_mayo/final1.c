#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct
{
    int dia;
    int cod_cab;
    int cat_vehiculo;
} t_movi;

typedef struct
{
    int cod_cab_rec;
    float recauda_rec;
} t_recuada;

typedef struct
{
    int cod_cat_pre;
    float precio_cat_pre;
} t_precios;

typedef struct
{
    int cod_cab_pro;
    float canti_pro;
} t_promedio;

void proceso(){
    FILE *archi1, *archi2, *archi3;

    archi1=fopen("Movi.txt","r");
    archi2=fopen("Recauda.dat","rw");
    archi3=fopen("Precios.dat","r");

    t_movi movi;
    t_recuada recauda;
    t_precios precios;
    
    int dia, cod_cab, cat_vehiculo;

    int dia_anterior, canti,i,clave;//se agregan aparte

    float prom1,mejor_prom,suma_total,suma_dia;

    double prome[15], precio_cab[25];// se agregan aparte


    fseek(archi3,sizeof(t_precios)*1,SEEK_SET);
    fread(&precios, sizeof(t_precios),1,archi3);

    while(!feof(archi3)){
        dia_anterior=dia;
        
    }
}
