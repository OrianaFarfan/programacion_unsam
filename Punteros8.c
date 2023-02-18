/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
8. Implemente una función que reciba un vector de números en punto flotante y un
entero que representa el tamaño del vector y devuelva el promedio.
Usar notación aritmética de punteros (no subíndices []) para recorrer el vector.
*/
#include<stdio.h>
#define N 100

float promedio(float v[], int cant)
{
	int i;
	float suma=0, promedio; //float porque el vector tiene valores float

	for(i=0; i<cant; i++)
	{
		suma += *(v+i); //sumo valores del vector v, donde voy a barrer ese vector como si fuera un puntero
	}

	promedio = suma/cant;

	return promedio;
}

int main()
{
	int i, c;
	float v[N];

	printf("\nCantidad de valores: ");
	scanf("%d",&c);

	printf("\nIngrese los %d valores del vector:\n\n", c);
	for(i = 0; i < c; i++)
	{
		scanf("%f",v+i);
	}

	printf("\nEl promedio de los valores ingresados es: %f\n\n", promedio(v, c));

	return 0;
}
