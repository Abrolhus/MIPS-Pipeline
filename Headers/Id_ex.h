#ifndef ADF3CD5D_07E6_4B8E_ACB4_7290C9CDE0A1
#define ADF3CD5D_07E6_4B8E_ACB4_7290C9CDE0A1

#define BCO_REGIS 8
#include <iostream>

class ID_EX
{
private:
int *bcoRegis;
int rdRegis1;
int rdRegis2;
int rdData1;
int rdData2;
bool muxID = false;
int wrRegis;
int wrData;

public:
    ID_EX();
    ~ID_EX();
    int LeBancoRegist(int readRegis1, int readRegis2, int &readData1, int &readData2);
};

// class ID_EX
// {
// private:
//     int rd_index;
//     int immediate;
//     int offset;
//     int ra;
//     int rb;
//     int PC_plus_four;

// public:
//     ID_EX(int rd_index, int immediate, int offset, int ra, int rb, int PC_plus_four);
//     ~ID_EX();
// };

#endif /* ADF3CD5D_07E6_4B8E_ACB4_7290C9CDE0A1 */
