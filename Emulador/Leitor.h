#ifndef LEITOR_H_INCLUDED
#define LEITOR_H_INCLUDED

#endif // LEITOR_H_INCLUDED
typedef struct chip8
{
    unsigned char memory[4096];
    unsigned char V[16];
    unsigned short I;
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short stack[16];
    unsigned short sp;
    unsigned char key[16];
}CHIP8;
//funcoes
void carregarArquivo(const char narq, CHIP8 *chip,unsigned short pc);
void emular(CHIP8 *chip, unsigned short pc);


