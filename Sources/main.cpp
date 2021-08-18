#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include "inputOutput.h"
#include "IF_ID.h"
#include "ID_EX.h"
#include "stages.h"

using namespace std;

void menu()
{
    int selecao;
    cout << "\n ** Pipeline MIPS ** \n\n";
    cout << "1 - Modo direto" << endl;
    cout << "2 - Modo passo-a-passo  " << endl;
    cout << "3 - Sair" << endl;

    cin >> selecao;

    switch (selecao)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:
        exit(0);
        break;
    default:
        system("clear");
        cout << "\n\nOpção inválida! Tente novamente.\n";
    }
}

int main()
{

    menu();

    // grava o arquivo de texto na Memória de instrução
    // gravar as instruções no banco de registradores

    OutputClear("saida.txt");

    // ID_EX *idex = new ID_EX();

    int *memInst = new int[32];

    //   int inst = memorInstrucInput(memInst, 6);
    //   int t = getOpCode(inst);
    //   cout << getOpCode(inst)<<endl;

    IF_ID *ifid = new IF_ID();
    int *inst = ifid->CriaMemoInstruc();
    cout << "\nGravando instruções...\n";
    for (size_t i = 0; i < ifid->sizePC() / 4; i++)
        cout << inst[i] << endl;

    int e = 5;
    ifid->printInstrucoes(inst, e);
    ifid->gravaTXT_Inst(inst, e);
    ifid->estagio_IF_ID(inst, e);

    delete[] memInst;
    delete ifid;
    cout << "\nFinalizando programa.\n";
    return 0;
}
