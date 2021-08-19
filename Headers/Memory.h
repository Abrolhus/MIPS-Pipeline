//
// Created by abrolhus on 19/08/2021.
//

#ifndef PIPELINE_MEMORY_H
#define PIPELINE_MEMORY_H
#include <vector>


class Memory {
public:
    Memory(int size=128);
    int getWord(int address, int offset); // gets word at address + offset
    void storeWord(int word, int address, int offset); // stores/updates word at address + offset
private:
    std::vector<int>* data;
};


#endif //PIPELINE_MEMORY_H
