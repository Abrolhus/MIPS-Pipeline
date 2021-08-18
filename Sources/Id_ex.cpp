#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "ID_EX.h"

using namespace std;

ID_EX::ID_EX()
{
    this->bcoRegis = new int[BCO_REGIS];
    this->rdRegis1 = rdRegis1;
    this->rdRegis2 = rdRegis2;
    this->rdData1 = NULL;
    this->rdData2 = NULL;
}

ID_EX::~ID_EX()
{
    delete[] bcoRegis;
    cout << "\ndestruiu ID_EX" << endl;
}

int ID_EX::LeBancoRegist(int rdRegis1, int rdRegis2, int &rdData1, int &rdData2)
{
    if (rdRegis1 >= 0 && rdRegis1 < 32 && rdRegis2 >= 0 && rdRegis2 < 32)
    {
        rdData1 = this->bcoRegis[rdRegis1];
        rdData2 = this->bcoRegis[rdRegis2];
        return 1;
    }
    return 0;
}

// ID_EX::ID_EX(int rd_index, int immediate, int offset, int ra, int rb, int PC_plus_four):
//             rd_index(rd_index), immediate(immediate), offset(offset), ra(ra), rb(rb), PC_plus_four(PC_plus_four){
// }