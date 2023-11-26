
#include <stdio.h>
#include <stdint.h>

#define PC 31
#define SP 30
#define RA 29

//Macro para facilitar o acesso aos registradores
#define REG(cpu, x) cpu->registers[x]
#define RAM(cpu, x) cpu->memory[x]

#define ABS(x) x < 0 ? (x * -1) : x

typedef struct Cpu {
    int32_t registers[32];
    uint8_t memory [8192];
    int64_t HI, LO;
} Cpu_T;

void get_dataImediate(int *rd, int *rs, int *imediate) {
    printf("Rd: ");
    scanf("%d", rd);
    printf("Rs: ");
    scanf("%d", rs);
    printf("i: ");
    scanf("%d", imediate);

    printf("Le registradores...\n\n");
    printf("ULA: Operacao da ula\n\n");
}

void get_condJ(int *rs, int *rt, int *label_addres) {
    printf("Rs: ");
    scanf("%d", rs);
    printf("Rt: ");
    scanf("%d", rt);
    printf("Label_Addres: ");
    scanf("%d", label_addres);

    printf("Le registradores...\n\n");
    printf("ULA: Operacao da ula\n\n");
}


void get_dataRI(int *rd, int *rs, int *rt) {
    printf("Rd: ");
    scanf("%d", rd);
    printf("Rs: ");
    scanf("%d", rs);
    printf("Rt: ");
    scanf("%d", rt);

    printf("Le registradores...\n\n");
    printf("ULA: Operacao da ula\n\n");
}

void get_dataLoad(int *rs, int *rt) {
    printf("Rs: ");
    scanf("%d", rs);
    printf("Rt: ");
    scanf("%d", rt);

    printf("Le registradores...\n\n");
    printf("ULA: Operacao da ula\n\n");
}

void get_Reg(int *reg, int * ram) {
    printf("Reg: ");
    scanf("%d", reg);
    printf("Ram: ");
    scanf("%d", ram);

    printf("Le registradores...\n\n");
    printf("ULA: Operacao da ula\n\n");
}

void get_dataJ(int * data) {
    printf("Addres: ");
    scanf("%d", data);

    printf("Le registradores...\n\n");
    printf("ULA: Operacao da ula\n\n");
}

void print_R(Cpu_T * cpu, int rd, int rs, int rt) {
    printf("Escreve registradores...\n\n");


    printf("R%d: 0x%02X | dec: (%d)\n", rd, REG(cpu, rd), REG(cpu, rd));
    printf("R%d: 0x%02X | dec: (%d)\n", rs, REG(cpu, rs), REG(cpu, rs));
    printf("R%d: 0x%02X | dec: (%d)\n", rt, REG(cpu, rt), REG(cpu, rt));
}

void print_RI(Cpu_T * cpu, int rd, int rs) {
    printf("Escreve registradores...\n\n");

    
    printf("R%d: 0x%02X | dec: (%d)\n", rd, REG(cpu, rd), REG(cpu, rd));
    printf("R%d: 0x%02X | dec: (%d)\n", rs, REG(cpu, rs), REG(cpu, rs));
}

void print_Reg(Cpu_T *cpu, int r) {
    printf("Escreve registradores...\n\n");

    
    printf("R%d: 0x%02X | dec: (%d)\n", r, REG(cpu, r), REG(cpu, r));
}

void printMem(Cpu_T *cpu, int ram, int offset) {
    printf("Operacoes na memoria(read/write)\n");
    printf("Escreve registradores...\n\n");

    
    printf("Hex_RAM(0x%02X --> 0x%02X): ", ram, ram + offset - 1);

    for (int i = 0; i < offset; i++) {
        printf("%02X ", RAM(cpu, ram + i));
    }

    printf("\n");
}

void add(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = REG(cpu, rs) + REG(cpu, rt);

    print_R(cpu, rd, rs, rt);
}

void li(Cpu_T *cpu) {
    int rd, i;
    printf("Rd: ");
    scanf("%d", &rd);
    printf("i: ");
    scanf("%d", &i);

    REG(cpu, rd) = i;
    print_Reg(cpu, rd);
}

void addu(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rs) = ABS(REG(cpu,rs));
    REG(cpu, rt) = ABS(REG(cpu,rt));

    REG(cpu, rd) = REG(cpu, rs) + REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}

void neg(Cpu_T *cpu) {
    int rd, rs;
    get_dataLoad(&rd, &rs);

    REG(cpu, rd) = ~REG(cpu, rs);
    print_Reg(cpu, rd);
}

void negu(Cpu_T *cpu) {
    int rd, rs;
    get_dataLoad(&rd, &rs);

    REG(cpu, rd) = ABS(REG(cpu, rd));

    REG(cpu, rd) = ~REG(cpu, rs);
    print_Reg(cpu, rd);
}

void and(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = REG(cpu, rs) & REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}

void div(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = (int)REG(cpu, rs) / (int)REG(cpu, rt);
    print_R(cpu, rd, rs, rt);

}

void rem(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = (int)REG(cpu, rs) % (int)REG(cpu, rt);
    print_R(cpu, rd, rs, rt);

}


void remu(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rs) = ABS(REG(cpu,rs));
    REG(cpu, rt) = ABS(REG(cpu,rt));

    REG(cpu, rd) = (int)REG(cpu, rs) % (int)REG(cpu, rt);
    print_R(cpu, rd, rs, rt);

}

void divu(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rs) = ABS(REG(cpu,rs));
    REG(cpu, rt) = ABS(REG(cpu,rt));

    REG(cpu, rd) = REG(cpu, rs) / REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}


void jr(Cpu_T *cpu) {
    int rs;
    get_dataJ(&rs);

    REG(cpu, PC) = REG(cpu, rs);
    //code
}

void mfhi(Cpu_T *cpu) {
    int rd;
    printf("Reg: ");
    scanf("%d", &rd);
    
    REG(cpu, rd) = cpu->HI;
}


void mflo(Cpu_T *cpu) {
    int rd;
    printf("Reg: ");
    scanf("%d", &rd);
    
    REG(cpu, rd) = cpu->LO;
}

void mult(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = REG(cpu, rs) * REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}

void mulou(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rs) = ABS(REG(cpu, rs));
    REG(cpu, rt) = ABS(REG(cpu, rt));

    REG(cpu, rd) = REG(cpu, rs) * REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}

void multu(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rs) = ABS(REG(cpu,rs));
    REG(cpu, rt) = ABS(REG(cpu,rt));

    REG(cpu, rd) = REG(cpu, rs) * REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}

void nor(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = ~(REG(cpu, rs) | REG(cpu, rt));
    print_R(cpu, rd, rs, rt);
}

void xor(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = REG(cpu, rs) ^ REG(cpu, rt);
    print_R(cpu, rd, rs, rt);

}

void xori(Cpu_T *cpu) {
    int rd, rs, i;
    get_dataImediate(&rd, &rs, &i);

    REG(cpu, rd) = REG(cpu, rs) ^ i;
    print_RI(cpu, rd, rs);
}

void or(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
    REG(cpu, rd) = REG(cpu, rs) | REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}


void sll(Cpu_T *cpu) {
    int rd, rs, i;
    get_dataImediate(&rd, &rs, &i);

    //code
    REG(cpu, rd) = REG(cpu, rs) << i;
    print_RI(cpu, rd, rs);
}

void srl(Cpu_T *cpu) {
    int rd, rs, i;
    get_dataImediate(&rd, &rs, &i);

    //code
    REG(cpu, rd) = REG(cpu, rs) >> i;
    print_RI(cpu, rd, rs);
}


void sra(Cpu_T *cpu) {
    int rd, rs, i;
    get_dataImediate(&rd, &rs, &i);


    REG(cpu, rd) = REG(cpu, rs) << i;
    print_RI(cpu, rd, rs);
}

void rol(Cpu_T *cpu) {
    int rd, rs, i;
    get_dataImediate(&rd, &rs, &i);


    REG(cpu, rd) = REG(cpu, rs) << i;
    print_RI(cpu, rd, rs);
}

void ror(Cpu_T *cpu) {
    int rd, rs, i;
    get_dataImediate(&rd, &rs, &i);


    REG(cpu, rd) = REG(cpu, rs) >> i;
    print_RI(cpu, rd, rs);
}
void sub(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
    REG(cpu, rd) = REG(cpu, rs) - REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}

void subu(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rs) = ABS(REG(cpu,rs));
    REG(cpu, rt) = ABS(REG(cpu,rt));

    //code
    REG(cpu, rd) = REG(cpu, rs) - REG(cpu, rt);
    print_R(cpu, rd, rs, rt);
}

void j(Cpu_T *cpu) {
    int addres;
    get_dataJ(&addres);

    //code
    REG(cpu, PC) = addres;
}

void jal(Cpu_T *cpu) {
    int addres;
    get_dataJ(&addres);

    //code
    REG(cpu, RA) = REG(cpu, PC);
    REG(cpu, PC) = addres;
}

void addi(Cpu_T *cpu) {
    int rd, rs, imediate;
    get_dataImediate(&rd, &rs, &imediate);

    REG(cpu, rd) = REG(cpu, rs) + imediate;

    //code
    print_RI(cpu, rd, rs);
}

void addiu(Cpu_T *cpu) {
    int rd, rs, imediate;
    get_dataImediate(&rd, &rs, &imediate);

    REG(cpu, rs) = ABS(REG(cpu,rs));
    imediate = ABS(imediate);
    //code
    
    REG(cpu, rd) = REG(cpu, rs) + imediate;
    print_RI(cpu, rd, rs);
}

void andi(Cpu_T *cpu) {
    int rd, rs, imediate;
    get_dataImediate(&rd, &rs, &imediate);

    REG(cpu, rd) = REG(cpu, rs) & imediate;
    print_RI(cpu, rd, rs);
}

void beq(Cpu_T *cpu) {
    int rs, rt, addres;

    get_condJ(&rs, &rt, &addres);

    //code
    if (REG(cpu, rs) == REG(cpu, rt)) {
        REG(cpu, PC) = addres;
    }
}

void bne(Cpu_T *cpu) {
    int rs, rt, addres;

    get_condJ(&rs, &rt, &addres);

    //code
    if (REG(cpu, rs) != REG(cpu, rt)) {
        REG(cpu, PC) = addres;
    }
}

void ble(Cpu_T *cpu) {
    int rs, rt, addres;

    get_condJ(&rs, &rt, &addres);

    //code
    if (REG(cpu, rs) <= REG(cpu, rt)) {
        REG(cpu, PC) = addres;
    }
}
void blt(Cpu_T *cpu) {
    int rs, rt, addres;

    get_condJ(&rs, &rt, &addres);

    //code
    if (REG(cpu, rs) < REG(cpu, rt)) {
        REG(cpu, PC) = addres;
    }
}


void bgt(Cpu_T *cpu) {
    int rs, rt, addres;

    get_condJ(&rs, &rt, &addres);

    //code
    if (REG(cpu, rs) > REG(cpu, rt)) {
        REG(cpu, PC) = addres;
    }
}

void bge(Cpu_T *cpu) {
    int rs, rt, addres;

    get_condJ(&rs, &rt, &addres);

    //code
    if (REG(cpu, rs) >= REG(cpu, rt)) {
        REG(cpu, PC) = addres;
    }
}

void lb(Cpu_T *cpu) {
    int rd, ram;
    get_Reg(&rd, &ram);


    REG(cpu, rd) = RAM(cpu, ram);

    printMem(cpu, ram, 1);
    print_Reg(cpu, rd);
}



void lw(Cpu_T *cpu) {
    int rd, ram;
    get_Reg(&rd, &ram);

    REG(cpu, rd) = (int32_t)RAM(cpu, ram+3);

    REG(cpu, rd) = REG(cpu, rd) | ((int32_t)RAM(cpu, ram+2) << 8);
    REG(cpu, rd) = REG(cpu, rd) | ((int32_t)RAM(cpu, ram+1) << 16);
    REG(cpu, rd) = REG(cpu, rd) | ((int32_t)RAM(cpu, ram) << 24);
    
    printMem(cpu, ram, 4);
    print_Reg(cpu, rd);
}

void ori(Cpu_T *cpu) {
    int rd, rs, imediate;
    get_dataImediate(&rd, &rs, &imediate);

    //code
    REG(cpu, rd) = REG(cpu, rs) | imediate;
}

void sb(Cpu_T *cpu) {
    int rs, ram;
    get_Reg(&rs, &ram);

    RAM(cpu, ram) = REG(cpu, rs) & 0xff;
    printMem(cpu, ram, 1);
}

void move(Cpu_T *cpu){

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = REG(cpu, rs);
    
    print_R(cpu, rd, rs, rt);
}

void sw(Cpu_T *cpu) {
    int rs, ram;
    get_Reg(&rs, &ram);

    
    RAM(cpu, ram+3) =  REG(cpu, rs)          & 0xff;
    RAM(cpu, ram+2) = (REG(cpu, rs) >> 8)    & 0xff;
    RAM(cpu, ram+1) = (REG(cpu, rs) >> 16)   & 0xff;
    RAM(cpu, ram)   = (REG(cpu, rs) >> 24)   & 0xff;

    printMem(cpu, ram, 4);
}

