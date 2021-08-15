
#ifndef IF_ID_H
#define IF_ID_H
#include <string>
#define MEMINST 128
class IF_ID
{
private:
    int i;
    int pc;
    int *memInst;

public:
    IF_ID();
    ~IF_ID();

    int getPc();
    int getInstrucoes();
    int* CriaMemoInstruc();
    void imprimeMemoInst();
    int sizePC();
};



#endif /* E692F662_A688_4B93_93F3_E36C6D8610E2 */
