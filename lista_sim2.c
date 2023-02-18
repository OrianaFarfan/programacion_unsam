/*
2. Escribir un programa que cree una lista tipo LIFO (pila) con datos ingresados por el
usuario.
Luego mostrar los datos. Liberar la memoria que se reservó al crearla.
*/
#include<stdio.h>
#include<stdlib.h>

//Declaración de la estructura para los nodos (tipo de datos)
typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;

//Funcion que inserta al principio
nodo *insertar_lifo (nodo *l,int d)
{
    nodo *nuevo;
    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = l;
return nuevo;
}

//Funcion que muestra los elementos de la lista
void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

//Funcion que libera toda la memoria ocupada por la lista
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

//Programa principal que hace uso de las funciones definidas arriba
int main ()
{
    int opc,dato;
    nodo *lista = NULL;

    printf("Ingrese dato que quiera (con 0 finaliza):");
    scanf("%d",&dato);

    while(dato!=0) {

        lista = insertar_lifo (lista,dato);

        printf("Ingrese otro dato (con 0 finaliza):");
        scanf("%d",&dato);
    }

    //Mostrar la lista
    mostrar (lista);

    //Destruir lista
    lista = destruir (lista);
    return 0;
}
