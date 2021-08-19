//
// Created by abrolhus on 19/08/2021.
//

#include "../Headers/BancoDeRegistradores.h"

BancoDeRegistradores::BancoDeRegistradores(int size) {
    this->regs = new std::vector<int>(size);
    this->regs.at(0) = 0;
}

int BancoDeRegistradores::read(int reg) const {
    return this->regs.at(reg);
}
void BancoDeRegistradores::write(int reg, int word) {
    if(reg != 0){ // the $zero register is constant
        this->regs.at(reg) = word;
    }
}