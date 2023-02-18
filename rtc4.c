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


    for(j=7; j>=0; j--) printf("\t  %d", bina[j]);

    printf("\n");
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

    for(i=0; i<4; i++)
    {
        switch(i)
        {
            case 0: d = leer(0x0A);
                    printf("Registro A. \n");
                    printf("  ");
                    binario(d);
                    printf("\t UIP |\t DV2 |\t DV1 |\t DV0 |\t RS3 |\t RS2 |\t RS1 |\t RS0 \n\n");
                    break;
            case 1: d = leer(0x0B);
                    printf("Registro B. \n");
                    printf("");
                    binario(d);
                    printf("\t SET |\t PIE |\t AIE |\t UIE |\t SQWE |\t DM |\t 24/12 |  DSE \n\n");
                    break;
            case 2: d = leer(0x0C);
                    printf("Registro C. \n");
                    printf("  ");
                    binario(d);
                    printf("\t IRQF |\t PF |\t AF |\t UF |\t  0  |\t  0  |\t  0  |\t  0  \n\n");
                    break;
            case 3: d = leer(0x0D);
                    printf("Registro D. \n");
                    printf("  ");
                    binario(d);
                    printf("\t VRT |\t  0  |\t  0  |\t  0 |\t  0  |\t  0  |\t  0  |\t  0 \n\n");
                    break;
        }
    }

    return 0;
}
