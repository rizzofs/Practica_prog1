
#include "../../Los_includes.h"
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
    t_precios precios[16];
    
    int dia, cod_cab, cat_vehiculo;

    int dia_anterior, canti,i,clave;//se agregan aparte

    float prom1,mejor_prom,suma_total,suma_dia;

    double prome[15], precio_cab[26];// se agregan aparte

    i=1;
    while(!feof(archi3)){
        fread(&precios[i].cod_cat_pre,sizeof(int),1,archi3);
        fread(&precios[i].precio_cat_pre,sizeof(float),1,archi3);
        i++;
    }
    fscanf(archi1,"%i %i %i",&dia,&cod_cab,&cat_vehiculo);
    while(!feof(archi1)){
        dia_anterior=dia;
        for(int i=1;i<=26;i++){
            precio_cab[i]=0;
        }
        suma_dia=0;
        canti=0;
        int i=1;
        while(!feof(archi1)&&dia==dia_anterior){
            suma_dia+=precios[cat_vehiculo].precio_cat_pre;
            precio_cab[cod_cab]+=precios[cat_vehiculo].precio_cat_pre;
            suma_total+=suma_dia;
            canti++;
            fscanf(archi1,"%i %i %i",&dia,&cod_cab,&cat_vehiculo);
        }
        printf("\nLos vehiculos que pasaron en el dia fueron: %i",canti);
        printf("\nEl monto recaudado en el dia %i es de %f",dia_anterior,suma_dia);
        for(int j=1;j<=26;j++){
            prom1+=precio_cab[j];
        }
        printf("\nEl promedio diario de las cabinas es de %f",prom1/26);
    }
    printf("\n\n\nEl promedio de recaudacion total es de %f",suma_total/i);
    printf("\n\n\n\n\n\n");
}

void main(){
    proceso();
    printf("\n\n\nCorrecto");
}