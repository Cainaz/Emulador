#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "Leitor.h"

CHIP8 chip;
int main(int argc, char *argv[]){
    int sair=0;

    /*if(argc!=1){
        puts("sintaxe: somente o nome do arquivo!");
        exit(0);
    }*/
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

    while(!sair){
    //printf("entrou no loop. %d", i);
    emular(&chip);
    sair = tratar_teclas(&chip);

    }


return 0;
}
