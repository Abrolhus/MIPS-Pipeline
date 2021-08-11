#include "inputOutput.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <math.h>
#include "stages.h"

using namespace std;

int main()
{

    string fileIn = "input.txt";
    string fileOut = "output.txt";
    vector<string> lines = inputFile(fileIn);

    for (size_t i = 0; i < lines.size(); i++)
    {
        cout << lines[i] << endl;
    }
    OutputFile(fileOut, "Teste de gravação");
    unsigned int inst = getOpCode(pow(2, 30)); // 0b00000.....000100101

    cout << "\n Finalizando programa...\n";
    return 0;
}