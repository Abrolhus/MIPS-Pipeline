#include "inputOutput.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <string>
#include "IFID.h"

using namespace std;

int main()
{
    string fileIn = "input.txt";
    string fileOut = "output.txt";
    int *mem_Instrucao = new int[32];
    vector<string> lines = inputFile(fileIn);

    for (size_t i = 0; i < lines.size(); i++)
    {
        mem_Instrucao[i] = stol(lines[i], nullptr, 2);
        cout << mem_Instrucao[i] << endl;
    }

    OutputClear(fileOut);
        
    for (size_t i = 0; i < 16; i++)
        OutputFile(fileOut, to_string(mem_Instrucao[i]));

    cout << "\n Finalizando programa...\n";
    delete[] mem_Instrucao;
    return 0;
}