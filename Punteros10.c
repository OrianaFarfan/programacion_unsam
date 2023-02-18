/*
10. Escriba un programa que permita al usuario ingresar valores enteros en una
matriz de 3x3 y luego imprima los elementos de la diagonal principal.
Usar notación aritmética de punteros (no subíndices []) para recorrer la matriz.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3],x,y,*p,i=0;
    p = &matriz[0][0]; //inicializo el puntero con la direccion del primer elemento de la matriz

    for(x = 0;x < 3;x++) // esto nos movera por las filas
        {
            for(y = 0;y < 3;y++) // esto nos movera por las columnas
                {
                    printf("Ingrese un valor para la posicion [%d][%d]\n",x+1,y+1); // nos imprimira por que columna y fila (coordenada) estamos
                    scanf("%d",(p+i)); // se asigna el valor a la matriz --> p estaba apuntando al primer elemento en un inicio --> esta en p+0 = p = &matriz[0][0]
                    i++;
                }
    }
    printf("Los valores de la diagonal principal son: [%d] [%d] [%d]\n",*(p+0),*(p+4),*(p+8));

    printf("\n\nFin del Programa\n");

return 0;
}
