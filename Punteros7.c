/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
7. Suponga que primero, ultimo y medio son punteros del mismo tipo y
primero y ultimo apuntan al primer y último elemento de un vector. Si quiere
que medio apunte al elemento que está en la mitad del vector ¿por qué la siguiente
instrucción es inválida y cómo se podría solucionar?
medio = (primero + ultimo) / 2
*/
#include <stdio.h>
#include<stdlib.h>
int main()
{   //posiciones 0  1  2   3   4   5  6    7
    int a [8]= {5, 15, 34, 54, 14, 2, 52, 72};
    int *primero,*medio,*ultimo;

    primero= &a[0]; //le asigno la direccion del primer elemento del vector
    ultimo = &a[7]; //le asigno la direccion del ultimo elemento del vector
    medio = &a[ ( (ultimo - primero )/ 2 ) ]; //hace la diferencia de posiciones de memoria --> (7-0)/2 --> 3

    printf("\na. ¿Cuál es el valor de MEDIO ?\n");
    printf("\nRESPUESTA: %d\n",*medio);
    printf("\n\nFin del Programa\n");

    return 0;
}
