
#ifndef IFID_H
#define IFID_H
#include <string>

class IFID
{
private:
    int pc;
    int instrucoes;

public:
    IFID(int pc, int instrucoes);
    ~IFID();

    int getPc();
    int getInstrucoes();
};



#endif /* E692F662_A688_4B93_93F3_E36C6D8610E2 */
