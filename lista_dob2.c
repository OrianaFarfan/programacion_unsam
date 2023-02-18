/*
2. Escribir un programa que genere una lista doble y ordenada. Generar un listado en pantalla de la misma comenzando desde cada extremo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defino un nodo gral de las listas dobles (con punteros para atrás y adelante)
typedef struct nodo_d{
  int dato;
  struct nodo_d *ant, *sig;
}nodo_d;

// defino los punteros al primer y ultimo el de la lista
typedef struct ldoble{
  nodo_d *prim, *ult;
} lista;


void mostrarDePrimAUlt(lista l){
  nodo_d *p = l.prim; //A p se lo inicializa con el puntero del inicio

  printf("Lista al dcho : ");
  while(p!=NULL){
    printf("--> %d", p->dato);
    p = p->sig;
  }
  printf("\n");
  return;
}

void mostrarDeUltAPrim(lista l){
  nodo_d *p = l.ult;
  printf("Lista al reves : ");
  while(p!=NULL){
    printf("--> %d", p->dato);
    p = p->ant;
  }
  printf("\n");
  return;
}

lista destruir(lista l){
  nodo_d *p = l.prim; // uso a 'p' como antes usaba a 'l'
  nodo_d *aux =NULL;
  while(p!=NULL){
    aux = p;
    p = p->sig;
    free(aux);
  }
  l.prim = NULL;
  l.ult = NULL;
  printf("LISTA DESTRUIDA \n");
  return l;
}

lista insertar_lifo(lista l, int dato){
  nodo_d  *nuevo = NULL;
  nuevo = (nodo_d*) malloc (sizeof(nodo_d));
  nuevo->dato =dato;

  nuevo->ant = NULL;
  nuevo->sig = l.prim;

  if(l.prim ==NULL){ // lista vacía
    l.ult = nuevo;
  }
  else{
    l.prim->ant = nuevo;
  }

  l.prim = nuevo;
  return l;
}


lista ingreso_ordenado(lista l, int dato){ // menor a mayor
  nodo_d *nuevo = NULL;
  nuevo = (nodo_d*) malloc (sizeof(nodo_d));
  nuevo->dato = dato;

  if(l.prim == NULL || l.prim -> dato > dato){ // lista vacia, l.ult=l.prim=NULL Ó primer dato mayor al q quiero ingresar (o sea que mi dato es menor, y lo tengo
                                                                                                                // que insertar antes que el que es primer nodo)

    l = insertar_lifo(l, dato); // VER SI ES LO MISMO
  }
  else{
    nodo_d *p;
    p = l.prim;

    while(p->sig !=NULL && p->sig->dato <= dato){ // voy recorriendo la lista. Mientras el nodo siguiente no sea NULL y que el dato de nodo siguiente sea menor a dato
      p=p->sig; //Avanzo
    }
    // sale o: porque estoy en l.ult o porque p->sig->dato > dato
    // voy a meter a 'nuevo' entre p y p->sig
    nuevo->sig = p->sig;
    p->sig = nuevo;
    nuevo->ant = p;

    if(nuevo->sig != NULL){ // o sea, salió por la segunda cond (esto era a lo q apuntaba p->sig)
      nuevo->sig->ant =nuevo; //esto significa: al nodo siguiente de nuevo --> su anterior ahora apunta a nuevo
    }
    else{ // salió por q p->sig ==NULL
      printf("es el ult elemento ahora \n");
      l.ult = nuevo;
    }
    //p->sig = nuevo; // tengo que hacerlo ultimo!!!!
  }
  return l;
}


int main(void) {
  int elemento=1;
  lista l; // no hace falta definirla como un puntero, porq los campos son punteros
  l.prim = NULL;
  l.ult = NULL;

  while(elemento!=0){
    printf("ingrese el elemento de la lista -ingrese 0 para dejar de ingresar-: \n");
    scanf("%d", &elemento);
    if(elemento!=0){
      l = ingreso_ordenado(l, elemento);
    }
  }

  mostrarDePrimAUlt(l);
  //printf("%d", l.ult->dato);
  if(l.ult !=NULL){
    printf("ult dato es:  %d\n", l.ult->dato); // mi error estaba en que hacia p->sig = nuevo al ppio
  }
  mostrarDeUltAPrim(l);
  l = destruir(l);
  return 0;
}

