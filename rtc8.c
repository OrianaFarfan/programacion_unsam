#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#define P 0x70

unsigned char in (unsigned char reg){
	outb (reg, P);
    return inb(P + 1);
}

void out (unsigned char valor, unsigned char reg){
	outb (reg, P);
	outb (valor, P + 1);
 }

int main(){
	unsigned char hora, min, seg, a, b, c, i;

    if (ioperm(P, 2, 1)) {perror("ioperm"); exit(1);}

    out (0x45, 0x01);
    out (0xFF, 0x03);
    out (0xFF, 0x05);

    c = in (0x0C);
    printf ("Esperando las alarmas...\n");
    for (i = 0; i < 180; i++){
        c = in (0x0C);
        if (c & 0x20)
	        printf ("Alarma\n");
        usleep(1000000);
    }
    if (ioperm(P, 2, 0)) {perror("ioperm"); exit(1);}
    return 0;
}
