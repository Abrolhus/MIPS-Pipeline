#include "../Headers/Memory.h"

Memory::Memory(int size) {
    this->data = new std::vector<int>(size);
}

int Memory::getWord(int address, int offset) {
    return this->data.at(address + offset/4);
}

void Memory::storeWord(int word, int address, int offset) { // doesnt work if not storing a word properly (with 4-steps)
    this->data.at(address + offset/4) = word; // note que esse metodo recebe uma palavra, nao um indice de registrador do banco de registradores
}