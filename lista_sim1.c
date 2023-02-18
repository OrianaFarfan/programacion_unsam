/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
1. Escriba una función que permita insertar un nuevo elemento antes del primer nodo de una
lista
enlazada de enteros.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
	int dato;
	struct nodo *sig;

}nodo;

nodo *insertar_lifo(nodo *l, int d)
{
	nodo *nuevo;

	nuevo = (nodo*) malloc (sizeof (nodo));
	nuevo->dato = d;
	nuevo->sig = l;

	return nuevo;
}

void mostrar(nodo *l)
{
	printf("\nLista: ");

	while(l != NULL)
	{
		printf("--> %d ",l->dato);
		l = l->sig;
	}
	printf("\n\n");
}

nodo *destruir (nodo *l)
{
    	nodo *aux;

   	 while (l != NULL)
   	 {
         aux = l;
       	 l = l->sig;
       	 free (aux);
   	 }
   	 aux = NULL;

   	 printf ("\nLista destruida.\n\n");

   	 return aux;
}

int main()
{
	int c;
	nodo *lista = NULL;

	printf("\nIngrese valores enteros para la lista (finalize con 0): \n\n");
	scanf("%d",&c);

	while(c != 0)
	{
		lista = insertar_lifo(lista,c);
		scanf("%d",&c);
	}

	mostrar(lista);

	lista = destruir(lista);

	return 0;
}
