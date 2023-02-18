/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
4. Dada una lista enlazada, formada por números enteros, hacer un programa que la divida en
dos listas: pares e impares.
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
    int dato;
    nodo *impar= NULL;nodo *par = NULL;

    printf("Ingrese un numero entero (cero finaliza):");
    scanf("%d",&dato);

    while(dato!=0) {
        if(dato%2==0){
            par = insertar_lifo (par,dato);
        }
        else{
            impar = insertar_lifo (impar,dato);
        }
    printf("Ingrese un numero entero (cero finaliza):");
    scanf("%d",&dato);
        }

    printf("La lista PAR es:\n");
    //Mostrar la lista
    mostrar (par);

    printf("La lista IMPAR es:\n");
    //Mostrar la lista
    mostrar (impar);

    //Destruir lista
    par = destruir (par);
    impar = destruir (impar);
    return 0;
}
