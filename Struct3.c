/*
3) Escribir una función que reciba las coordenadas cartesianas de 2 puntos en el
espacio y devuelva la distancia euclídea.
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
{   float dista;
    distancia v[L];
    int i;
    for(i=0;i<L;i++) {
        printf("Ingrese la coordenada X de su %d vector\n",i+1);
        scanf("%f",&v[i].x);

        printf("Ingrese la coordenada Y de su %d vector\n",i+1);
        scanf("%f",&v[i].y);
    }

    v[0].resultado=pow((v[1].x-v[0].x),2); // coordenada x de p0 y p1 --> diferencia elevado a la 2
    v[1].resultado=pow((v[1].y-v[0].y),2); //coordenada y de p0 y p1 --> diferencia elevado a la 2
    dista= sqrt(v[0].resultado+v[1].resultado);

    printf("La distancia euclidea es:%f \n",dista);

    printf("Fin del Programa..........\n");
    return 0;
}
