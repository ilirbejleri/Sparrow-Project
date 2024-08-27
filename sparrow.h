#include <bitset>
#include <iostream>
#include <vector>


namespace sparrow {

    struct NullableInts {
        std::vector<int> nums;
        std::vector<std::bitset<32>> valid;
    };

    void DropZero(NullableInts* n);

    struct AverageResult {
        float value;
        bool ok;
    };

    AverageResult Average(const NullableInts* n);

    AverageResult Average(const NullableInts& n);

    struct DivideResult {
        NullableInts value;
        bool ok;
    };

    DivideResult Divide(NullableInts* a, NullableInts* b);

    NullableInts* StrsToNullableInts(std::vector<std::string> inputs);

    int NullableIntsToArray(NullableInts& n, int** x);

    namespace warmup {
        unsigned CountBits(std::bitset<32> bits, unsigned pos, unsigned len);
        unsigned CountBits(std::vector<std::bitset<32>>);
        std::pair<std::vector<std::bitset<32>>, bool> BitAnd(std::vector<std::bitset<32>> a, std::vector<std::bitset<32>> b);
        
    }
}