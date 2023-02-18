/*

EJERCICIO 7

Definir un tipo de dato que tenga dos campos: tipo (1, 2, o 3) y un segundo campo para el valor.
El valor dependiendo del tipo debe permitir almacenar un int, un float o un double pero sólo uno simultáneamente.

*/

typedef union{
  int entero; // tipo 1
  float flotante; // tipo 2
  double doble; // tipo 3
} valor;

typedef struct { //Tipo de dato con 2 campos:
  int TipoDato; // tipo de dato que puede ser cualquiera de los 3 del union
  valor ValorDato; // tipo de dato valor (o sea ya definio que se va a llamar valor) que tiene que almacenar en simultaneo --> union
} dat;

#include <stdio.h>

int main(void) {
  dat dato;

  printf("Por favor ingrese el tipo del dato (1 = int , 2 = float o 3 = double) \n");
  scanf("%d", &dato.TipoDato); //Lo guarda en el que solo guarda un tipo de dato.

  switch(dato.TipoDato){
    case 1:
      printf("Por favor ingrese el valor del dato\n");
      scanf("%d", &dato.ValorDato.entero);
      printf("El dato ingresado es : %d \n",dato.ValorDato.entero);

    break;
    case 2:
      printf("Por favor ingrese el valor del dato\n");
      scanf("%f", &dato.ValorDato.flotante);
      //dato.ValorDato.entero = 78; //--> con esto lo sobreescribiría
      printf("El dato ingresado es : %.2f  \n",dato.ValorDato.flotante);
      printf("%d  \n",dato.ValorDato.entero);
    break;
    case 3:
      printf("Por favor ingrese el valor del dato\n");
      scanf("%lf", &dato.ValorDato.doble);
      printf("El dato ingresado es : %lf \n",dato.ValorDato.doble);
    break;
  }


  return 0;
}
