#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "mips.h"

#define compare(i, c, func) if (strcmp(i, c) == 0) (func)(cpu) 
void parse_instruction(Cpu_T *cpu, char * instruction) {
    printf("Instruction memory: busca de operacao\n\n");

    printf("Incrementa PC.\n");
    cpu->registers[PC] += 4;

    //Macros para escolher uma operaçao
    printf("Decodifica instrucao:\n\n");
    
    compare(instruction,   "add",   add);
    compare(instruction,  "move",  move);
    compare(instruction,  "addu",  addu);
    compare(instruction,   "and",   and);
    compare(instruction,   "div",   div);
    compare(instruction,  "divu",  divu);
    compare(instruction,    "jr",    jr);
    compare(instruction,  "mfhi",  mfhi);
    compare(instruction,  "mflo",  mflo);
    compare(instruction,  "mult",  mult);
    compare(instruction, "multu", multu);
    compare(instruction,   "nor",   nor);
    compare(instruction,   "xor",   xor);
    compare(instruction,    "or",    or);
    compare(instruction,   "sll",   sll);
    compare(instruction,   "srl",   srl);
    compare(instruction,   "sra",   sra);
    compare(instruction,   "sub",   sub);
    compare(instruction,  "subu",  subu);
    compare(instruction,     "j",     j);
    compare(instruction,   "jal",   jal);
    compare(instruction,  "addi",  addi);
    compare(instruction, "addiu", addiu);
    compare(instruction,  "andi",  andi);
    compare(instruction,   "beq",   beq);
    compare(instruction,   "bne",   bne);
    compare(instruction,    "lb",    lb);
    compare(instruction,    "lw",    lw);
    compare(instruction,   "ori",   ori);
    compare(instruction,    "sb",    sb);
    compare(instruction,    "sw",    sw);
    compare(instruction,    "li",    li);
}

int main() {
    puts("Mips simulator.");

    Cpu_T cpu;
    cpu.HI = 0;
    cpu.LO = 0;

    //Initialize registers to 0
    for (int i = 0; i < 32; i++) {
        cpu.registers[i] = 0;
    }

    char op[6];

    for(;;) {
        printf("Digite uma operacao:\n> ");
        scanf("%5s", op);

        printf("PC: 0x%x\n", cpu.registers[PC]);
        parse_instruction(&cpu, op);

        printf("PC: 0x%x\n", cpu.registers[PC]);
    }
    return 0;
}