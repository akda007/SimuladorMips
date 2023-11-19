
#define PC 31
#define SP 30

#define REG(cpu, x) cpu->registers[x]

typedef struct Cpu {
    float registers[32];
    float memory [8192];
} Cpu_T;


void get_dataRI(int *rd, int *rs, int *rt) {
    printf("Rd: ");
    scanf("%d", rd)
    printf("Rs: ");
    scanf("%d", rs)
    printf("Rt: ");
    scanf("%d", rt)
}

void get_dataLoad(int *rs, int *rt) {
    printf("Rs: ");
    scanf("%d", rs)
    printf("Rs: ");
    scanf("%d", rt)
}

void get_dataJ(int * data) {
    printf("Addres: ");
    scanf("%d", data);
}

void add(Cpu_T *cpu) {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    REG(cpu, rd) = REG(cpu, rs) + REG(cpu, rt);
}

void addu() {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
    
}

void and() {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code

}

void div() {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code

}

void divu() {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code

}

void jalr() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void jr() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void mfhi() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void mthi() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void mflo() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void mtlo() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void mfc0() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void mult() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void multu() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void nor() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void xor() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void or() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void slt() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void sltu() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void sll() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void srl() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void sra() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void sub() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void subu() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void j() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void jal() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void addi() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void addiu() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void andi() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void beq() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void blez() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void bne() {
    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code

}

void bgtz() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void lb() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void lbu() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void lhu() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void lui() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void lw() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void ori() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void sb() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void sh() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void slti() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void sltiu() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

void sw() {

    int rd, rs, rt;
    get_dataRI(&rd, &rs, &rt);

    //code
}

