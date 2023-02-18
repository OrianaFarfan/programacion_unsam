/*
4. Escribir una función que reciba un vector de enteros y su tamaño, y devuelva la
cantidad de números impares que contiene.
int impares (int *v, int tam);
*/
#include <stdio.h>
int impares (int *v, int tam){ //funcion escrita
    int impar=0,i;

    for( i=0 ; i<tam ; i++){
        if( *(v+i) % 2 != 0 ){ // mi condicion para que luego incremente el contador de impares
        impar++;
        }
    }
return impar; // retorna el contador de impares
}


int main()
{
    int v[12] = {1,2,3,4,5,6,7,8,9,10,11,13}; // podria hacer un vector de n variable pero el programa seria mas grande

    printf("La cantidad de numeros impares es: %d \n", impares(v,12)); // mando a la funcion impares el vector y su longitud
    //El vector es como un puntero que apunta al inicio del vector
    return 0;
}
