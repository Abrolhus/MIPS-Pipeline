//
// Created by abrolhus on 11/08/2021.
//

#ifndef MIPS_PIPELINE_STAGES_H
#define MIPS_PIPELINE_STAGES_H

typedef unsigned int uint;
struct OpCodes{
    uint r = 0b0;
    uint addi = 0b00100;           00000000000010101010101010010101010100101
    uint lw = 0b100011;
    uint sw = 0b1010011;
    uint beq = 0b000100;
    uint bne = 0b000101;
    uint j = 0b000010;
    uint jal = 0b000011;
    //uint jr = 0b000000;
};

unsigned int getOpCode(unsigned int inst);

#endif //MIPS_PIPELINE_STAGES_H
