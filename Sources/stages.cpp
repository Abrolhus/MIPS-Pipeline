#include <iostream>
#include <fstream>
#include "stages.h"
#include "IF_ID.h"
#define R_TYPE 0

using namespace std;

int getOpCode(int inst)
{
    int opCode = inst >> 26;
    return opCode;
}

int getRS(int inst)
{
    int t = 0b000011111000000000000000000000;
    int rs = (inst & t) >> 21;
    return rs;
}

int getRT(int inst)
{
    int t = 0b000000000111110000000000000000;
    int rt = (inst & t) >> 16;
    return rt;
}

int getRD(int inst)
{
    int t = 0b000000000000001111100000000000;
    int rd = (inst & t) >> 11;
    return rd;
}

int getShamt(int inst)
{
    int t = 0b000000000000000000011111000000;
    int shamt = (inst & t) >> 6;
    return shamt;
}

int getFunc(int inst)
{
    int t = 0b000000000000000000000000111111;
    int func = (inst & t);
    return func;
}

int getImmed(int inst)
{
    int t = 0b000000000000001111111111111111;
    int immed = (inst & t);
    return immed;
}

int getImmedJ(int inst)
{
    int t = 0b000011111111111111111111111111;
    int immedj = (inst & t);
    return immedj;
}

/**
 * @brief 
 * 
 * @param op 
 */
void verificaOpcod(int op)
{
    OpCodes *opcode = new OpCodes();
    switch (op)
    {
    case 0b0000: // add - 0
        /* code */
        break;
    case 0b1000: // addi - 8
        /* code */
        break;
    case 0b100011: // lw - 35
        /* code */
        break;
    case 0b1010011: // sw - 83
        /* code */
        break;
    case 0b000100: // beq - 4
        /* code */
        break;
    case 0b000101: // bne -5
        /* code */
        break;
    case 0b000010: // j - 2
        /* code */
        break;
    case 0b000011: // jal - 3
        /* code */
        break;
    default:
        cout << "\nOpcode não cadastrado.\n";
        break;
    }
}

void LeInstrucoes(int *t, int i)
{
    cout << "\nLinha: " << i
         << "\nOPCODE " << getOpCode(t[i]) << endl
         << "RS " << getRS(t[i]) << endl
         << "RT " << getRT(t[i]) << endl
         << "RD " << getRD(t[i]) << endl
         << "SHAMT " << getShamt(t[i]) << endl
         << "FUNC " << getFunc(t[i]) << endl
         << "IMED " << getImmed(t[i]) << endl
         << "IMEDJ " << getImmedJ(t[i]) << endl;
}

void imprimeInst(int *t, int i)
{
    fstream output_txt;
    string path = "output.txt";
    output_txt.open(path, ios::out | ios::app);

    output_txt << "\nLinha: " << i
               << "\nOPCODE " << getOpCode(t[i]) << endl
               << "RS " << getRS(t[i]) << endl
               << "RT " << getRT(t[i]) << endl
               << "RD " << getRD(t[i]) << endl
               << "SHAMT " << getShamt(t[i]) << endl
               << "FUNC " << getFunc(t[i]) << endl
               << "IMED " << getImmed(t[i]) << endl
               << "IMEDJ " << getImmedJ(t[i]) << endl;
}
