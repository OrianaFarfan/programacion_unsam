/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
6) Leer los strings del archivo del ej. anterior y mostrarlos en pantalla.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f;
    int i=0, n;
    char palabra[200];

    f = fopen("archivo.bin", "rb");
        if(f == NULL)
            {
                printf("\nError al crear archivo\n");
                return 1;
            }

    n = fread(palabra, sizeof(palabra), 1, f); //Guardamos en palabra, con ese size, de a 1 de ese tamaño y desde f. Voy leyendo cada size palabra o sea 200 bytes.

    if(n != 1)
            {
                printf("\nError al leer\n");
                fclose(f);
                return 2;
            }

    while(n==1){
        printf("La palabra numero %d que se encuentra en el archivo es: %s\n",i+1,palabra);
        n = fread(palabra, sizeof(palabra), 1, f);
        i++;
    }

    if(fclose(f) != 0){
        printf("\nError al cerrar\n");
        return 3;
    }
    printf("Fin del Programa..........\n");
    return 0;
}
