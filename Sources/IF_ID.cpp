#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "IF_ID.h"
#include "stages.h"
#include "inputOutput.h"

using namespace std;

/**
 * @brief Construct a new IF_ID::IF_ID object
 * 
 */
IF_ID::IF_ID() = default    ;

/**
 * @brief Destroy the IF_ID::IF_ID object
 * 
 */
IF_ID::~IF_ID()
{
    cout << "destruiu IF_ID" << endl;
};

int IF_ID::getPc(int i)
{
    return (4 * i) + 4;
}

std::vector<int>* IF_ID::CriaMemoInstruc()
{
    string fileIn = "input.txt";
    vector<string> lines = inputFile(fileIn);
    auto* memInst = new std::vector<int>();

    for (size_t i = 0; i < lines.size()-2; i++)
    {
        //lines[i].pop_back();
        int val = (int)stol(lines[i], nullptr, 2);
        memInst->push_back(val); // passa de binário para inteiro
        //this->pc++;
    }

    return memInst;
}
int IF_ID::sizePC()
{
    return this->pc;
}

int IF_ID::getOpCode(int inst)
{

    int opCode = (unsigned int)inst >> 26;

    return opCode;
}

int IF_ID::getRS(int inst)
{
    int t = 0b000011111000000000000000000000;
    int rs = (inst & t) >> 21;
    return rs;
}

int IF_ID::getRT(int inst)
{
    int t = 0b000000000111110000000000000000;
    int rt = (inst & t) >> 16;
    return rt;
}

int IF_ID::getRD(int inst)
{
    int t = 0b000000000000001111100000000000;
    int rd = (inst & t) >> 11;
    return rd;
}

int IF_ID::getShamt(int inst)
{
    int t = 0b000000000000000000011111000000;
    int shamt = (inst & t) >> 6;
    return shamt;
}

int IF_ID::getFunct(int inst)
{
    int t = 0b000000000000000000000000111111;
    int funct = (inst & t);
    return funct;
}

int IF_ID::getImmed(int inst)
{
    int t = 0b000000000000001111111111111111;
    int immed = (inst & t);
    return immed;
}

int IF_ID::getImmedJ(int inst)
{
    int t = 0b000011111111111111111111111111;
    int immedj = (inst & t);
    return immedj;
}

void IF_ID::printInstrucoes(int *inst, int i)
{
    cout << "\nLinha: " << i
         << "\nOPCODE " << getOpCode(inst[i]) << endl
         << "RS " << getRS(inst[i]) << endl
         << "RT " << getRT(inst[i]) << endl;

    if (getOpCode(inst[i]) == 0b0)
    {
        cout << "RD " << getRD(inst[i]) << endl;
        cout << "SHAMT " << getShamt(inst[i]) << endl;
        cout << "FUNCT " << getFunct(inst[i]) << endl;
    }
    else if (getOpCode(inst[i]) == 0b10 || getOpCode(inst[i]) == 0b11)
        cout << "IMEDJ " << getImmedJ(inst[i]) << endl;
    else
        cout << "IMED " << getImmed(inst[i]) << endl;
}

void IF_ID::gravaTXT_Inst(int *inst, int i)
{
    fstream output_txt;
    string path = "saida.txt";
    output_txt.open(path, ios::out | ios::app);

    output_txt << "\nLinha: " << i
               << "\nOPCODE " << getOpCode(inst[i]) << endl
               << "RS " << getRS(inst[i]) << endl
               << "RT " << getRT(inst[i]) << endl;
    if (getOpCode(inst[i]) == 0b0)
    {
        output_txt << "RD " << getRD(inst[i]) << endl
                   << "SHAMT " << getShamt(inst[i]) << endl
                   << "FUNCT " << getFunct(inst[i]) << endl;
    }
    else if (getOpCode(inst[i]) == 0b10 || getOpCode(inst[i]) == 0b11)
        output_txt << "IMEDJ " << getImmedJ(inst[i]) << endl;
    else
        output_txt << "IMED " << getImmed(inst[i]) << endl;
    output_txt.close();
}

/**
 * @brief 
 * 
 * @param menInst 
 * @param i 
 */
void IF_ID::printIFID(string menInst, int i)
{
    cout << "\n\t\t *** IF_ID ***\n "
         << "\n\tInstrução: " << menInst
         << "\n\tPC: " << this->getPc(i) << endl;
}

/**
 * @brief 
 * 
 * @param menInst 
 * @param i 
 */
void IF_ID::gravaTXT_IFID(string menInst, int i)
{
    fstream saidaTxt("saida.txt", ios::out | ios::app);
    saidaTxt << "\n\t\t *** IF_ID ***\n"
             << "\n\tInstrução: " << menInst
             << "\n\tPC: " << this->getPc(i) << endl;
    saidaTxt.close();
}


/**
 * @brief 
 * 
 * @param inst 
 * @param i 
 */
void IF_ID::estagio_IF_ID(int *inst, int i)
{
    string func, rs, rt, rd, temp, imed, imedJ;
    if (this->getOpCode(inst[i]) == 0)
        func = verificaFunct(this->getFunct(inst[i]));
    else
        func = verificaOpcod(this->getOpCode(inst[i]));

    rs = to_string(getRS(inst[i]));
    rt =  to_string(getRT(inst[i]));
    rd =  to_string(getRD(inst[i]));
    imed =  to_string(getImmed(inst[i]));
    imedJ = to_string(getImmedJ(inst[i]));

    if (this->getOpCode(inst[i]) == 0)
        temp = rd;
    else if (this->getOpCode(inst[i]) >= 2 && getOpCode(inst[i]) <= 3)
    {
        temp = imedJ;
        rs = rt = " ";
    }
    else
        temp = imed;

    string menInst = func + rs + rt + temp;

    cout << "\n\t\t *** IF_ID ***\n "
             << "\n\t\tINSTRUÇÃO: "<< func
             << "\n\t\tPC:        " <<this->getPc(i)
             << "\n\t\tRS:        " << rs
             << "\n\t\tRT:        " << rt
             << "\n\t\tRD:        " << temp <<endl;



    fstream saidaTxt("saida.txt", ios::out | ios::app);
    saidaTxt << "\n\t\t *** IF_ID ***\n"
             << "\n\t\tINSTRUÇÃO: "<< func
             << "\n\t\tPC:        " <<this->getPc(i)
             << "\n\t\tRS:        " << rs
             << "\n\t\tRT:        " << rt
             << "\n\t\tRD:        " << temp<<endl;
    saidaTxt.close();
}
/**
 * @brief
 *
 * @param menInst
 * @param i
 */
int IF_ID::getInstruction() const {
    return instruction;
}

void IF_ID::setInstruction(int instruction) {
    IF_ID::instruction = instruction;
}

int IF_ID::getPc() const {
    return pc;
}

void IF_ID::setPc(int pc) {
    IF_ID::pc = pc;
}

