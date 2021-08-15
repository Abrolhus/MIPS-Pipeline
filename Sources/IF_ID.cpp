#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "IF_ID.h"
#include "inputOutput.h"

using namespace std;

/**
 * @brief Construct a new IF_ID::IF_ID object
 * 
 */
IF_ID::IF_ID()
{
    this->i = MEMINST;
    this->pc = pc;
    this->memInst = new int[i];
}

/**
 * @brief Destroy the IF_ID::IF_ID object
 * 
 */
IF_ID::~IF_ID()
{

    delete[] memInst;
    cout << "\ndestruiu IFID" << endl;
};

int IF_ID::getPc()
{
    return pc;
}

int *IF_ID::CriaMemoInstruc()
{
    //IFID *ifid = new IFID();

    string fileIn = "input.txt";
    vector<string> lines = inputFile(fileIn);

    for (size_t i = 0; i < lines.size(); i++)
    {
        memInst[i] = stol(lines[i], nullptr, 2); // passa de binário para inteiro
        this->pc= this->pc + 1;
    }

    return memInst;
}

void IF_ID::imprimeMemoInst()
{

    for (size_t i = 0; i < sizePC(); i++)
    {
        this->memInst[i];
    }
}

int IF_ID::sizePC()
{
   return this->pc;
}
