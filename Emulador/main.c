#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "Leitor.h"
#define MAX_FILENAME 255

int main(int argc, char argv[]){
    //funções de base

    unsigned char memory[4096];
    unsigned char V[16];
    unsigned short I;
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short stack[16];
    unsigned short sp;
    unsigned char key[16];


    if(argc!=3){
        puts("sintaxe: neander <prog.bin> pc");
        exit(0);
    }
    const char narq[MAX_FILENAME+1];
    strncpy(narq, argv[1], MAX_FILENAME);
    unsigned short pc = atoi(argv[2]);
    printf("%s:%d\n",narq,pc);


    carregarArquivo(const char narq, unsigned char *memory,unsigned short pc);
    emular(unsigned char *memory,unsigned short pc, unsigned short *I);

return 0;
}
