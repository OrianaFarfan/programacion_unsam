/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
3. Escriba una función que devuelva la cantidad de elementos de una lista.
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

//Funcion que muestra la cantidad de elementos de la lsita
void mostrar_cantidad (nodo *l) {
    int i=0;
    if(l==NULL) {
        printf("La lista se encuentra vacia\n");
    }
    else {
    while(l!=NULL) {
        l = l->sig;
        i++;
    }
    printf("La lista posee %d elementos\n",i);
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
    int dato;
    nodo *lista = NULL;

    printf("Ingrese un numero entero (cero finaliza):");
    scanf("%d",&dato);

    /*Generamos una lista */
    while(dato!=0) {
        lista = insertar_lifo (lista,dato);

        printf("Ingrese un numero entero (cero finaliza):");

        scanf("%d",&dato);
    }
    //MUESTRA LA CANTIDAD DE ELEMENTOS DE LA LISTA!!!!!!!!!!!!!!!!!!
    mostrar_cantidad (lista);
    //Destruir lista
    lista = destruir (lista);
    return 0;
}
