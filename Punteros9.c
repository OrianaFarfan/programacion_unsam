/*
9. Implemente la siguiente función para calcular el producto escalar de dos vectores:
double prod_esc (const double *a, const double *b, int n);
Donde a y b apuntan a vectores de longitud n.
La función debe retornar a[0]*b[0]+a[1]*b[1]+ ... + a[n-1]*b[n-1]
Usar notación aritmética de punteros (no subíndices []) para recorrer los vectores.
*/

#include<stdio.h>
#define N 100

double prod_esc (const double *a, const double *b, int n)
{
	int i;
	double prod = 0;

	for (i = 0; i < n; i++)
	{
		prod += *(a+i) * *(b+i); // con b+1 me mueve en los lugares de los vectores y con * muestro el contenido.
	}

	return prod;
}

int main()
{
	int i, c;
	double a[N], b[N];

	printf("\nCantidad de valores para los vectores: ");
	scanf("%d",&c);


	printf("\nIngrese los %d valores para el primer vector: \n\n", c);
	for (i = 0; i < c; i++)
	{
		scanf("%lf",a+i);
	}


	printf("\nIngrese los %d valores para el segundo vector: \n\n", c);
	for (i = 0; i < c; i++)
	{
		scanf("%lf",b+i);
	}


	printf("\nEl producto vectorial de los vectores ingresados es: %f\n\n", prod_esc(a,b,c));

	return 0;
}
