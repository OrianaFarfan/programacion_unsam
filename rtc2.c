#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

void leer(unsigned char reg)
{
    unsigned char veri, d;

    outb(0x0A, 0x70);
    veri = inb(0x71);
    if((veri & 0x80) != 0) usleep(1984);

    outb(reg, 0x70);
    d = inb(0x71);

    printf("El valor del puerto seleccionado es: 0x%02x. \t-->", d);
}

int main()
{
    int i;

    if(ioperm(0x70, 2, 1))
    {
        perror("ioperm");
        exit(1);
    }

    for(i=0; i<14; i++)
    {
        switch(i)
        {
            case 0: leer(0x00);
                    printf("Segundos. \n");
                    break;
            case 1: leer(0x01);
                    printf("Segundos de alarma. \n");
                    break;
            case 2: leer(0x02);
                    printf("Minutos. \n");
                    break;
            case 3: leer(0x03);
                    printf("Minutos de alarma. \n");
                    break;
            case 4: leer(0x04);
                    printf("Hora. \n");
                    break;
            case 5: leer(0x05);
                    printf("Hora de alarma. \n");
                    break;
            case 6: leer(0x06);
                    printf("Dia de semana. \n");
                    break;
            case 7: leer(0x07);
                    printf("Dia de mes. \n");
                    break;
            case 8: leer(0x08);
                    printf("Mes. \n");
                    break;
            case 9: leer(0x09);
                    printf("Anio (ultimos 2 digitos). \n");
                    break;
            case 10:    leer(0x0A);
                        printf("Registro A. \n");
                        break;
            case 11:    leer(0x0B);
                        printf("Registro B. \n");
                        break;
            case 12:    leer(0x0C);
                        printf("Registro C. \n");
                        break;
            case 13:    leer(0x0D);
                        printf("Registro D. \n");
                        break;
        }
    }

    if(ioperm(0x70, 2, 0))
    {
        perror("ioperm");
        exit(1);
    }

    return 0;
}
