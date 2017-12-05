//#ifndef LEITOR_H_INCLUDED
//#define LEITOR_H_INCLUDED
#define FPS 180.0
#define LARGURA_TELA 640
#define ALTURA_TELA 320
#define memsize 4096
#define resolucao 64*32
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
    unsigned char graphics[resolucao];
    bool drawflag;
}CHIP8;

//funcoes
void inicializar_chip8(CHIP8 *);
void carregar_jogo(const char* , CHIP8 *);
void emular(CHIP8 *);
int iniciar_alegro();
int ler_desenhar(CHIP8 *,const char*);
void reset(CHIP8 *, const char*);



