#include <iostream>
#include "stages.h"
#define R_TYPE 0

int getOpCode(int inst){
    int opCode = inst >> 26;
    return opCode;
}

int getRS(int inst){
    int t = 0b000011111000000000000000000000;
    int rs= (inst & t)>>21;
    return rs;
}

int getRT(int inst){
    int t = 0b000000000111110000000000000000;
    int rt= (inst & t)>>16;
    return rt;
}

int getRD(int inst){
    int t = 0b000000000000001111100000000000;
    int rd= (inst & t) >> 11;
    return rd;
}

int getShamt(int inst){
    int t = 0b000000000000000000011111000000;
    int shamt= (inst & t) >> 6;
    return shamt;
}

int getFunc(int inst){
    int t = 0b000000000000000000000000111111;
    int func= (inst & t);
    return func;
}

int getImmed(int inst){
    int t = 0b000000000000001111111111111111;
    int immed= (inst & t);
    return immed;
}

int getImmedJ(int inst){
    int t = 0b000011111111111111111111111111;
    int immedj= (inst & t) ;
    return immedj;
}