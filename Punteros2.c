/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
A�o: 2020

2. Explicar qu� est� mal en el siguiente fragmento de c�digo:

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
