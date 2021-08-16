//
// Created by abrolhus on 11/08/2021.
//

#ifndef MIPS_PIPELINE_STAGES_H
#define MIPS_PIPELINE_STAGES_H

//typedef int uint;
struct OpCodes
{
    int r = 0b0;
    int addi = 0b1000;
    int lw = 0b100011;
    int sw = 0b1010011;
    int beq = 0b000100;
    int bne = 0b000101;
    int j = 0b000010;
    int jal = 0b000011;
    //uint jr = 0b000000;
};

int getOpCode( int inst);
int getRS( int inst);
int getRT( int inst);
int getRD( int inst);
int getShamt( int inst);
int getFunc( int inst);
int getImmed( int inst);
int getImmedJ( int inst);
void verificaOpcod(int op);
void LeInstrucoes(int *t, int i);
void imprimeInst(int *t, int i);

#endif //MIPS_PIPELINE_STAGES_H
