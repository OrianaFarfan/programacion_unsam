/*
4) Escribir una función que reciba las coordenadas de dos vectores en el plano y
devuelva las coordenadas del vector que resulta de componer ambos vectores
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define L 2
// en knoppix no me estaria funcionando las librerias math.h en otros compiladores si.

typedef struct{
    float x;
    float y;
    float resultado;
}distancia;//Aca se define el tipo de datos

int main()
{
    distancia v[L];
    int i;
    for(i=0;i<L;i++) {
        printf("Ingrese la coordenada X de su %d vector\n",i+1);
        scanf("%f",&v[i].x);

        printf("Ingrese la coordenada Y de su %d vector\n",i+1);
        scanf("%f",&v[i].y);
    }
    v[0].resultado=(v[1].x-v[0].x);
    v[1].resultado=(v[1].y-v[0].y);
    printf("La coordenada de su vector resultante es: (%.2f,%.2f) \n",v[0].resultado,v[1].resultado);

    printf("Fin del Programa..........\n");
    return 0;
}
