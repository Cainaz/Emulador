#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "Leitor.h"

void carregarArquivo(const char narq, CHIP8 *chip,unsigned short pc){

    FILE *fp;
    fp = fopen(narq, "rb");
    int resultado =0;

    if (fp == NULL)
    {
      puts ("Erro ao ler arquivo \n");
      fclose (fp);
    }
    resultado = fread(chip->memory, sizeof(unsigned char),256,fp);
    printf("Numero de elementos lidos: %d",resultado);
    //p;
    fclose(fp);

}

void emular(CHIP8 *chip, unsigned short pc){

  // Fetch opcode
  unsigned short opcode = chip->memory[pc] << 8 | chip->memory[pc + 1];

  // Decode opcode
  switch(opcode & 0xF000)
  {

    case 0x0000:
        switch(opcode & 0x000F)
        {
            case 0x0000: // 0x00E0: Clears the screen
            // Execute opcode
            break;

            case 0x000E: // 0x00EE: Returns from subroutine
            // Execute opcode
            break;

            default:
                printf ("Opcode desconhecido [0x0000]: 0x%X\n", opcode);
        }
        break;

    case 0x1000:
        break;

    case 0x2000:
            chip->stack[chip->sp] = pc;
            ++chip->sp;
            pc = opcode & 0x0FFF;
        break;

    case 0x3000:
        break;

    case 0x4000:
        break;

    case 0x5000:
        break;

    case 0x6000:
        break;

    case 0x7000:
        break;

    case 0x8000:
        break;

    case 0x9000:
        break;

    case 0xA000: // ANNN: Sets I to the address NNN

      chip->I = opcode & 0x0FFF;
      pc += 2;
    break;

    case 0xB000:
        break;

    case 0xC000:
        break;

    case 0xD000:
        break;

    case 0xE000:
        break;

    case 0xF000:
        break;

    default:
      printf ("Unknown opcode: 0x%X\n", opcode);
  }


  // Update timers

  if(chip->delay_timer > 0)
    --chip->delay_timer;

  if(chip->sound_timer > 0)
  {
    if(chip->sound_timer == 1)
      printf("BEEP!\n");
    --chip->sound_timer;
  }

}




