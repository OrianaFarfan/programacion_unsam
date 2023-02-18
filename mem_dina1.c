/*
1. Escribir un prog. en el que el usuario informa la cantidad de elementos que va a
ingresar y luego los valores de los elementos (enteros).
Los elementos deben almacenarse en un vector y luego en el archivo vector.dat. No
se debe limitar la cantidad de elementos.
*/

#include<stdio.h>
#include<stdlib.h>


//Esta funcion grabar es igual al del ejemplo del profe: donde se le pasa la cantidad de datos de esa struct y el vector contiene en cada posicion (n posiciones)
// a cada estructura con su campo.
void guardar(int *v, int n)
{
	int c;
	FILE *f;

	f = fopen("vector.dat","wb");
	if (f != NULL)
	{
		c = fwrite(v, sizeof (int), n, f);
		if(c != n)
		{
			printf("\nError al guardar. \n");
		}
		if(fclose(f) != 0)
		{
			printf("\nError al cerrar. \n");
		}
	}
	else
	{
		printf("\nError al abrir. \n");
	}

	return;
}

int main()
{
	int n, *v=NULL, i ;

	printf("\nCantidad de elementos a ingresar: ");
	scanf("%d",&n);

	//Vemos que v siempre se inicializa en NULL
	v = (int*) malloc(sizeof (int) * n); //Reservo un bloque de esa cantidad de memoria y v guarda la direccion

	printf("\nIngrese los %d valores: \n\n", n);

	for(i=0; i<n; i++)
        {
            scanf("%d", v+i); //Con v+1 recorro el vector con el puntero
        }

	guardar(v,n);

	free(v);
	v=NULL;

	return 0;
}
