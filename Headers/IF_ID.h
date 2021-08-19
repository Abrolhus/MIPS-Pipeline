#ifndef IF_ID_H
#define IF_ID_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <streambuf>
#include <vector>
#define MEM_INST 128

using namespace std;
class IF_ID
{
private:
    int pc;
    int *memInst;

public:
    IF_ID();
    ~IF_ID();

    int getPc(int p);
    int getInstrucoes();
    int *CriaMemoInstruc();
    void imprimeMemoInst();
    int sizePC();
    int getOpCode(int inst);
    int getRS(int inst);
    int getRT(int inst);
    int getRD(int inst);
    int getShamt(int inst);
    int getFunct(int inst);
    int getImmed(int inst);
    int getImmedJ(int inst);
    void printInstrucoes(int *inst, int i);
    void gravaTXT_Inst(int *inst, int i);
    void printIFID(string menInst,int p);
    void gravaTXT_IFID(string menInst,int p);
    void estagio_IF_ID(int *inst, int i);
};

#endif /* E692F662_A688_4B93_93F3_E36C6D8610E2 */
