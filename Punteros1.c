/*
1. Considere las siguientes instrucciones:
                  int *p; --> define un puntero que apuntará a enteros
                  int i; --> define un entero
                  int k;  --> otro
                  i = 42; --> asigna el 42 a la var i
                  k = i; --> asigna el i=42 a la var k
                  p = &i; --> asigna la dirección de i a p

Luego de esas instrucciones, ¿cuál de las siguientes cambia el valor de i a 75?
A. k = 75; // Valor de i sera 42
B. *k = 75; // k no es un puntero
C. p = 75; //p es un puntero
D. *p = 75; // Esta es la correcta, ya que con p=&i se le asigno al puntero p la direccion de i, y con *p=75 estoy entrando al valor de esa variable
                        //y asignandole este valor
E. Dos o más de las anteriores // D es la correcta
*/
#include <stdio.h>
int main()
{
    int *p;
    int i;
    int k;
    i = 42;
    k = i;
    p = &i;
    *p=75;
    k=45; //cambia el valor
    printf ("Valor de i es: %d \n",i);
    printf ("Valor de k es: %d \n",k);
    return 0;
}
