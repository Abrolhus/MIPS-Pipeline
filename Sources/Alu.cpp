#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "../Headers/Alu.h"

using namespace std;

/**
 * @brief 
 * 
 */
Alu::Alu()
{
}

/**
 * @brief Destroy the Alu:: Alu object
 * 
 */
Alu::~Alu()
{
    cout << "Destroy the Alu::Alu object";
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @param controlInput 
 * @param zeroFlag 
 * @return int 
 */
int Alu::act(int a, int b, int controlInput, int &zeroFlag)
{
    int result = 0;
    zeroFlag = 0;
    switch (controlInput)
    {
    case CI_ADD:
        result = add_f(a, b);
        break;
    case CI_SUB:
        result = sub_f(a, b);
        break;
    // case CI_LW:
    //     result = add_f_lw(a, b);
    //     break;
    // case CI_BQ:
    //     result = sub_f_beq(a, b);
    //     break;
    case CI_OR:
        result = or_f(a, b);
        break;
    case CI_AND:
        result = and_f(a, b);
        break;
    case CI_SLT:
        result = slt_f(a, b);
        break;
    case CI_ADDI:
        result = addi_f(a, b);
        break;
    case CI_SLL:
        result = sll_f(a, b);
        break;
    default:
        exit(EXIT_FAILURE);
    }
    if (result == 0)
    {
        zeroFlag = 1;
    }
    return result;
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int Alu::add_f(int a, int b)
{
    return a + b;
}
int Alu::sub_f(int a, int b)
{
    return a - b;
}

int Alu::add_f_lw(int a, int b)
{
    return a + b;
}
int Alu::sub_f_beq(int a, int b)
{
    return a - b;
}
int Alu::and_f(int a, int b)
{
    return a & b;
}
int Alu::or_f(int a, int b)
{
    return a | b;
}
int Alu::addi_f(int a, int b)
{
    return (unsigned int)a + (unsigned int)b;
}
int Alu::slt_f(int a, int b)
{
    return a < b; // TODO(Samuel): check if this slt is correct;
}
int Alu::sll_f(int a, int b)
{
    return a << b;
}


