/*
2. Escribir un programa para leer el archivo vector.dat del ejercicio anterior y
almacenarlo en un vector. No se conoce la cantidad de elementos y no se puede
limitar
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c=0, r, *v=NULL, i;
	FILE *f;

	f=fopen("vector.dat","rb");
	if(f==NULL)
        {
            printf("\nError al abrir.\n");
            return 1;
        }

	do{
		c++;
		v = (int*)realloc(v, sizeof (int)*c); //Se copia lo que se tenia en v en un nuevo bloque de ese size
		r = fread(v+c-1, sizeof (int), 1, f); //Se lee de a 1 dato de sizeof int del archivo f y se lo guarda en v+c-1
        }while(r == 1);

	printf("\nEl vector leido es: \n\n");
	for(i = 0; i < c-1; i++) //Creo que es porque hace ese do while, onda incrementa "c" pero cuando hace el fread no da 1 y sale del do while
        {
            printf("%d ",*(v+i));
        }
	printf("\n\n");

	free(v);
	v == NULL;

	if(fclose(f)!=0)
	{
		printf("\nError al cerrar.\n");
		return 2;
	}

	return 0;
}

