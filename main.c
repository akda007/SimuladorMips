#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "mips.h"

typedef enum {
    I, R, J
} InstructionType;

#define compare(i, c, func) if (strcmp(i, c) == 0) (func)(cpu) 

void parse_instruction(Cpu_T *cpu, char * instruction) {
    InstructionType type;    

    compare(instruction, "add", add);
    compare(instruction, "addu", addu);
    compare(instruction, "and", and);
    compare(instruction, "div", div);
    compare(instruction, "divu", divu);
    compare(instruction, "jalr", jalr);
    compare(instruction, "jr", jr);
    compare(instruction, "mfhi", mfhi);
    compare(instruction, "mthi", mthi);
    compare(instruction, "mflo", mflo);
    compare(instruction, "mtlo", mtlo);
    compare(instruction, "mfc0", mfc0);
    compare(instruction, "mult", mult);
    compare(instruction, "multu", multu);
    compare(instruction, "nor", nor);
    compare(instruction, "xor", xor);
    compare(instruction, "or", or);
    compare(instruction, "slt", slt);
    compare(instruction, "sltu", sltu);
    compare(instruction, "sll", sll);
    compare(instruction, "srl", srl);
    compare(instruction, "sra", sra);
    compare(instruction, "sub", sub);
    compare(instruction, "subu", subu);
    compare(instruction, "j", j);
    compare(instruction, "jal", jal);
    compare(instruction, "addi", addi);
    compare(instruction, "addiu", addiu);
    compare(instruction, "andi", andi);
    compare(instruction, "beq", beq);
    compare(instruction, "blez", blez);
    compare(instruction, "bne", bne);
    compare(instruction, "bgtz", bgtz);
    compare(instruction, "lb", lb);
    compare(instruction, "lbu", lbu);
    compare(instruction, "lhu", lhu);
    compare(instruction, "lui", lui);
    compare(instruction, "lw", lw);
    compare(instruction, "ori", ori);
    compare(instruction, "sb", sb);
    compare(instruction, "sh", sh);
    compare(instruction, "slti", slti);
    compare(instruction, "sltiu", sltiu);
    compare(instruction, "sw", sw);

}

int main() {
    puts("Mips simulator.");

    Cpu_T cpu;

    char op[6];
    uint8_t rs, rt, rd;

    for(;;) {
        printf("Digite uma operacao:\n> ");
        scanf("%5s", op);

        parse_instruction(op);

        cpu.memory[PC]++;        
    }
    return 0;
}