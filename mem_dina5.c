/*
Programacion UNSAM
Autor: Carlos Douglas Rodriguez
Año: 2020

5.Suponga que se ejecutan las siguientes instrucciones:

    struct punto {
    int x;
    int y;
    };

    struct rectangulo {
    struct punto superior_izq;
    struct punto inferior_der;
    };

    struct rectangulo *p;

Escriba las líneas necesarias para que p apunte a una estructura rectangulo válida
que tenga (10,25) como esquina superior izquierda y (20,15) como esquina inferior
derecha.
*/

#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

struct punto { //coord x e y
    int x;
    int y;
    };

struct rectangulo {
    struct punto superior_izq; // coord x e y sup izq
    struct punto inferior_der; // coord x e y inf der
    };

void main(){
    struct rectangulo *p;

    p=(struct rectangulo*)malloc(sizeof(struct rectangulo));

    if(p==NULL){
        printf("\nNo se pudo reservar memoria. Saliendo...\n");
    }

    else{

        printf("\nDigite la coordenada X del punto superior izquierdo: ");
        scanf("%d",&(*p).superior_izq.x); // Ese & no es direccional sino que es para guarda por el scanf

        printf("\nDigite la coordenada Y del punto superior izquierdo: ");
        scanf("%d",&(*p).superior_izq.y);

        printf("\nDigite la coordenada X del punto inferior derecho: ");
        scanf("%d",&(*p).inferior_der.x);

        printf("\nDigite la coordenada Y del punto inferior derecho: ");
        scanf("%d",&(*p).inferior_der.y);
    }

    //Con *p muestro valorrrrrrrrrrrrrrrrrrrrrr
    printf("\nEl punto superior izquierdo es: (%d,%d) y el punto inferior derecho es: (%d,%d)\n",(*p).superior_izq.x,(*p).superior_izq.y,(*p).inferior_der.x,(*p).inferior_der.y);
    free (p);
    return;
}
