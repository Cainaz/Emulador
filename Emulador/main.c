#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "Leitor.h"

#define MAX_FILENAME 255

CHIP8 chip;
int main(int argc, char argv[]){


    if(argc!=3){
        puts("sintaxe: neander <prog.bin> pc");
        exit(0);
    }
    const char narq[MAX_FILENAME+1];
    strncpy(narq, argv[1], MAX_FILENAME);
    unsigned short pc = atoi(argv[2]);
    printf("%s:%d\n",narq,pc);
    chip.pc = pc;
    inicializar(&chip); //inicializando variaveis do chip8
    carregarArquivo(narq, &chip); //carrega os arquivos na memoria
    emular(&chip); //funcao que emula

return 0;
}
