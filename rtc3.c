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

void binario(unsigned char d)
{
    char bina[8] = {'\0'};
    int i = 0, j;

    while(d > 0)
    {
        bina[i] = d % 2;
        d /= 2;
        i++;
    }

    printf("Binario: 0b");

    for(j=7; j>=0; j--) printf("%d", bina[j]);

}

int main()
{
    unsigned char d;
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
            case 0: d = leer(0x00);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Segundos. \n");
                    break;
            case 1: d = leer(0x01);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Segundos de alarma. \n");
                    break;
            case 2: d = leer(0x02);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Minutos. \n");
                    break;
            case 3: d = leer(0x03);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Minutos de alarma. \n");
                    break;
            case 4: d = leer(0x04);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Hora. \n");
                    break;
            case 5: d = leer(0x05);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Hora de alarma. \n");
                    break;
            case 6: d = leer(0x06);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Dia de semana. \n");
                    break;
            case 7: d = leer(0x07);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Dia de mes. \n");
                    break;
            case 8: d = leer(0x08);
                    printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Mes. \n");
                    break;
            case 9: d = leer(0x09);
                     printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                    binario(d);
                    printf("\t|\t Anio (ultimos 2 digitos). \n");
                    break;
            case 10:    d = leer(0x0A);
                        printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                        binario(d);
                        printf("\t|\t Registro A. \n");
                        break;
            case 11:    d = leer(0x0B);
                        printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                        binario(d);
                        printf("\t|\t Registro B. \n");
                        break;
            case 12:    d = leer(0x0C);
                        printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                        binario(d);
                        printf("\t|\t Registro C. \n");
                        break;
            case 13:    d = leer(0x0D);
                        printf("El valor del puerto seleccionado es: 0x%02x.\t|\t", d);
                        binario(d);
                        printf("\t|\t Registro D. \n");
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
