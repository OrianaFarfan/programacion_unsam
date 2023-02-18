/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
5) Escribir una función que reciba 2 horas h1 y h2 (hora, minutos y segundos) y
devuelva la diferencia entre ambas (en horas, minutos y segundos). Se sabe que
h2 es posterior a h1.
*/
// sale un bus de error al final no se porque pero funciona
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// en knoppix no me estaria funcionando las librerias math.h en otros compiladores si.
typedef struct{
    int hora;
    int minutos;
    int segundos;
    int resultado;
}horario;//Aca se define el tipo de datos

int main()
{
    horario v[3];
    int i;

    for(i=0;i<2;i++) {
        printf("Ingrese el %d Horario \n",i+1);
        printf("Ingrese la hora\n");
        scanf("%d",&v[i].hora);
        printf("Ingrese los minutos\n");
        scanf("%d",&v[i].minutos);
        printf("Ingrese los segundos\n");
        scanf("%d",&v[i].segundos);
    }
    v[0].resultado=(v[0].hora * 3600) + (v[0].minutos * 60) + v[0].segundos;
    v[1].resultado=(v[1].hora * 3600 )+ (v[1].minutos * 60) + v[1].segundos;
    v[3].resultado=v[1].resultado-v[0].resultado;

    v[3].hora=(v[3].resultado / 3600);
    v[3].minutos=((v[3].resultado - v[3].hora * 3600) / 60);
    v[3].segundos=v[3].resultado - (v[3].hora * 3600 + v[3].minutos * 60);
    printf("La diferencia Horaria es: %02d:%02d:%02d\n",v[3].hora,v[3].minutos,v[3].segundos);

    printf("Fin del Programa..........\n");
    return 0;
}
