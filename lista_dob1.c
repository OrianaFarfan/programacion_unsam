/*

1. Escribir funciones que inserten un elemento numérico en una lista doblemente enlazada:
    a. Al principio de la lista.
    b. Al final de la lista.
    c. En un lugar intermedio (por ejemplo la posición n).

(c) --> tomo a n => como que quiero poner a mi nodo, antes del nodo que se encuentra en 'n'

https://www.programiz.com/dsa/doubly-linked-list#insertion-in-between

*/

#include <stdio.h>
#include <stdlib.h>

// defino un nodo xra lista doble
// dato + nodo sig + punt nodo sig
typedef struct nodo_d{
  float dato;
  struct nodo_d *ant, *sig;
}nodo_d;

// estructura con punteros al primero y al ult
typedef struct ldoble {
  nodo_d *prim, *ult;
}lista;


int  menu(){
  int ingreso = 0;
  printf("si desea ingresar un elemento al ppio de la lista, ingrese 1 : \n");
  printf("si desea ingresar un elemento al final de la lista, ingrese 2 : \n");
  printf("si desea ingresar un elemento en un lugar especifico de la lista, ingrese 3 : \n");
  printf("si desea mostrar la lista, ingrese 4 : \n");
  printf("si desea salir, ingrese 5 : \n");
  scanf("%d", &ingreso);
  return ingreso;
}
lista insertar_LIFO(lista l, float d){ // lista l -> puedo no definirlo como puntero, porq todos los campos son punteros
  nodo_d* nuevo=NULL;
  nuevo=(nodo_d*) malloc (sizeof(nodo_d));
  nuevo-> dato= d;
  nuevo-> sig = l.prim;
  nuevo-> ant = NULL;
  if(l.prim== NULL){
    l.ult = nuevo;
  }
  else{
    l.prim->ant=nuevo; // le asigna al puntero anterior del primer elemento, el nuevo nodo
  }
  l.prim=nuevo;
  return l;
}

lista insertar_FIFO(lista l,float d){
  nodo_d* nuevo= NULL;
  nuevo= (nodo_d*) malloc (sizeof(nodo_d));
  nuevo-> dato= d;
  nuevo-> sig= NULL;
  nuevo-> ant= l.ult;
  if(l.prim==NULL){
    l.ult=nuevo;
  }
  else{
    l.ult->sig= nuevo;
  }
  l.ult=nuevo;
  return l;
}



int cantNodos(lista l){
  nodo_d *p=l.prim;

	int tam=0;
	while(p!=NULL){
    p=p->sig;
    tam++;
  }
  printf("la cant de nodos de la lista es de: %d nodos \n", tam);
	return tam;
}



void mostrar(lista l){
  nodo_d *p, *aux;
  p = l.prim;
  printf("lista : \n");
  while(p!=NULL){
    printf("-->%.2f", p->dato);
    p = p->sig;
  }
  printf("\n");
}


lista destruir (lista l) {
	nodo_d *p, *aux;

	p = l.prim; // p apunta al primer nodo
	while (p != NULL) {
		aux = p;
		p = p->sig;
		free (aux);
	}
	printf ("Lista destruida\n");
  // como tengo una lista con punteros 1ro y ultimo, tengo q actualizarlos con valor null
	l.prim = NULL;
	l.ult = NULL;
	return l;
}


lista insertar_intermedio(lista l, float d, int n){

    if(n==1) l=insertar_LIFO(l, d); //En el caso de que n sea 1, o sea el primero

    else{
        nodo_d *aux=NULL;
        int i=1; //Defino este valor
        //DEFINO UN PUNTERO AUX PARA RECORRER LA LISTA DESDE EL PRIMER NODO
        aux =l.prim; //DEJO AUX EN LA POSICION DE INSERCION

        while(aux != NULL && i != n){ // ARREGLO: CAMBIO EL ORDEN DE aux = aux->sig (porq voy a estar guardando el aux mal)
                //Si i es distiton de n, o sea la posicion --> i(que es 1)!=n
           i++; //va incrementando el valor de i hasta que llegue al valor de n
           aux = aux->sig;
        }
        //Con lo anterior se va buscando el nodo que se quiere: o sea en la posicion que se quiera
        //CASO 1 - SE ENCONTRO LA POSICION --> Aca comienzo a llenar con los datos
        if(i == n){
            nodo_d *nuevo;
            nuevo = (nodo_d*)malloc(sizeof(nodo_d));
            nuevo->dato = d; //PASO EL DATO A NUEVO

            // ARREGLO: primero estoy poniendo flechitas DESDE mi nodo nuevo, a los nodos de la lista
            nuevo->sig = aux; //APUNTO EL SIG A LO QUE HABIA EN LA POSICION DE INSERCION
            nuevo->ant = aux->ant; //APUNTO EL NODO ANT A LO QUE HABIA EN LA POS DE INSERCION
            // aux = nuevo; //APUNTO LA POSICION DE INSERCION AL VALOR DE INSERCION //ARREGLO: esto xra mi no va, no quiero reemplazar a aux
            // ARREGLO: voy a poner las flechitas HACIA mi nodo nuevo
            // 1RA FLECHITA
            // sabiendo que nuevo->ant = aux->ant
            nuevo->ant->sig = nuevo; // si es distinto de null, (ya se que va a ser así), entonces puedo acceder a ese nodo ('nuevo->ant')
            // 2DA FLECHITA
            aux->ant = nuevo;
            // l.prim = nuevo; //el principio de la lista apunta al dato // ARREGLO: esto nose por qué lo harías, no sabes si nuevo va a estar en n=1
        }
        // CASO 2 - LA LISTA NO TIENE SUFICIENTES LUGARES
        else{
            printf("\nLa lista no tiene suficientes lugares");
        }

    }

    return l;
}




int main(void) {
  int m = 0,pos=0;
  float elem =0.0;
  lista l;
  // inicializo la lista
  l.prim = NULL;
  l.ult = NULL;

  while(m!=5){
    m = menu();
    switch(m){
      case 1:
        printf("Ingrese el elemento a ingresar: \n");
        scanf("%f", &elem);
        l = insertar_LIFO(l, elem);
        break;
      case 2:
        printf("Ingrese el elemento a ingresar: \n");
        scanf("%f", &elem);
        l = insertar_FIFO(l, elem);
        break;
      case 3:
        printf("Ingrese el elemento a ingresar: \n");
        scanf("%f", &elem);
        printf("ingrese la posicion en la que lo quiere agregar \n");
        scanf("%d", &pos);
        l = insertar_intermedio(l, elem, pos);
        break;
      case 4:
        mostrar(l);
      break;
    }
  }
  l = destruir(l);
  return 0;
}

