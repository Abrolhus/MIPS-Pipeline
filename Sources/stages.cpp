#include <iostream>
#include <fstream>
#include "stages.h"
#include <math.h>
#define OADD 0x20
#define OADDI 0x21
#define OSUB 0x22
#define OAND 0x24
#define OOR 0x25
#define OSLL 0x0
#define OSLT 0x2a
#define OJ 0x2
#define OJAL 0x3
#define OBEQ 0x14
#define OBNE 0x15
#define OJR 0x8
#define OLW 0x23
#define OSW 0x2b

#define R_TYPE 0

using namespace std;

/**
 * @brief
 *
 * @param op
 */
string verificaOpcod(int op)
{
    string code;
    switch (op)
    {
    case 0b0000: // Tipo R
         code = "R";
        break;
    case 0b1000: // addi - 8
        code = "addi";
        break;
    case 0b100011: // lw - 35
        code = "lw";
        break;
    case 0b1010011: // sw - 83
        code = "sw";
        break;
    case 0b000100: // beq - 4
        code = "beq";
        break;
    case 0b000101: // bne - 5
        code = "bne";
        break;
    case 0b000010: // j - 2
        code = "j";
        break;
    case 0b000011: // jal - 3
        code = "jal";
        break;
    default:
        cout << "\nOpcode não cadastrado.\n";
        break;
    }

    return code;
}

string verificaFunct(int funct)
{
    string f;
    switch (funct)
    {
    case 32: //100000
        f = "add";
        break;
    case 34: //100010
        f = "sub";
        break;
    case 36: //100100
        f = "and";
        break;
    case 37: //100101
        f = "or";
        break;
    case 42: //101010
        f = "slt";
        break;
    case 0: //000000
        f = "sll";
        break;
    case 35: //100011
        f = "lw";
        break;
    case 43: //101011
        f = "sw";
        break;
    case 4: //000100
        f = "beq";
        break;
    case 5: //000101
        f = "bne";
    case 2: //000010
        f = "j";
    case 8: //001000
        f = "jr";
    case 3: //000011
        f = "jal";
        break;
    default:
        cout << "\nFunction não cadastrado.\n";
        break;
    }
    return f;
}
int verificaAluControl(int funct)
{
    int control;
    switch (funct)
    {
    case 32:            //100000
        control = 0b10; //"add";
        break;
    case 34:            //100010
        control = 0110; // "sub";
        break;
    case 36:            //100100
        control = 0000; //"and";
        break;
    case 37:            //100101
        control = 0001; //"or";
        break;
    case 42:            //101010
        control = 0111; //"slt";
        break;
    case 25:            //
        control = 1100; //"NOR";
        break;
    default:
        cout << "\nFunction não cadastrado.\n";
        break;
    }

    return control;
}

int convDecimal(int bin)
{
    int dec;
        for(int i = 0; bin > 0; i++)
    {
        dec = dec + pow(2, i) * (bin % 10);
        bin = bin / 10;
    }
    return dec;
}


void stages(){
    BancoDeRegistradores Regs;
    Alu UnidadeLogica;
    IF_ID IfId;
    ID_EX IdEx;
    EX_MEM ExMem;
    MEM_WD MemWb;
    std::vector<int>* memoriaDeInstrucoes;
    memoriaDeInstrucoes = IF_ID::CriaMemoInstruc();
    Memory Memoria;

    for(int i = 0; i < memoriaDeInstrucoes->size(); i++){
        cout << "Ciclo de Clock: " << i*5 <<  " | PC: " << IfId.getPc() << endl;
        cout << "Registradores: ";
        for(int i = 0; i < Regs.getSize(); i++){
            cout << Regs.read(i) << ", ";
        }
        cout << endl;
        cout << "Lendo instrucao da Memoria de Instrucoes..." << endl;
        stage1(IfId, memoriaDeInstrucoes);
        cout << "Inst: " << IfId.getInstruction() << endl << endl;
        cout << "Decodificando Instrucao..." << endl;
        stage2(IfId, IdEx, Regs);
        cout << "OP: " << IdEx.getOp() << endl;
        cout << "RS: " << IdEx.getRs() << " | " << "RT: " << IdEx.getRt() << " | " << IdEx.getRd() << endl;
        cout << "Immed: " << IdEx.getImmed() << " | " << "Shampt: "<< IdEx.getShamt() << endl << endl;
        stage3(IdEx, ExMem);
        cout << "Efetuando Operacao.." << endl;
        cout << "Resultado da ALU: " << ExMem.getAluResult() << endl << endl;
        stage4(ExMem, MemWb, Memoria, Regs);
        cout << "Lendo Memoria de Dados..." << endl;
        cout << "Data: " << MemWb.getData() << endl << endl;
        stage5(MemWb, Regs);
        if(MemWb.getDst() != 0){
            cout << "Escrevendo nos Registradores..." << endl;
            cout << "Destino: " << MemWb.getDst() << endl;
            cout <<  "Data: " << MemWb.getData() << endl << endl;
        }
        cout << endl << endl;
    }
}
void stage1(IF_ID& Ifid, std::vector<int>* memoriaDeInstrucoes){
    Ifid.setInstruction(memoriaDeInstrucoes->at(Ifid.getPc()/4));
    Ifid.setPc(Ifid.getPc() + 4);

}
void stage2(IF_ID& Ifid, ID_EX& Id_ex, BancoDeRegistradores& Regs){
    int rd=0, rs=0, rt=0, op=0, pc=0, immed=0, shamt=0; // op is the opCode if I or J, or func if R
    int jump=0;
    int inst = Ifid.getInstruction();
    int opCode = Ifid.getOpCode(inst);
    if(opCode == 0){
        rs = Regs.read(Ifid.getRS(inst));
        rt = Regs.read(Ifid.getRT(inst));
        rd = Ifid.getRD(inst);
        op = Ifid.getFunct(inst);
        pc = Ifid.getPc();
        immed = 0;
    } else if(verificaOpcod(opCode) == "j" || verificaOpcod(opCode) == "jal"){
        jump = Ifid.getImmedJ(inst);
        op = opCode;
    }
    else{ // I
        op = opCode;
        rs = Regs.read(Ifid.getRS(inst));
        //rs = Ifid.getRS(inst);
        rt = Ifid.getRT(inst);
        immed = Ifid.getImmed(inst);
    }
    Id_ex.setOp(op);
    Id_ex.setRs(rs);
    Id_ex.setRt(rt);
    Id_ex.setRd(rd);
    Id_ex.setImmed(immed);
    Id_ex.setShamt(shamt);
}
void stage3(ID_EX& Id_ex, EX_MEM& Ex_mem){
    int op =Id_ex.getOp();
    int aluCode = 0;
    int zeroFlag = 0;
    int a, b;
    switch(op){
        case 0x20:
            a = Id_ex.getRs();
            b = Id_ex.getRt();
            Ex_mem.setDst(Id_ex.getRd());
            aluCode = 0b10;
            break;
        case OSUB:
            a = Id_ex.getRs();
            b = Id_ex.getRt();
            Ex_mem.setDst(Id_ex.getRd());
            aluCode = 0b11;
            break;
        case OLW:
            a = Id_ex.getRs();
            b = Id_ex.getImmed();
            Ex_mem.setDst(Id_ex.getRt());
            break;
        case OADDI:
            a = Id_ex.getRs();
            b = Id_ex.getImmed();
            Ex_mem.setDst(Id_ex.getRt());
            break;
        case OSLT:
            a = Id_ex.getRs();
            b = Id_ex.getRt();
            Ex_mem.setDst(0);
        default:
            break;
    }
    //else if (verificaOpcod(op) == "lw" || verificaOpcod(op) == "sw")
       //aluCode= 0b10;
    //else if (verificaOpcod(op) == "beq")
        //aluCode = 0b110;
    Ex_mem.setAluResult(Alu::act(a, b, aluCode, zeroFlag));
    Ex_mem.setOp(op);
}
void stage4(EX_MEM& Ex_mem, MEM_WD& Mem_wb, Memory& Mem, BancoDeRegistradores& Regs){
    Mem_wb.setOp(Ex_mem.getOp());
    Mem_wb.setDst(Ex_mem.getDst());
    Mem_wb.setData((Ex_mem.getAluResult()));
    if(verificaFunct(Ex_mem.getOp()) == "lw"){
        int word = Mem.getWord(Ex_mem.getAluResult(), 0); // TODO: ALU sums the address with the offset
        Mem_wb.setData(word);
        Mem_wb.setDst(Ex_mem.getDst());
    }
    else if(verificaFunct(Ex_mem.getOp()) == "sw"){
        int word = Regs.read(Ex_mem.getDst());
        Mem.storeWord(word, Ex_mem.getAluResult(), 0); // TODO: ALU sums the address with the offset
        Mem_wb.setDst(0);
    }
}
void stage5(MEM_WD& Mem_wb, BancoDeRegistradores& Regs){
    // if(verificaFunct(Mem_wb.getOp()) == ""); // TODO:
    if(Mem_wb.getDst() != 0){
        Regs.write(Mem_wb.getDst(), Mem_wb.getData());
    }
}