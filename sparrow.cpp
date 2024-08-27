#include "sparrow.h"

using namespace sparrow;

void sparrow::DropZero(NullableInts* n) {
        for(int i = 0; i<n->nums.size(); i++){
            if(n->nums[i] == 0) {
                n->valid[i/32][i%32] = 0;
            }
        }
    }

AverageResult sparrow::Average(const NullableInts* n) {
    AverageResult result {};
    int count{0};
    if(n == nullptr) {
        return result;
    } else {
        for(int i = 0; i<n->nums.size(); i++) {
            if(n->valid[i/32][i%32] == 1) {
                result.value += n->nums[i];
                result.ok = true;
                count++;
            }
        }
    }
    result.value /= count;
    return result;
}

AverageResult sparrow::Average(const NullableInts& n) {
    return sparrow::Average(&n);
}

DivideResult sparrow::Divide(NullableInts* a, NullableInts* b) {
    DivideResult result {};
    std::pair<std::vector<std::bitset<32>>, bool> andAttempt{warmup::BitAnd(a->valid, b->valid)};
    
    if(!andAttempt.second) {
        return result;
    } else {
        result.value = NullableInts{.valid{andAttempt.first}};
        result.ok = true;
    }
    for(int i = 0; i<a->nums.size(); i++) {
        if(result.value.valid[i/32][i%32] == 1) {
            result.value.nums.push_back(a->nums[i]/b->nums[i]);
        } else {
            result.value.nums.push_back(0);
        }
    }
    return result;
    

}

NullableInts* sparrow::StrsToNullableInts(std::vector<std::string> inputs) {
    NullableInts* parsed = new NullableInts;
    parsed[0].nums = {};
    parsed[0].valid = std::vector<std::bitset<32>>{};
    for(int i = 0; i<inputs.size(); i++) {
        if(i%32 == 0) {
            parsed[0].valid.push_back(std::bitset<32>{});
        }
        if(inputs[i] != "null") {
            parsed[0].nums.push_back(std::stoi(inputs[i]));
            parsed[0].valid[i/32][i%32] = 1;
        } else {
            parsed[0].nums.push_back(-1);
            
        }
    }
    return parsed;
    
}

int sparrow::NullableIntsToArray(NullableInts& n, int** x) {
    
    
    int size{static_cast<int>(warmup::CountBits(n.valid))};
    
    *x = new int[size];

    for(int i = 0; i<n.nums.size(); i++) {
        if(n.valid[i/32][i%32] == 1) {
            
            **x = n.nums[i];
            *x = *x+1;
        }
    }
    *x = *x - size;
    return size;
    
}

unsigned warmup::CountBits(std::bitset<32> bits, unsigned pos, unsigned len) {
    if(pos > 31) {
        return 0;
    }
    if(len-pos > 32) {
        len = 32-pos;
    }
    int count{0};
    while (len > 0) {
        if(bits[pos] == 1) {
            count++;
        }
        pos++;
        len--;
    }
    return count;
    
}

unsigned warmup::CountBits(std::vector<std::bitset<32>> bitVector) {
    int count{0};
    for(std::bitset bits : bitVector) {
        for(int i = 0; i<32; i++) {
            if(bits[i] == 1) {
                count++;
            }
        }
    }
    return count;
}

std::pair<std::vector<std::bitset<32>>, bool> warmup::BitAnd(std::vector<std::bitset<32>> a, std::vector<std::bitset<32>> b) {
    std::vector<std::bitset<32>> result{};
    if(a.size() != b.size()) {
        return {result, false};
        }
    
    for(int i = 0; i<a.size(); i++) {
        result.push_back(a[i]&b[i]);
    }
    return {result, true};
}

