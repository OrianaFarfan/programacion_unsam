/*

2. Escribir un programa que cree una lista tipo LIFO (pila) con datos ingresados por el usuario. Luego mostrar los datos. Liberar la memoria que se reservó al crearla.

*/

#include <stdio.h>
#include <stdlib.h>

// defino una estructura NODO
typedef struct nodo{
  int dato;
  struct nodo *sig;
} nodo;

// defino una función que devuelve un puntero tipo 'nodo'
nodo* insertar_LIFO (nodo* l , int dat){
   nodo *nuevo;

   nuevo = (nodo*) malloc (sizeof (nodo));
  (*nuevo).dato = dat;
  (*nuevo).sig = l; // le asigno como puntero a los datos siguientes en la lista
  return nuevo;
}

nodo* destruir(nodo*l){
   nodo* aux;

   while(l!=NULL){
    aux =l;
    l = (*l).sig; // le digo a "l" que debe valer el sig lugar
    free(aux); // libero el espacio en c/nodo
  }
  printf("destruccion de la lista EXITOSA \n");
  return NULL; // como voy a asignarle a mi lista lo q devuelva la función, me aseguro q esté vacía
}


void mostrar(nodo* l){
   printf("lista");

   while(l!=NULL){
        printf("--> %d", (*l).dato);
        l = (*l).sig;
  }
  printf("\n");
}

int main(void) {
  nodo *lista = NULL;
  int i=0;
  int dato=1;

  printf(" ---------- PROGRAMA PARA INGRESAR DATOS EN LISTA TIPO LIFO ---------- \n\n");
  while(dato!=0){
        printf("Ingrese el dato %d que desea ingresar : (deja de ingresar con un 0) \n", i+1);
        scanf("%d", &dato);
        if(dato!=0){

        lista = insertar_LIFO(lista, dato);
    }
    i++;
  }

  mostrar(lista);
  lista = destruir(lista);

  return 0;
}

