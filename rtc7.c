#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

unsigned char leer(unsigned char reg)
{
    unsigned char veri;

    outb(0x0A, 0x70);
    veri = inb(0x71);
    if((veri & 0x80) != 0) usleep(1984);
    
    outb(reg, 0x70);
    return inb(0x71);
}

int main()
{
    unsigned char hora, min, seg, anio1, anio2;

    if(ioperm(0x70, 2, 1))
    {
        perror("ioperm");
        exit(1);
    }

    hora = leer(0x04);
    min = leer(0x02);
    seg = leer(0x00);
    anio1 = leer(0x32);
    anio2 = leer(0x09);
    
    printf("Anio: %02x%02x. Hora: %02x:%02x:%02x. \n", anio1, anio2, hora, min, seg);
    
    if(ioperm(0x70, 2, 0))
    {
        perror("ioperm");
        exit(1);
    }

    return 0;
}