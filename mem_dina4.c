/*

3. Escriba la función 'duplicar' que reserve memoria dinámicamente para duplicar un string que se le pasa como argumento. Por ejemplo, la llamada:

                                        p = duplicar (str);

debe reservar memoria para un string de la misma longitud que str, copiar los datos y retornar un puntero a la nueva cadena de caracteres. Si la reserva de memoria falla, entonces duplicar debe retornar un puntero nulo.

                                      -----------PLANTEO--------------
* a la funcion 'duplicar'
                          -> se le pasa como argumento un string
                          -> lo que devuelve es un puntero a una 'nueva cadena de caracteres'
                          -> este puntero -> relacionado a una 'reserva de memoria' donde se copiaron los datos del string original
                          -> si no lo puede hacer debe retornar un puntero nulo

IDEAS-------------
-> yo sé que existe una función que REDIMENSIONA EL ESPACIO ASIGNADO DE FORMA DINÁMICA ANTERIORMENTE A UN PUNTERO
--> LLAMADA 'REALLOC'
-->void*realloc(void*puntero, size_t nuevo_tamaño_bloque);
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *duplicar (char *str1) //Recibe un puntero a char y devuelve otro puntero a char
{
	int i, n;
	char *str2;

	n=strlen(str1); // mide la longitud del char de entrada
	str2 = (char*) malloc (sizeof (char)*n*2+1); //El +1 es para asignarle el caracter de fin de cadena.

	for(i=0; i<n; i++)
	{
		str2[i]=str2[i+n]=str1[i];
	}
	str2[n*2] = '\0'; // Aca en el ultimo lugar se le asigna el caracter de fin de cadena

	return str2;
}

int main()
{
	char *str, *p;

	printf("\nIngrese un string: \n\n");
	scanf("%s",str);

	p = duplicar(str);
	if(p != NULL)
	{
		printf("\nEl string duplicado es: %s\n\n",p);
	}
	else
	{
		printf("\nNo se pudo reservar memoria para el string.\n\n");
	}

	return 0;
}
