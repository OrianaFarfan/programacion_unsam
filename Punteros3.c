/*
3. Escribir un programa que imprima los elementos de un vector de enteros en orden
inverso utilizando punteros (no usar subíndices []).
int v[10] = {1,2,3,4,5,6,7,8,9,10};
int *p;
*/
#include <stdio.h>
int main()
{
    int v[10] = {1,2,3,4,5,6,7,8,9,10},*p,i;

    p = v; // Apunto p al primer elemento del vector

    for( i=9; i>=0 ; i-- ){
        printf("La posicion en el vector %d posee el numero %d y su posicion de memoria es %p\n",i+1,*(p+i),(p+i)); //El ultimo valor es *(p+9) y su posicion (p+9)
        //El "i+1" me imprime la posicion del vector, "*(p+i) me imprimela variable apuntada por ese puntero, y por ultimo "(p+i)" me imprime la posicion de memoria
        }
    return 0;
}
