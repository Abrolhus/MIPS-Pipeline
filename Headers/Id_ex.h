#ifndef ID_EX_H
#define ID_EX_H

#include <iostream>


class Id_ex
{
private:
    int rd_index;
    int immediate;
    int offset;
    int ra;
    int rb;
    int PC_plus_four;

public:
    Id_ex(int rd_index, int immediate, int offset, int ra, int rb, int PC_plus_four);
    ~Id_ex();
};

#endif
