//
// Created by abrolhus on 19/08/2021.
//

#ifndef PIPELINE_BANCODEREGISTRADORES_H
#define PIPELINE_BANCODEREGISTRADORES_H
#include <vector>


class BancoDeRegistradores {
public:
    BancoDeRegistradores(size=32);
    int read(int reg) const;
    write(int reg, int word);
private:
    std::vector<int>* regs;
};


#endif //PIPELINE_BANCODEREGISTRADORES_H
