#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

unsigned char leer(unsigned char reg)
{
    unsigned char veri, d;

    outb(0x0A, 0x70);
    veri = inb(0x71);
    if((veri & 0x80) != 0) usleep(1984); // = if((veri & 0x80))

    outb(reg, 0x70);
    return inb(0x71); //hacia el codigo C
}

void hexadecimal(unsigned char d)
{
    int hexa[8] = {'\0'}, i = 0;

    while(d != 0)
    {
        hexa[i] = d % 16;
        d /= 16; // Es d=d/16
        i++;
    }

    i--;

    while(i >= 0)
    {
        switch(hexa[i])
        {
            case 10: printf("A");
                    break;
            case 11: printf("B");
                    break;
            case 12: printf("C");
                    break;
            case 13: printf("D");
                    break;
            case 14: printf("E");
                    break;
            case 15: printf("F");
                    break;
            default: printf("%d", hexa[i]);
                    break;
        }
        i--;
    }
    printf("\n");
}

int main()
{
    unsigned char d;
    int op;

    if(ioperm(0x70, 2, 1))
    {
        perror("ioperm");
        exit(1);
    }

    printf("Ingrese el port que desea leer (0-13) (termina con 14). \n");
    scanf("%d", &op);

    while(op != 14)
    {
        switch(op)
        {
            case 0: d = leer(0x00);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 1: d = leer(0x01);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 2: d = leer(0x02);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 3: d = leer(0x03);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 4: d = leer(0x04);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 5: d = leer(0x05);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 6: d = leer(0x06);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 7: d = leer(0x07);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 8: d = leer(0x08);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 9: d = leer(0x09);
                    printf("Con el % : %02x\n",d);
                    printf("Con la funcion hexa : ");
                    hexadecimal(d);
                    printf("\n");
                    break;
            case 10:    d = leer(0x0A);
                        printf("Con el % : %02x\n",d);
                        printf("Con la funcion hexa : ");
                        hexadecimal(d);
                        printf("\n");
                        break;
            case 11:    d = leer(0x0B);
                        printf("Con el % : %02x\n",d);
                        printf("Con la funcion hexa : ");
                        hexadecimal(d);
                        printf("\n");
                        break;
            case 12:    d = leer(0x0C);
                        printf("Con el % : %02x\n",d);
                        printf("Con la funcion hexa : ");
                        hexadecimal(d);
                        printf("\n");
                        break;
            case 13:    d = leer(0x0D);
                        printf("Con el % : %02x\n",d);
                        printf("Con la funcion hexa : ");
                        hexadecimal(d);
                        printf("\n");
                        break;
            default:    printf("Por favor, elija una opcion valida. \n");
                        break;
        }
        printf("Ingrese el port que desea leer (0-13) (termina con 14). \n");
        scanf("%d", &op);
    }

    if(ioperm(0x70, 2, 0))
    {
        perror("ioperm");
        exit(1);
    }

    return 0;
}
