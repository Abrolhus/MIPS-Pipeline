#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "IF_ID.h"
#include "MEM_WD.h"
#include "inputOutput.h"

using namespace std;

MEM_WD::MEM_WD(/* args */)
{
    
}

/**
 * @brief Destroy the mem wd::mem wd object
 *
 */
MEM_WD::~MEM_WD()
{

     cout << "Destroy the mem MEM_WD::MEM_WD wd object" << endl;

}

int MEM_WD::getOp() const {
    return op;
}

void MEM_WD::setOp(int op) {
    MEM_WD::op = op;
}

int MEM_WD::getDst() const {
    return dst;
}

void MEM_WD::setDst(int dst) {
    MEM_WD::dst = dst;
}

int MEM_WD::getData() const {
    return data;
}

void MEM_WD::setData(int data) {
    MEM_WD::data = data;
}
