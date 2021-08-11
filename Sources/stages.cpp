#include <iostream>
#include "stages.h"
#define R_TYPE 0

int getOpCode(int inst){
    int opCode = inst >> 25;
    return opCode;
}

