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
    int rs, rt, rd, immed, shamt, op;

public:
    ID_EX();
    ~ID_EX();
    void carregaBcoRegis(int r1, int r2);
    void printBcoRegis();
    void gravaTXT_BcoRegis();
    int leBancoRegist(int rdRegis1, int rdRegis2, int &rdData1, int &rdData2);
    void estagio_ID_EX(IF_ID &ifid,int r1, int r2, int *inst, int i);

    int getRs() const;

    void setRs(int rs);

    int getRt() const;

    void setRt(int rt);

    int getRd() const;

    void setRd(int rd);

    int getImmed() const;

    void setImmed(int immed);

    int getShamt() const;

    void setShamt(int shamt);

    int getOp() const;

    void setOp(int op);
};

#endif /* D129B876_CC2B_4BE7_B67B_7DDB27132427 */
