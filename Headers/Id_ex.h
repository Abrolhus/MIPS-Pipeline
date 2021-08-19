#ifndef D129B876_CC2B_4BE7_B67B_7DDB27132427
#define D129B876_CC2B_4BE7_B67B_7DDB27132427
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <streambuf>
#include <vector>
#include "IF_ID.h"
//#define BCO_REGIS 32

using namespace std;

class ID_EX
{
private:
    int *bcoRegis;
    int writeData;
    int writeRegis;

public:
    ID_EX();
    ~ID_EX();
    void carregaBcoRegis(int r1, int r2);
    void printBcoRegis();
    void gravaTXT_BcoRegis();
    int leBancoRegist(int rdRegis1, int rdRegis2, int &rdData1, int &rdData2);
    void estagio_ID_EX(IF_ID &ifid,int r1, int r2, int *inst, int i);
};

#endif /* D129B876_CC2B_4BE7_B67B_7DDB27132427 */
