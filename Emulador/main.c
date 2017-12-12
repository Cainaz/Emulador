#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "Leitor.h"

CHIP8 chip;
int main(int argc, char *argv[]){
    int sair=0;
    const char *narq= NULL;
    narq = argv[1];
    printf("Nome do arquivo: %s\n",narq);


    inicializar_chip8(&chip); //inicializando variaveis do chip8
    carregar_jogo(narq, &chip); //carrega os arquivos na memoria

    if(!iniciar_alegro()) //inicializando alegro
  {
    puts("Falha ao inicializar a Allegro");
    exit(EXIT_FAILURE);
    return 0;
}
    while(!sair){
    emular(&chip);     //Fun��o de leitura dos opcodes
    sair = ler_desenhar(&chip, narq); //fun��o para desenhar a tela e ler as teclas
    }

return 0;
}
