#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include "inputOutput.h"
#include "IFID.h"
#include "stages.h"

using namespace std;

int main()
{
    int *memInst = new int[32];
    int inst = memorInstrucInput(memInst, 6);
    int t = getOpCode(inst);
    // cout << getOpCode(inst)<<endl;

    cout << t << endl;

    delete[] memInst;
    cout << "\nFinalizando programa.\n";
    return 0;
}
