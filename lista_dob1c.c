#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_d {
	float dato;
	struct nodo_d *ant, *sig;
} nodo_d;

typedef struct ldoble {
	nodo_d *prim, *ult;
} lista;

lista insertar_lifo(lista l, float d) {
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;
	nuevo->ant = NULL;
	nuevo->sig = l.prim;

	if (l.prim == NULL)
		l.ult = nuevo;
	else
		l.prim->ant = nuevo;
	l.prim = nuevo;
	return l;
}

lista insertar_fifo(lista l, float d) {
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;
	nuevo->sig = NULL;
	nuevo->ant = l.ult;

	if (l.prim == NULL)
		l.prim = nuevo;
	else
		l.ult->sig = nuevo;
	l.ult = nuevo;
	return l;
}

lista destruir (lista l) {
	nodo_d *p, *aux;

	p = l.prim;
	while (p != NULL) {
		aux = p;
		p = p->sig;
		free (aux);
	}
	printf ("Lista destruida\n");
	l.prim = NULL;
	l.ult = NULL;
	return l;
}

lista insertar_pos_n(lista l, float d, int n) {
	int c=0;
	lista aux, aux2;
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;

	aux=l;
	while(aux.prim != NULL && c != n){
		aux.prim = aux.prim->sig;
		c++;
	}
	if(aux.prim == NULL)
		printf("\nLa lista tiene %d posiciones.\n\n", c);
	else{
		aux.prim=aux.prim->ant;
		nuevo->ant=aux.prim->ant;
		nuevo->sig=aux.prim;
		aux.prim=nuevo->ant;
		aux.prim->sig=nuevo;
	}

	return l;
}

int main() {
	nodo_d *p;
	float f;
	lista l;
	int modo,n;

	l.prim = NULL;
	l.ult = NULL;

	printf("Ingrese los datos (0 para terminar): ");
	scanf("%f", &f);
	while (f != 0) {
		printf ("\nIngrese 1 para LIFO, 2 para FIFO o 3 para posición n: ");
		scanf ("%d", &modo);
		if (modo == 1)
			l = insertar_lifo(l, f);
		else{
			if(modo == 2)
				l = insertar_fifo(l, f);
			else{
				printf("\nPosición:");
				scanf("%d",&n);
				l = insertar_pos_n(l, f, n);
			}
		}
		printf("\nIngrese los datos (0 para terminar): ");
		scanf("%f", &f);
	}

	printf("\nMuestro en orden ingresado\n");
	for (p = l.prim; p != NULL; p = p->sig)
		printf("Dato = %6.2f\n", p->dato);

	printf("Muestro en orden inverso\n");
	for (p = l.ult; p != NULL; p = p->ant)
		printf("Dato = %6.2f\n", p->dato);

	l = destruir (l);
	return 0;
}
