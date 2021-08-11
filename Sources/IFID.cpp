#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "IFID.h"

using namespace std;

IFID::IFID(int pc, int instrucoes)
{
    this->pc = pc;
    this->instrucoes = instrucoes;
}

IFID::~IFID()
{
};

int IFID::getPc()
{
    return pc;
}


