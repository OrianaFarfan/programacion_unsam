/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020
6. Escribir una función que busque un elemento de la lista, por comparación con una clave e
indique si se encuentra o no. Si se encuentra se informará este elemento y también el
anterior
(en caso de existir).
*/
#include<stdio.h>
#include<stdlib.h>
/*Declaración de la estructura para los nodos (tipo de datos)*/
typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;

/*Inserta un nuevo nodo al final de la lista. Esta es la funcion pedida en el enunciado*/
/*Todo lo demas es para tener un programa completo para poder probar*/
nodo *insertar_fifo (nodo *l, int d)
{
    nodo *nuevo, *p;

    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = NULL; /*Porque va a ser el ultimo nodo*/

    if (l == NULL)
        return nuevo;

    /*Como la lista no esta vacia la recorro buscando el ultimo nodo*/
    p = l;
    while (p->sig != NULL)
        p = p->sig;
    /*Ahora p es el ultimo nodo*/
    p->sig = nuevo;
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

/*Funcion de comparar*/
void comparar (nodo *l) {
    int comp,i=0;
    nodo * aux;

    printf ("\nEl programa procedera a buscar un elemento.\nIngrese el elemento a buscar:\n");
    scanf("%d",&comp);

    while (l != NULL) {
        i++;
        if ( comp == l->dato && i==1 ) {
            printf ("\nEl elemento fue encontrado en su lista: --> %d\nNo posee elementos anteriores", l->dato);
            }

        else if ( comp == l->dato && i!=1) {
        printf ("\nEl elemento fue encontrado en su lista: --> %d \nEL elemento anteriores es: --> %d",l->dato,l->dato-1);
        }

        else {
            printf("El elemento no esta en la lista");
        }

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
/*Pide entros hasta que se ingrese cero y los inserta en la lista*/
nodo *ingresa_usuario(nodo *lista) {
    int temp;

    printf ("\nIngrese un nro entero (cero finaliza):");
    scanf ("%d", &temp);
    while (temp != 0) {
        lista = insertar_fifo (lista, temp);
        printf ("\nIngrese otro nro entero (cero finaliza):");
        scanf ("%d", &temp);
    }
    return lista;
}
/*Programa principal que hace uso de las funciones definidas arriba*/
int main ()
{
    nodo *lista = NULL;

    /*Inserta en la lista los valores que ingrese el usuario*/
    lista = ingresa_usuario (lista);

    comparar (lista);

    /*Destruir lista*/
    lista = destruir(lista);
    return 0;
}
