/*
EJERCICIOS 1 Y 2

Leer por teclado los detalles (legajo, nombre, promedio) de n estudiantes (n < 100) y almacenarlo en el archivo estudiantes.dat.

--> creo una estructura de estudiante
      CON LOS CAMPOS:
                      - legajo
                      - nombre
                      - promedio

--> almaceno los datos de cada estudiante en un vector que luego almaceno en un archivo
--> en cada posición voy a  tener la info de UN estudiante --> pero cada estudiante, va a tener asociado 3 datos (al ser el estudiante una ESTRUCTURA con 3 CAMPOS)

*/


#include <stdio.h>
// defino una estrucura con typedef
typedef struct{
  int legajo;
  char nombre[10];
  float promedio;
} tipo_est;


int main () {
  int i=0, j=0, MAX;

  printf("ingrese el numero de alumnos (menos de 100): ");
  scanf("%d", &MAX);

  // declaro un vector de tipo : estudiante
  tipo_est estudiantes[MAX];

  // defino el archivo binario en el que voy a almacenar a los estudiantes
  FILE *datos_est;

  /* INGRESO */
    datos_est = fopen("datos_est.dat", "wb");
    for(i =0; i<MAX; i++){
        printf("Ingrese el legajo del estudiante %i \n ", i+1);
        scanf("%d", &estudiantes[i].legajo);

        printf("Ingrese el nombre del estudiante %i \n ", i+1);
        scanf("%s", estudiantes[i].nombre);

        printf("Ingrese el promedio del estudiante %i \n ", i+1);
        scanf("%f", &estudiantes[i].promedio);
  };
  fwrite(&estudiantes, sizeof(tipo_est), MAX, datos_est ); // escribo MAX veces al vector "estudiantes", contando de a pasos de tamaño "tipo_est"
  fclose(datos_est);

  /* LEO ARCHIVO X CONTROL*/
  datos_est = fopen("datos_est.dat", "rb");
  tipo_est estudiantesv2[MAX]; //Defino otro vector para guardar y leer

  if(datos_est == NULL) {
    printf("\n Error al abrir el archivo \n");
    }

  else {
    printf("\n Apertura 2 OK  \n");
        for(j =0; j<MAX; j++)
        {
          fread(&estudiantesv2[j], sizeof(tipo_est), 1, datos_est);

          printf("el legajo del estudiante es : %d \n ",estudiantesv2[j].legajo );
          printf("el nombre del estudiante es : %s \n ",estudiantesv2[j].nombre );
          printf("el promedio del estudiante es : %.2f \n ",estudiantesv2[j].promedio );
        };

  fclose(datos_est);
  };

  // EJERCICIO 2
  lectura(MAX); //Llamo a la funcion lectura de abajo

  return 0;
}

// EJERCICIO 2

void lectura (int MAX) {
  FILE *datos_est;
  tipo_est estudiantes[MAX];

  float promedios[MAX]; // creo un vector con los promedios de cada estudiante
  float mayor = 0.00;
  int i=0, j=0;

  /* LEO ARCHIVO */
  datos_est = fopen("datos_est.dat", "rb");
  if(datos_est == NULL) {
    printf("\n Error al abrir el archivo \n");
  }

  else {
    printf("\n Apertura 3 OK  \n");
    fread(&estudiantes, sizeof(tipo_est),MAX, datos_est);
    for(j =0; j<MAX; j++){
     // fread(&estudiantes[j], sizeof(tipo_est),1, datos_est);
      printf("el promedio del estudiante %d es : %.2f \n ",j+1,estudiantes[j].promedio );
      promedios[j] =  estudiantes[j].promedio;
    };
  fclose(datos_est);
  };


  for(i =0; i<MAX; i++)
    {
    if(promedios[i]>mayor)
        {
            mayor = promedios[i];
        }
    }
  printf("El mayor promedio es : %.2f \n", mayor);

}
