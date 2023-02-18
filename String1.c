/*
1) Leer un string por teclado y luego convertirlo a mayúsculas sin usar las
funciones de string.h (ayuda: piense en los códigos ASCII y el nro. 32)
*/

#include <stdio.h>

int main()
{
    char minus[100], mayus[100];
    int i=0;

    printf("Ingresar palabra en minuscula. Se devuelve en MAYUSCULA: \n");
    scanf("%s", minus); //Cuando es char --> No se usa &

        while(minus[i]!= '\0')
        {
            mayus[i]=minus[i]-32;
            i++;
        }

        printf("Palabra original: %s \n", minus);
        printf("Palabra en MAYUSCULA: %s \n", mayus);
        printf("La palabra tiene %d caracteres \n", i);

return 0;
}
