#include "sparrow.h"


int main(int argc, char* argv[]) {
    
    std::vector<std::string> strings;
    
    for(int i = 1; i<argc; i++) {
        strings.push_back(argv[i]);
    }
    
    
    const sparrow::NullableInts* ints;
    ints = sparrow::StrsToNullableInts(strings);
    
    sparrow::AverageResult result{Average(ints)};
    delete ints;
    if(result.ok){
        std::cout << result.value;
    } else {    
        std::cout << "failed";       
    }
    
    

}