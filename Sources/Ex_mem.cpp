#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "Ex_mem.h"
#include "Alu.h"
#include "stages.h"

using namespace std;

EX_MEM::EX_MEM()
{
}
/**
 * @brief Destroy the ex mem::ex mem object
 * 
 */
EX_MEM::~EX_MEM()
{
    cout << "Destroy the EX_MEM::EX_MEM object" << endl;
}

int EX_MEM::AluControl(int opCode, int funct)
{
    if (verificaOpcod(opCode) == "R")
        return verificaAluControl(funct);
    
    else if (verificaOpcod(opCode) == "lw" || verificaOpcod(opCode) == "sw")
        return 0b10;
    else if (verificaOpcod(opCode) == "beq")
        return 0b110;

        return 0;
}

int EX_MEM::getAluResult() const {
    return alu_result;
}

void EX_MEM::setAluResult(int aluResult) {
    alu_result = aluResult;
}

int EX_MEM::getOp() const {
    return op;
}

void EX_MEM::setOp(int op) {
    EX_MEM::op = op;
}

int EX_MEM::getDst() const {
    return dst;
}

void EX_MEM::setDst(int dst) {
    EX_MEM::dst = dst;
}

// EX_MEM::EX_MEM(int rd_index, int alu_result, int rb):
//         rd_index(rd_index), alu_result(alu_result), rb(rb){verificaAluControl(funct);
// }
