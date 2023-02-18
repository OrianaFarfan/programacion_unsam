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
    unsigned char hora, min ,seg, c;
    int i;

    if(ioperm(0x70, 2, 1))
    {
        perror("ioperm");
        exit(1);
    }

    hora = leer(0x04);
    min = leer(0x02);
    seg = leer(0x00);

    seg += 5;

    escribir(seg, 0x01);
    escribir(min, 0x03);
    escribir(hora, 0x05);

    c = leer(0x0C);

    printf("Esperando alarma en 5 segundos..... \n");

    for(i=0; i<120; i++)
    {
        c = leer(0x0C);
        if(c & 0x20)
        {
            printf("Alarma!!!!!!!!!!!!. \n");
            exit(1);
        }
        usleep(500000);
    }

    if(ioperm(0x70, 2, 0))
    {
        perror("ioperm");
        exit(1);
    }

    return 0;
}
