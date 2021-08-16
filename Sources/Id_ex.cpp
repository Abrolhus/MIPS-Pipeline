#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "ID_EX.h"

using namespace std;

ID_EX::ID_EX(int rd_index, int immediate, int offset, int ra, int rb, int PC_plus_four):
            rd_index(rd_index), immediate(immediate), offset(offset), ra(ra), rb(rb), PC_plus_four(PC_plus_four){
}