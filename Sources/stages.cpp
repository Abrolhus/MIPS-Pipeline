#include <iostream>
#include <fstream>
#include "stages.h"
#include <math.h>

#define R_TYPE 0

using namespace std;

/**
 * @brief
 *
 * @param op
 */
string verificaOpcod(int op)
{
    string code;
    switch (op)
    {
    case 0b0000: // Tipo R
         code = "R";
        break;
    case 0b1000: // addi - 8
        code = "addi";
        break;
    case 0b100011: // lw - 35
        code = "lw";
        break;
    case 0b1010011: // sw - 83
        code = "sw";
        break;
    case 0b000100: // beq - 4
        code = "beq";
        break;
    case 0b000101: // bne - 5
        code = "bne";
        break;
    case 0b000010: // j - 2
        code = "j";
        break;
    case 0b000011: // jal - 3
        code = "jal";
        break;
    default:
        cout << "\nOpcode não cadastrado.\n";
        break;
    }

    return code;
}

string verificaFunct(int funct)
{
    string f;
    switch (funct)
    {
    case 32: //100000
        f = "add";
        break;
    case 34: //100010
        f = "sub";
        break;
    case 36: //100100
        f = "and";
        break;
    case 37: //100101
        f = "or";
        break;
    case 42: //101010
        f = "slt";
        break;
    case 0: //000000
        f = "sll";
        break;
    case 35: //100011
        f = "lw";
        break;
    case 43: //101011
        f = "sw";
        break;
    case 4: //000100
        f = "beq";
        break;
    case 5: //000101
        f = "bne";
    case 2: //000010
        f = "j";
    case 8: //001000
        f = "jr";
    case 3: //000011
        f = "jal";
        break;
    default:
        cout << "\nFunction não cadastrado.\n";
        break;
    }
    return f;
}
int verificaAluControl(int funct)
{
    int control;
    switch (funct)
    {
    case 32:            //100000
        control = 0b10; //"add";
        break;
    case 34:            //100010
        control = 0110; // "sub";
        break;
    case 36:            //100100
        control = 0000; //"and";
        break;
    case 37:            //100101
        control = 0001; //"or";
        break;
    case 42:            //101010
        control = 0111; //"slt";
        break;
    case 25:            //
        control = 1100; //"NOR";
        break;
    default:
        cout << "\nFunction não cadastrado.\n";
        break;
    }

    return control;
}

int convDecimal(int bin)
{
    int dec;
        for(int i = 0; bin > 0; i++)
    {
        dec = dec + pow(2, i) * (bin % 10);
        bin = bin / 10;
    }
    return dec;
}

