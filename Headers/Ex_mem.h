#ifndef EX_MEM_H
#define EX_MEM_H

class EX_MEM
{
private:
   int rd_index;
    int alu_result;
    int rb;
public:
     // rb is used if is a memory store operation (i.e. loadWord). In the case of loadword, rb will be the destination register;
    EX_MEM(int rd_index, int alu_result, int rb);
    ~EX_MEM();
};


#endif
