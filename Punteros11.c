/*

11. Suponga que el puntero p está declarado como sigue:

    struct mi_estructura {
      char a, b;
      int c;
      int e [5];
    };

    struct mi_estructura me;

    struct mi_estructura *p = &me; // --> define un puntero del tipo "mi_estructura" que apunta a la variable "me"

¿Cuáles de las siguientes instrucciones son válidas?
  a) p->b = ’ ’;  --> VALIDA, le asigno el caracter al campo b (a través del putnero)
  b) p->e [3] = 10; --> VALIDA, muy pareceida a anterior
  c) (*p).a = ’*’; --> VALIDA TAMBN, es igual que a) pero otra forma
  d) *p.b = ’?’;  --> falta paréntesis
  e) me.c = 1; --> si es valido, pero lo modifica localmente nomás
  f) p.c = 1; --> NO ES VALIDO, falta flecha o algo, no puedo hacer esto con un puntero
*/




#include <stdio.h>

struct mi_estructura {
  char a, b;
  int c;
  int e [5];
};

int main(void) {
      struct mi_estructura me;
      struct mi_estructura *p = &me; // --> define un puntero del tipo "mi_estructura" que apunta a "me"

      p->b ='A';
      printf("el caracter es 'b': %c \n", me.b); // me refiero a la estructura directamente (cuyo valor fue modificado a traves del puntero)

      p->e[3] =10;
      printf("el valor de la pos 4 del vector 'e' es : %i \n", me.e[3]);

      (*p).a ='*';
      printf("el caracter es 'a' : %c \n", me.a);

      // *p.b = '?'; --> NO VALIDO, falta parentesis

      me.c=8;
      printf("el valor de 'c' es : %i \n", me.c);

      // p.c =1; // no puedo hacer esto con un puntero
      return 0;
    }
