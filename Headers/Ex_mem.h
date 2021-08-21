#ifndef EX_MEM_H
#define EX_MEM_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;
class EX_MEM
{
private:
   // int rd_index;
   int alu_result;
   int op;
   int dst; // in loadWord: rt;
public:
    int getDst() const;

    void setDst(int dst);

    int getOp() const;

    void setOp(int op);

    int getAluResult() const;

    void setAluResult(int aluResult);
    // EX_MEM(int rd_index, int alu_result, int rb);
    EX_MEM();
    ~EX_MEM();

    int AluControl(int opCode, int funct);

};


#endif
