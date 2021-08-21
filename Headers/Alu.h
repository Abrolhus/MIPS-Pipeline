#ifndef PIPELINE_ALU_H
#define PIPELINE_ALU_H

#include <stdlib.h>
#define CI_AND 0b0000
#define CI_OR 0b0001
#define CI_ADD 0b0010
#define CI_ADDI 0b0011
#define CI_SLL 0b0100
#define CI_SUB 0b0110
#define CI_SLT 0b0111
class Alu {
public:
    static int act(int A, int B, int controlInput, int& zeroFlag);
    Alu();
private:
    static int add_f(int a, int b);
    static int add_f_lw(int a, int b);
    static int sub_f(int a, int b);
    static int sub_f_beq(int a, int b);
    static int and_f(int a, int b);
    static int or_f(int a, int b);
    static int slt_f(int a, int b);
    static int addi_f(int a, int b);
    static int sll_f(int a, int b);
};

#endif //PIPELINE_ALU_H
