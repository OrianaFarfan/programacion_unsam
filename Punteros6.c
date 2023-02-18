/*
6. Suponga que se ejecutan las siguientes instrucciones:

        int a = {5, 15, 34, 54, 14, 2, 52, 72};
        int *p = &a [1], *q = &a [5];

a. ¿Cuál es el valor de *(p+3)? //busca el valor que esta en p + 3
b. ¿Cuál es el valor de *(q-3)?
c. ¿Cuál es el valor de q-p?
d. ¿La condición p<q es verdadera o falsa?
e. ¿La condición *p<*q es verdadera o falsa?
*/

#include <stdio.h>
#include<stdlib.h>
int main()
    {//posiciones 0 1   2  3   4   5   6   7
    int a [8]= {5, 15, 34, 54, 14, 2, 52, 72};
    int *p,*q;
    p= &a[1];
    q = &a[5];
    printf("\na. ¿Cuál es el valor de *(p+3)?\n");
    printf("\nRESPUESTA: %d\n",*(p+3)); // valor 14

    printf("\nb. ¿Cuál es el valor de *(q-3)?\n");
    printf("\nRESPUESTA: %d\n",*(q-3)); // valor 34

    printf("\nc. ¿Cuál es el valor de q-p?\n");
    printf("\nRESPUESTA: %d\n",(q-p)); // hace la diferencia de las posiciones de memoria 4

    printf("\nd. ¿La condición p<q es verdadera o falsa?\n");
    if(p>q)
        printf("\nRESPUESTA: Verdadera\n");
    else
        printf("\nRESPUESTA: Falsa\n");
        printf("\ne. ¿La condición *p<*q es verdadera o falsa?\n");
    if(*p<*q)
        printf("\nRESPUESTA: Verdadera\n");
    else
        printf("\nRESPUESTA: Falsa\n");
        printf("\n\nFin del Programa\n");

return 0;
}

/*

        int a = {5, 15, 34, 54, 14, 2, 52, 72};
        int *p = &a [1], *q = &a [5];

a. ¿Cuál es el valor de *(p+3)?  --> *(p+3) = 14

b. ¿Cuál es el valor de *(q-3)? --> *(q-3)=34

c. ¿Cuál es el valor de q-p? --> q-p=4

d. ¿La condición p<q es verdadera o falsa? --> V, q apunta a una direcc mayor que p

e. ¿La condición *p<*q es verdadera o falsa?  F, *q = 2 y *p = 15 (*p>*q)



*/


#include <stdio.h>

int main(void) {
  int a[]= {5, 15, 34, 54, 14, 2, 52, 72};
  int *p,*q;
  p=&a [1]; // apunta a las direcciones de esos elementos
  q=&a [5];
  printf("%d \n",*(p+3));
  printf("%d \n",*(q-3));
  printf("%ld \n",(q-p));
  printf("%ld \n",p); //ld porque la representacion de una direccion es muy larga
  printf("%ld \n",q);
  printf("%d \n",*p);
  printf("%d \n",*q);
  return 0;
}
