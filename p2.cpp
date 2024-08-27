#include "sparrow.h"



int main() {
    sparrow::NullableInts nints1{.nums={20,999,40,60}, .valid=std::vector{std::bitset<32>{"00000000000000000000000000001101"}}};
    sparrow::NullableInts nints2{.nums={10,10,0,20}, .valid=std::vector{std::bitset<32>{"00000000000000000000000000001111"}}};

    sparrow::DropZero(&nints2);

    

    sparrow::DivideResult divideRes{sparrow::Divide(&nints1, &nints2)};

    sparrow::AverageResult avgRes{sparrow::Average(&divideRes.value)};

    std::cout << avgRes.value;
}