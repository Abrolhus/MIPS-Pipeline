#include "../Headers/Alu.h"

int Alu::act(int a, int b, int controlInput, int& zeroFlag) {
    int result = 0;
    zeroFlag = 0;
    switch(controlInput){
        case CI_ADD:
            result = add_f(a, b);
            break;
        case CI_SUB:
            result = sub_f(a, b);
            break;
        case CI_OR:
            result = or_f(a, b);
            break;
        case CI_AND:
            result = and_f(a, b);
            break;
        case CI_SLT:
            result = slt_f(a, b);
            break;
        case CI_ADDI:
            result = addi_f(a, b);
            break;
        case CI_SLL:
            result = sll_f(a, b);
            break;
        default:
            exit(EXIT_FAILURE);
    }
    if(result == 0){
        zeroFlag = 1;
    }
    return result;
}

int Alu::add_f(int a, int b) {
    return a + b;
}
int Alu::sub_f(int a, int b) {
    return a - b;
}
int Alu::and_f(int a, int b) {
    return a & b;
}
int Alu::or_f(int a, int b) {
    return a | b;
}
int Alu::addi_f(int a, int b) {
    return (unsigned int)a + (unsigned int)b;
}
int Alu::slt_f(int a, int b) {
    return a < b; // TODO(Samuel): check if this slt is correct;
}
int Alu::sll_f(int a, int b) {
    return a << b;
}
