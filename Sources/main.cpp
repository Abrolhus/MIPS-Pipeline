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

    ID_EX *idex = new ID_EX();
    IF_ID *ifid = new IF_ID();
    EX_MEM *exmem = new EX_MEM();

    int *inst = ifid->CriaMemoInstruc();
    cout << "\nGravando instruções...\n";
    for (size_t i = 0; i < ifid->sizePC(); i++)
        cout << inst[i] << endl;

    int e = 0;
    ifid->printInstrucoes(inst, e);
    ifid->gravaTXT_Inst(inst, e);

//*!            Estágio 1 - IF_ID

    ifid->estagio_IF_ID(inst, e);
   // idex->printBcoRegis();
    idex->gravaTXT_BcoRegis();


    int r1= ifid->getRS(inst[e]);
    int r2= ifid->getRT(inst[e]);
    int pc= ifid->getPc(e);
    idex->carregaBcoRegis(r1, r2);      // Carrega banco de registradores
    idex->gravaTXT_BcoRegis();          // Grava banco de registradores

    int rdData1 = 0, rdData2 = 0;
    idex->leBancoRegist(r1, r2, rdData1, rdData2);


//*!           Estágio 2 - ID_EX

    idex->estagio_ID_EX(*ifid, r1, r2,inst, e );


//*!           Estágio 3 - EX_MAM



//*!           Estágio 2 - MAN_WD


    //    cout << "rg1: " << rdData1 << endl;
    //    cout << "rg2: " << rdData2 << endl;
    //    cout << "PC: " << pc << endl;

    delete[] memInst;
    delete idex;
    delete ifid;
    delete exmem;
    cout << "\nFinalizando programa.\n";
    return 0;
}
