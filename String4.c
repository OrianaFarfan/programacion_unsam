/*
4) Leer 5 strings por teclado y mostrar el de mayor longitud
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char palabra[200], mayor[200];
    int i=0,tam;

    for( i=0 ; i<5 ; i++)
    {
        printf("Ingrese la palabra numero %d:\n",i+1);
        scanf("%s", palabra);


        if ( strlen(palabra) > strlen(mayor) ) // comparo la longitud de las cadenas
            strcpy(mayor,palabra);//Copio la cadena palabra a mayor
    }
    printf ("La palabra con mayor caracteres es: %s\n",mayor);
    return 0;
}
