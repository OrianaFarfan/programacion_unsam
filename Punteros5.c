/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
5. Escribir una función que devuelva un puntero al máximo valor de un vector de
“doubles”. Si el vector está vacío (cant = 0) la función debe retornar NULL.
*/
#include<stdio.h>
#define N 100

double *max(double *v, int cant) //devuelve un puntero que apunta al elemento double que se quiere, en este caso al mayor
{
	int i;
	double *m, max=0; //con m devolvemos ese valor que queremos --> mayor double

	if(cant == 0)
	{
		m=NULL; //si es cantidad 0 --> el puntero apunta a NULL
	}
	else
	{
		for(i=0; i<cant; i++)
		{
			if(v[i]>max) //Al primer elemento lo compara con 0
			{
				max=v[i]; //se actualiza el valor de max para comparar
				m=&v[i]; //guarda la direccion de memoria de ese valor que esta en el vector v
			}
		}
	}

	return m; //devuelve el puntero a null o a la direccion del valor double
}

int main()
{
	int i, c;
	double *m, v[N]; //maximo un v[N] cuyo N=100

	printf("\nCantidad de valores: ");
	scanf("%d",&c);

	if(c!=0)
	{
		printf("\nIngrese los %d valores para el vector. \n\n",c);
		for(i=0; i<c; i++)
		{
			scanf("%lf", v+i); //nueva forma de guardar valores en un vector aunque tambien sirve -->	scanf("%lf",&v[i]);
		}
	}

	m = max(v, c);

	if(m != NULL)
	{
		printf("\nEl mayor valor es: %f\n\n",*m); //*m porque quiero mostrar el valor
	}
	else
	{
		printf("\nNo hay ningun valor en el vector.\n\n");
	}

	return 0;
}
