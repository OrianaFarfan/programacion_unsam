#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

struct rtc
{ //Son 14 elementos (0-13) --> 14 bytes
    unsigned char seg;
    unsigned char seg_alarm;
    unsigned char min;
    unsigned char min_alarm;
    unsigned char hora;
    unsigned char hora_alarm;
    unsigned char dia_sem;
    unsigned char dia_mes;
    unsigned char mes;
    unsigned char anio2;
    unsigned char regA;
    unsigned char regB;
    unsigned char regC;
    unsigned char regD;
};

int main()
{
    struct rtc v[10]; //El vector v va a ser del tiepo struct rtc. Un vector de 10 elementos que contiene 14 elementos (VER SI SE PUEDE CAMBIAR A ALGO DSITNTO DE 10)

    FILE *arch; // Se crea una variable puntero para ir barriendo el archivo

    int n = 1, i = 0, op, tam;

    arch = fopen("rtc.bin", "rb"); // Se abre el archivo binario por eso el rb
    if(arch == NULL)
    {
        printf("Error al leer el archivo. \n"); // Si el archivo estaba vacio o sea NULL, se va a mostrar este mensaje.
        exit(1);
    }

    while(n == 1) //Pero si n es 1 (donde en el primer caso es 1 porque ya se definio asi, pero como se llego hasta aca quiere decir que el archivo se abrio)
    {   //el n=1 definido al inico es solo para entrar en este fread
        n = fread(&v[i], sizeof(struct rtc), 1, arch); // donde se almacena, tamaño de lo que se va a leer, cuanto de ese sizeof se lee, con qué se lee
        i++; //cuento 1 elemento leido y se mueve el lugar del vector v
    }

    if(fclose(arch) != 0)
    {
        printf("Error al cerrar archivo. \n");
        exit(1);
    }

    printf("Elija una opcion: \n");
    printf("1-Informar tamanio del archivo. \n");
    printf("2-Mostrar hora. \n");
    printf("3-Mostrar anio. \n");
    printf("4-Informar AIE. \n");
    printf("5-Salir \n");
    scanf("%d", &op);

    while(op != 5)
    {
        switch(op)
        {
            case 1: tam = (i-1) * 64; //Claro como ya leyo esos primeros 13 primeros datos --> Es como que ya lei los 64 registros totales
                    printf("El tamanio del archivo es de %d bytes. \n", tam);
                    break;
            case 2: printf("Hora: %02x:%02x:%02x. \n", v[0].hora, v[0].min, v[0].seg);
                    break;
            case 3: printf("Anio: 20%02x. \n", v[0].anio2);
                    break;
            case 4: if((v[0].regB & 0x20) != 0) printf("El bit AIE esta en 1. \n");
                    else printf("El bit AIE esta en 0. \n");
                    break;
            default:    printf("Por favor, elija una opcion valida. \n");
                        break;
        }
        printf("Elija una opcion: \n");
        printf("1-Informar tamanio del archivo. \n");
        printf("2-Mostrar hora. \n");
        printf("3-Mostrar anio. \n");
        printf("4-Informar AIE. \n");
        printf("5-Salir \n");
        scanf("%d", &op);
    }

    return 0;
}
