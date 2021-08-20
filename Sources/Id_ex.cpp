#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "Id_ex.h"
#include "IF_ID.h"
#include "stages.h"
#define BCO_REGIS 32

using namespace std;
/**
 * @brief Construct a new id ex::id ex object
 * 
 */
ID_EX::ID_EX()
{
    this->bcoRegis = new int[BCO_REGIS];
}

/**
 * @brief Destroy the id ex::id ex object
 * 
 */
ID_EX::~ID_EX()
{
    delete[] bcoRegis;
    cout << "\n\n\nDestroy the ID_EX::ID_EX object" << endl;
}

void ID_EX::printBcoRegis()
{
    cout
        << "\n\t\t\b Banco de Registradores\n\n";

    for (int i = 0; i < BCO_REGIS; i++)
    {
        this->bcoRegis[i] = 0;
        cout<<"\t\t\t" << this->bcoRegis[i] << endl;
    }
}

void ID_EX::gravaTXT_BcoRegis()
{
    fstream saidaTxt("saida.txt", ios::out | ios::app);

    saidaTxt << "\n\t\tBanco de Registradores\n\n";
    for (int i = 0; i < BCO_REGIS; i++)
        saidaTxt<<"\t\t\t" << this->bcoRegis[i] << endl;
    saidaTxt.close();
}

/**
 * @brief
 *
 * @param rdRegis1
 * @param rdRegis2
 * @return int
 */
int ID_EX::leBancoRegist(int rdRegis1, int rdRegis2, int &rdData1, int &rdData2)
{
    if (rdRegis1 >= 0 && rdRegis1 < BCO_REGIS && rdRegis2 >= 0 && rdRegis2 < BCO_REGIS)
    {
        rdData1 = this->bcoRegis[rdRegis1];
        rdData2 = this->bcoRegis[rdRegis2];

        return 1;
    }
    return 0;
}

void ID_EX::carregaBcoRegis(int r1, int r2)
{
    this->bcoRegis[r1] = r1;
    this->bcoRegis[r2] = r2;
}

void ID_EX::estagio_ID_EX(IF_ID &ifid, int r1, int r2, int *inst, int i)
{
    string func, rd, temp, imed, imedJ;

    if (ifid.getOpCode(inst[i]) == 0) // TIPO R
        func = verificaFunct(ifid.getFunct(inst[i]));
    else
        func = verificaOpcod(ifid.getOpCode(inst[i]));

    if (ifid.getOpCode(inst[i]) == 0) // Mux write Register
        this->writeRegis = (ifid.getRD(inst[i]));
    else if (func == "lw")
        this->writeRegis = (ifid.getRT(inst[i]));
        else 
        this->writeRegis = atoi("nop ");

    imed = " immed: " + to_string(ifid.getImmed(inst[i]));
    imedJ = " immedJ: " + to_string(ifid.getImmedJ(inst[i]));

    if (ifid.getOpCode(inst[i]) == 0)
        temp = rd;
    else if (ifid.getOpCode(inst[i]) >= 2 && ifid.getOpCode(inst[i]) <= 3)
        temp = imedJ;
    else
        temp = imed;

    cout << "\n\t\t *** ID_EX ***\n "
         << "\n\t\tINSTRUÇÃO:      " << func
         << "\n\t\tPC:             " << ifid.getPc(i)
         << "\n\t\tREG_DATA1:      " << r1
         << "\n\t\tREG_DATA2:      " << r2
         << "\n\t\tWRITE_REGISTER: " << this->writeRegis 
         << "\n\t\tWRITE_DATA:     " << " " << endl;

    fstream saidaTxt("saida.txt", ios::out | ios::app);
    saidaTxt << "\n\t\t *** ID_EX ***\n "
             << "\n\t\tINSTRUÇÃO:      " << func
             << "\n\t\tPC:             " << ifid.getPc(i)
             << "\n\t\tREG_DATA1:      " << r1
             << "\n\t\tREG_DATA2:      " << r2
             << "\n\t\tWRITE_REGISTER: " << this->writeRegis
             << "\n\t\tWRITE_DATA: " << " " << endl;
    saidaTxt.close();
}
