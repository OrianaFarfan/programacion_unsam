/*
4. Escriba la siguiente función:
int *crear_vector (int n, int valor_inicial);
La función debe retornar un puntero a un vector de enteros de tamaño n creado
dinámicamente cuyas posiciones son inicializadas con valor_inicial. La
función debe retornar NULL si no se puede reservar la memoria.
*/



#include<stdio.h>
#include<stdlib.h>

int *crear_vector(int n, int valor_inicial) //Devuelve un puntero que apunta al inicio del vector
{
	int i, *p; // Se crea el puntero que se va devolver

	p=(int*)malloc(sizeof (int)*n); // Se crea un bloque fijo de tamaño sizeof int por n (cantidad de enteros) --> Se asigna la direccion de inicio a p

	for( i=0; i<n; i++)
	{
		*(p+i)=valor_inicial; //Se inicializa cada posicion del vector con el valor que se le pasa
	}

	return p; //Aca devuelve el puntero
}

int main()
{
	int c ,i, vi, *p;

	printf("\nCantidad de elementos: ");
	scanf("%d",&c);

	printf("\n\nValor inicial: ");
	scanf("%d",&vi);

	p=crear_vector(c,vi);

	printf("\n\nEl vector creado es:\n\n");

	for( i=0; i<c; i++)
	{
		printf("%d ", *(p+i));
	}

	printf("\n\n");

	return 0;
}
