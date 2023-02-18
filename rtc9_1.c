#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

struct rtc
{
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
    struct rtc v[2]; //Es un vector que va a contener 1 elemento cuya primera posicion es 0.
    FILE *arch;
    int n;

    if(ioperm(0x70, 2, 1)) // Aca se pide permiso porque vamos a usar los PORTS!!!!!!!
    {
        perror("ioperm");
        exit(1);
    }

    v[0].seg = leer(0x00); //En la posicion 0 del vector v (que es la unica en realidad), en el campo seg se le va a asignar lo que leyo del reg 0x00
    v[0].seg_alarm = leer(0x01);
    v[0].min = leer(0x02);
    v[0].min_alarm = leer(0x03);
    v[0].hora = leer(0x04);
    v[0].hora_alarm = leer(0x05);
    v[0].dia_sem = leer(0x06);
    v[0].dia_mes = leer(0x07);
    v[0].mes = leer(0x08);
    v[0].anio2 = leer(0x09);
    v[0].regA = leer(0x0A);
    v[0].regB = leer(0x0B);
    v[0].regC = leer(0x0C);
    v[0].regD = leer(0x0D);

    arch = fopen("rtc.bin", "wb"); // Se va a escribir en el archivo rtc.bin                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    en el archivo rtc.bin

    if(arch == NULL) // Se verifica que se abra bien el archivo que se va a usar
        {
            printf("Error al abrir el archivo. \n");
            exit(1);
        }


    n = fwrite(&v[0], sizeof(struct rtc), 1, arch); // O sea que va a escribir el contenido del vector en el arch, que tiene ese size y que graba de a 1
    if(n != 1) //Verifico que escribio algo, o sea que haya dado 1
        {
            printf("Error al escribir el archivo. \n");
            exit(1);
        }

    if(fclose(arch) != 0)
        {
                printf("Error al cerrar el archivo. \n");
                exit(1);
        }


    //Imprimo todo lo que guarde
    printf("Verificacion. \n");

    printf("%02x \n", v[0].seg);
    printf("%02x \n", v[0].seg_alarm);
    printf("%02x \n", v[0].min);
    printf("%02x \n", v[0].min_alarm);
    printf("%02x \n", v[0].hora);
    printf("%02x \n", v[0].hora_alarm);
    printf("%02x \n", v[0].dia_sem);
    printf("%02x \n", v[0].dia_mes);
    printf("%02x \n", v[0].mes);
    printf("%02x \n", v[0].anio2);
    printf("%02x \n", v[0].regA);
    printf("%02x \n", v[0].regB);
    printf("%02x \n", v[0].regC);
    printf("%02x \n", v[0].regD);

    if(ioperm(0x70, 2, 0))
    {
        perror("ioperm");
        exit(1);
    }

    return 0;
}
