#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "Leitor.h"

CHIP8 chip;
int main(int argc, char *argv[]){

    /*if(argc!=1){
        puts("sintaxe: somente o nome do arquivo!");
        exit(0);
    }*/
    int i = 0;
    const char *narq= NULL;
    narq = argv[1];
    printf("nome do arquivo: %s\n",narq);

    inicializar(&chip); //inicializando variaveis do chip8
    carregarArquivo(narq, &chip); //carrega os arquivos na memoria

    if(!abrir_tela())
  {
    puts("Falha ao inicializar a Allegro");
    exit(EXIT_FAILURE);
}

    for(;;){
    emular(&chip);
    //funcao que emula
    if(chip.drawflag == 1)
    desenhar(&chip);

    if(chip.memory[i] == chip.memory[4096])
        return 0;
    i++;
    }
return 0;
}
