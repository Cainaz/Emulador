//#ifndef LEITOR_H_INCLUDED
//#define LEITOR_H_INCLUDED
#define memsize 4096

//#endif // LEITOR_H_INCLUDED


typedef struct chip8
{
    unsigned short opcode;
    unsigned char memory[4096];
    unsigned char V[16];
    unsigned short I;
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short stack[16];
    unsigned short sp;
    unsigned char key[16];
    unsigned short pc;
    unsigned char graphics[64 * 32];
    int drawflag;
}CHIP8;

//funcoes
void inicializar(CHIP8 *);
void carregarArquivo(const char* , CHIP8 *);
void emular(CHIP8 *);
int desenhar(CHIP8 *);
int abrir_tela();



