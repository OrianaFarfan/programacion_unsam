/*
Ej 8 Práctica listas
Buscar un elemento numérico en una lista y eliminarlo. Considerar que puede ser el primero,
último o intermedio.
Programacion UNSAM
Año: 2021
 */

#include <stdio.h>
#include <stdlib.h>

/* Declaración de la estructura para los nodos (tipo de datos) */
typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;

/* Inserta al principio */
nodo *insertar_lifo (nodo *l, int d) {
    nodo *nuevo;

    nuevo = (nodo *) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = l;
    return nuevo;
}

/* Muestra los elementos de la lista */
void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

/* Libera toda la memoria ocupada por la lista */
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

/* Elimina un nodo de la lista --> Se divide en 3 casos*/
nodo *eliminar (nodo* l, int d) { //Se recibe el puntero al primer nodo y d que es el dato que se quiere eliminar de la lista
    nodo *ret = l, *aux; //puntero ret inicializado con el inicio de la lista


    if (l == NULL) { /* 1er caso: Si la lista es nula no hay que hacer nada */
        printf ("La lista esta vacia\n"); //Y retorna directamente ret que era l
    }


    else { /* La no lista es nula */
        if (l->dato == d){ /* 2do caso: el nodo a borrar es el primero */
            ret = l->sig; //A ret (que es el auxiliar/copiar de l: o sea apunta al primer nodo) se le actualiza como el nodo siguiente a l
            free (l); //Se libera al primer nodo
            printf ("Elemento eliminado\n"); //Y se retorna ret actualiazod
        }


        else { /* 3er caso: el nodo a borrar no es el primero */
            while (l->sig != NULL && l->sig->dato != d) //mientras que el sig de l (un nodo) no sea NULL y el dato de nodo siguiente sea distinto a d
                //Con l vamos recorriendo los nodos --> Se quiere que l apunte al nodo anteiror del que se quiere borrar
                l = l->sig; //Se le actualiza el valor de l con el del nodo siguiente

           //Recordar que l ahora es el nodo anterior al nodo que se quiere eliminar
            if (l->sig != NULL) { /* Si l->sig es NULL es porque el dato no existe en l, pero en este caso no llego a NULL */
                aux = l->sig; //Con aux se selecciona el nodo que se quiere eliminar
                l->sig = aux->sig; //quiero que l (el anterior al nodo que se quiere eliminar) apunte al siguiente del nodo eliminado (aux)
                free (aux); //libero al nodo aux que es el que se quiere eliminar
                printf ("Dato %d eliminado\n", d);
            }
            else { /* Si l->sig es NULL */
                printf ("El dato %d no se encuentra en la lista\n", d);
            }
        }
    }
    return ret; /* Va a ser el nuevo principio de la lista */
}

/* Pide entros hasta que se ingrese cero y los inserta en la lista */
nodo *ingresa_usuario (nodo *lista) {
    int temp;

    printf ("Ingrese un nro entero (cero finaliza):");
    scanf ("%d", &temp);
    while (temp != 0) {
        lista = insertar_lifo (lista, temp); //lifo : inserta primero/adelante
        printf ("\nIngrese otro nro entero (cero finaliza):");
        scanf ("%d", &temp);
    }
    return lista;
}

int main() {
    nodo *lista = NULL;
    int x;

    /* Inserta en la lista general los valores que ingrese el usuario */
    lista = ingresa_usuario (lista);
    mostrar (lista);

    /* Busqueda pedida en el enunciado */
    printf ("Ingrese un valor a eliminar:");
    scanf ("%d", &x);
    lista = eliminar (lista, x);
    mostrar (lista);

    /* Destruir lista (liberar memoria) */
    lista = destruir (lista);

    return 0;
}
