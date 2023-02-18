#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

unsigned char leer(unsigned char reg)
{
    outb(reg, 0x70);
    return inb(0x71);
}

void escribir(unsigned char valor, unsigned char reg)
{
    outb(reg, 0x70);
    outb(valor, 0x71);
}

int main()
{
    unsigned char regA, regB, regC;
    int i;

    if(ioperm(0x70, 2, 1))
    {
        perror("ioperm");
        exit(1);
    }

    regA = leer(0x0A);
    regA = regA | 0x0E; // --> regA|=0x0E 0000 1110 donde el | es para escribir
    regA = regA & 0xFE;// --> regA|=0xFE 1111 1110 donde el & es para leer --> La mascara tiene 1 en donde quiere leer
    escribir(0x0A, regA); // Aca escribe lo que se puso con |

    regB = leer(0x0B);
    regB = regB | 0x40; //--> regB|=0x40 0100 0000
    escribir(0x0B, regB);

    regC = leer(0x0C);

    printf("Esperando alarma de aparecer * 4 veces por segundo. \n");

    for(i=0; i<80; i++)
    {
        regC = leer(0x0C);
        if(regC & 0x40)
        {
            printf(" *a \n");
        }
        usleep(125000);
    }

    printf("Termine. \n");

    if(ioperm(0x70, 2, 0))
    {
        perror("ioperm");
        exit(1);
    }

    return 0;
}
