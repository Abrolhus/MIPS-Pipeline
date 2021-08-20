#ifndef EX_MEM_H
#define EX_MEM_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include "stages.h"

using namespace std;
class EX_MEM
{
private:
  int rd_index;
  int *alu_result;
  int rb; // rb is used if is a memory store operation (i.e. loadWord). In the case of loadword, rb will be the destination register;

public:
  
  // EX_MEM(int rd_index, int alu_result, int rb);
  EX_MEM();
  ~EX_MEM();

  int AluControl(int opCode, int funct);
  
};

#endif
