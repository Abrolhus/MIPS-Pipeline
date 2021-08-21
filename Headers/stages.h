//
// Created by abrolhus on 11/08/2021.
//

#ifndef MIPS_PIPELINE_STAGES_H
#define MIPS_PIPELINE_STAGES_H
#include <string>
#include "BancoDeRegistradores.h"
#include "Alu.h"
#include "IF_ID.h"
#include "Id_ex.h"
#include "Ex_mem.h"
#include "MEM_WD.h"
#include "Memory.h"


using namespace std;
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

string verificaOpcod(int op);
string verificaFunct(int funct);
int verificaAluControl(int funct);
int convDecimal(int bin);
void stages();
void stage1(IF_ID& Ifid, std::vector<int>* memoriaDeInstrucoes);
void stage2(IF_ID& Ifid, ID_EX& Id_ex, BancoDeRegistradores& Regs);
void stage3(ID_EX& Id_ex, EX_MEM& Ex_mem);
void stage4(EX_MEM& Ex_mem, MEM_WD& Mem_wb, Memory& Mem, BancoDeRegistradores& Regs);
void stage5(MEM_WD& Mem_wb, BancoDeRegistradores& Regs);

#endif //MIPS_PIPELINE_STAGES_H
