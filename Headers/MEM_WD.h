#ifndef A3685354_E5A0_4270_AFA3_3F7E67D861DD
#define A3685354_E5A0_4270_AFA3_3F7E67D861DD
class MEM_WD
{
private:
    int writeData;
    int readData;
    int op;
    int dst;
    int data;
    //int address;
public:
    int getOp() const;

    void setOp(int op);

    int getDst() const;

    void setDst(int dst);

    int getData() const;

    void setData(int data);

public:
    MEM_WD();
    ~MEM_WD();
};

#endif /* A3685354_E5A0_4270_AFA3_3F7E67D861DD */