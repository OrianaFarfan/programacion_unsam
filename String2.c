#include<stdio.h>

int main()
{
    char derecho[100], inverso[100];
    int i=0, tam=0;

    printf("Ingrese una palabra y se la va a mostrar invertida \n");
    scanf("%s",derecho);

        while(derecho[tam]!='\0')
        {
            tam++;
        }

//No se por que es <=tam pero sirve mejor asi. Supongo que por el caracter de fin de cadena
        for(i=0; i<=tam; i++)
        {
            inverso[i]=derecho[tam-1-i];

        }

        printf("palabra original: %s", derecho);
        printf("palabra invertida: %s", inverso);


return 0;

}
