#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include "inputOutput.h"
#include "IF_ID.h"
#include "stages.h"

using namespace std;

int main()
{
    IF_ID *ifid = new IF_ID();

    int *t = ifid->CriaMemoInstruc();

    int *memInst = new int[32];
    //   int inst = memorInstrucInput(memInst, 6);
    //   int t = getOpCode(inst);
    // cout << getOpCode(inst)<<endl;

    for (size_t i = 0; i <  ifid->sizePC(); i++)
        cout << t[i] << endl;
       
    for (size_t i = 0; i <ifid->sizePC() ; i++)
    {
        cout<< "\nLinha: "<< i;
    cout<< "\nOPCODE "<< getOpCode(t[i])<<endl;
    cout<<"RS "<< getRS(t[i])<<endl;
    cout<<"RT "<< getRT(t[i])<<endl;
    cout<<"RD "<< getRD(t[i])<<endl;
    cout<<"SHAMT " <<getShamt(t[i])<<endl;
    cout<<"FUNC "<< getFunc(t[i])<<endl;
    cout<<"IMED "<< getImmed(t[i])<<endl;
    cout<<"IMEDJ "<< getImmedJ(t[i])<<endl;/* code */
    }
    





    delete[] memInst;
    delete ifid;
    cout << "\nFinalizando programa.\n";
    return 0;
}
