#ifndef ADF3CD5D_07E6_4B8E_ACB4_7290C9CDE0A1
#define ADF3CD5D_07E6_4B8E_ACB4_7290C9CDE0A1

#include <iostream>

class ID_EX
{
private:
    int rd_index;
    int immediate;
    int offset;
    int ra;
    int rb;
    int PC_plus_four;

public:
    ID_EX(int rd_index, int immediate, int offset, int ra, int rb, int PC_plus_four);
    ~ID_EX();
};

#endif /* ADF3CD5D_07E6_4B8E_ACB4_7290C9CDE0A1 */
