#include <iostream>
#include <fstream>
#include "stages.h"

#define R_TYPE 0

using namespace std;


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
    case 0b0000: // add/sub - 0
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
    case 0b000101: // bne - 5
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

string verificaFunct(int funct)
{
    string f;
    switch (funct)
    {
    case 32:        //100000
        f = "add";
        break;
    case 34:        //100010
        f = "sub";
        break;
    case 36:        //100100
        f = "and";
        break;
    case 37:        //100101
        f = "or";
        break;
    case 42:          //101010
        f = "slt";
        break;
    case 0:           //000000
        f = "sll";
        break;
    case 35:            //100011
        f = "lw";
        break;
    case 43:            //101011
        f = "sw";
        break;
    case 4:             //000100
        f = "beq";
        break;
    case 5:             //000101
        f = "bne";
    case 2:             //000010
        f = "j";
    case 8:             //001000
        f = "jr";
    case 3:              //000011
        f = "jal";
        break;
    default:
        cout << "\nFunction não cadastrado.\n";
        break;
    }
return f;
   
}
