/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
7. Se tiene una lista ordenada de números enteros y se pide hacer una función que inserte un
elemento a la lista, manteniéndola ordenada.
*/

#include<stdio.h>
#include<stdlib.h>
/*Declaración de la estructura para los nodos (tipo de datos)*/
typedef struct nodo{
    int dato;
    struct nodo *sig;
} nodo;

/*Inserta en orden*/
nodo *insertar_ordenado(nodo *l, int d) {
    nodo *nuevo, *aux;

    nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = d;

    if (l == NULL || l->dato > d) {
    /*Lista vacia o primer elemento > nuevo*/
        nuevo->sig = l;
        return nuevo;
}
    /*Si llega hasta aca => lista no vacia y nuevo > primer*/
    aux = l;
    while (aux->sig != NULL  &&  aux->sig->dato <= d)
        aux = aux->sig;

    /*Salio del ciclo => aux->sig es NULL o aux->sig->dato > d*/
    /*Inserto el nuevo entre aux y aux->sig*/
    nuevo->sig = aux->sig;
    aux->sig = nuevo;
    return l;
}

/*Muestra los elementos de la lista*/
void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

/*Libera toda la memoria ocupada por la lista*/
nodo *destruir (nodo *l) {
    nodo * aux;
    while (l != NULL) {
        aux = l;
        l = l->sig;
        free (aux);
    }
    printf ("lista destruida\n");
    return NULL;
    }

/*Programa principal que hace uso de las funciones definidas arriba*/
int main () {
    nodo *lista = NULL;
    int dato;

    printf("Ingrese un numero entero (cero finaliza):");
    scanf("%d",&dato);

    /*Generamos una lista */
    while(dato!=0) {
        lista = insertar_ordenado (lista,dato);
        printf("Ingrese un numero entero (cero finaliza):");
        scanf("%d",&dato);
    }

    mostrar (lista);

    /*Permite inserter un valor arbitrario a la lista*/
    printf ("Ingrese un valor a agregar:");
    scanf ("%d", &dato);
    lista = insertar_ordenado (lista, dato);

    mostrar (lista);

    /*Destruir lista (liberar memoria)*/
    lista = destruir(lista);
    return 0;
}
