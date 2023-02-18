#include<stdio.h>
#include<string.h>


//Palabra mayor alfabeticamente --> que este mas a lo ultimo.
int main()
{
    char palabra[100], mayor[100]="a"; //Esta inicializada para comparar.
    int i=0, comp;



    for(i=0; i<5; i++)
    {
        printf("Ingrese la palabra n° %d:",i+1);
        scanf("%s", palabra);


        comp=strcmp(palabra, mayor); //si strcmp devuelve >0, palabra va despues en el diccionario

            if(comp>0)
            {
                strcpy(mayor, palabra); // (destino, origen)
            }
    }

    printf("La palabra mayor alfabeticamente es %s", mayor);
    printf("\n comp es: %d",comp);

return 0;
}
