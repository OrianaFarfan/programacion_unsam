/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
5) Leer 5 strings por teclado y almacenarlos en un archivo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f;
    int i, n;
    char palabra[200];

    f = fopen("archivo.bin", "wb");
        if(f == NULL){
        printf("\nError al crear archivo\n");
        return 1;
        }

    for(i = 0; i < 5; i++)
    {
        printf("Ingrese la palabra numero %d:\n",i+1);
        scanf("%s", palabra);

        n = fwrite(palabra, sizeof(palabra), 1, f);

        if(n != 1){
            printf("\nError al grabar\n");
            fclose(f);
        return 2;
                  }
    }




    if(fclose(f) != 0){
        printf("\nError al cerrar\n");
        return 3;
    }




    printf("Fin del Programa..........\n");
    return 0;
}
