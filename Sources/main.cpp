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

    int *inst = ifid->CriaMemoInstruc();

    int *memInst = new int[32];
    //   int inst = memorInstrucInput(memInst, 6);
    //   int t = getOpCode(inst);
    // cout << getOpCode(inst)<<endl;

    for (size_t i = 0; i < ifid->sizePC(); i++)
        cout << inst[i] << endl;

    for (size_t i = 0; i < ifid->sizePC(); i++)
    {
        LeInstrucoes(inst, i);
        imprimeInst(inst, i);
    }

    delete[] memInst;
    delete ifid;
    cout << "\nFinalizando programa.\n";
    return 0;
}
