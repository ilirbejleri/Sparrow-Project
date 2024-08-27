#include "sparrow.h"



int main() {
    std::bitset<32> b1{"11100000000001100000000000100010"};
    std::bitset<32> b2{"01110000000001111000000000100001"};

    std::vector<std::bitset<32>> v1{b1};
    std::vector<std::bitset<32>> v2{b2};

    
    std::vector<std::bitset<32>> result{(sparrow::warmup::BitAnd(v1, v2)).first};
    std::cout << sparrow::warmup::CountBits(result);

}