#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "Ex_mem.h"
#include "stages.h"
#include "Alu.h"

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

// EX_MEM::EX_MEM(int rd_index, int alu_result, int rb):
//         rd_index(rd_index), alu_result(alu_result), rb(rb){verificaAluControl(funct);
// }
