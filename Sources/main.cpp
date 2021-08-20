#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include "inputOutput.h"
#include "IF_ID.h"
#include "Id_ex.h"
#include "Ex_mem.h"
#include "MEM_WD.h"
#include "stages.h"
#include "Alu.h"

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
    // menu();

    // grava o arquivo de texto na Memória de instrução
    // gravar as instruções no banco de registradores

    OutputClear("saida.txt");
    int *memInst = new int[32];

    //   int inst = memorInstrucInput(memInst, 6);
    //   int t = getOpCode(inst);
    //   cout << getOpCode(inst)<<endl;
    //  ID_EX *idex = new ID_EX();

    IF_ID *ifid = new IF_ID();
    ID_EX *idex = new ID_EX();
    EX_MEM *exmem = new EX_MEM();
    MEM_WD *memwd = new MEM_WD();
    Alu *alu = new Alu();

    int *inst = ifid->CriaMemoInstruc();
    cout << "\nGravando instruções...\n";
    for (size_t i = 0; i < ifid->sizePC(); i++)
        cout << inst[i] << endl;

    int e = 15;
    ifid->printInstrucoes(inst, e);
    ifid->gravaTXT_Inst(inst, e);

    //*!------------Estágio 1 - IF_ID-----------------

    ifid->estagio_IF_ID(inst, e);
    idex->printBcoRegis(); // vazio
    idex->gravaTXT_BcoRegis();

    int r1 = ifid->getRS(inst[e]);
    int r2 = ifid->getRT(inst[e]);
    int pc = ifid->getPc(e);
    idex->carregaBcoRegis(r1, r2); // Carrega banco de registradores com
    idex->gravaTXT_BcoRegis();     // Grava banco de registradores

    int rdData1 = 0, rdData2 = 0;
    idex->leBancoRegist(r1, r2, rdData1, rdData2);

    //*!--------------Estágio 2 - ID_EX --------------------

    idex->estagio_ID_EX(*ifid, r1, r2, inst, e);

    //*!--------------Estágio 3 - EX_MAM---------------------

    int mux = 0, aluR = 0, functOp = 0;

    if (ifid->getFunct(inst[e]))
        functOp = exmem->AluControl(ifid->getOpCode(inst[e]), ifid->getFunct(inst[e]));

    //aluR = alu->act(r1, r2, functOp, mux);

    cout << "\n\n\t\t *** EX_MAM ***\n "
         << "\n\t\tINSTRUÇÃO:       "
         << "\n\t\tPC:              " << pc
         << "\n\t\tFUNÇÃO:          " << functOp
         << "\n\t\tALU CONTROL:     "
         << "\n\t\tALU RESULT:      " << aluR << endl;

    //*!--------------Estágio 4 - MAN_WD---------------------

    cout << "\n\n\t\t *** MEM_WD ***\n "
         << "\n\t\tINSTRUÇÃO:       " 
         << "\n\t\tREAD DATA:       "
         << "\n\t\tPC:              " << pc
         << "\n\t\tWRITE DATA:      " << endl;

    delete[] memInst;
    delete idex;
    delete ifid;
    delete exmem;
    delete memwd;
    delete alu;
    cout << "\nFinalizando programa.\n";
    return 0;
}
