#ifndef EX_MEM_H
#define EX_MEM_H


class Ex_mem
{
private:
   int rd_index;
    int alu_result;
    int rb;
public:
     // rb is used if is a memory store operation (i.e. loadWord). In the case of loadword, rb will be the destination register;
    Ex_mem(int rd_index, int alu_result, int rb);
    ~Ex_mem();
};


#endif
