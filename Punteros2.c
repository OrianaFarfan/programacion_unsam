/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020

2. Explicar qué está mal en el siguiente fragmento de código:

        char c = 'A';
        double *p = &c;

RESPUESTA:
El puntero no es de la misma naturaleza que el la direccion de memoria a donde esta
apuntando "C" de tipo char.
*/

#include <stdio.h>
int main()
{
    char c = 'A';
    double *p = &c;
    printf ("Hola Mundo");
    return 0;
}
