#ifndef Header_h
#define Header_h

#include <string>

using namespace::std;

struct GasStation {
    int city;
    int price;
    pair <int, GasStation*> left;
    pair <int, GasStation*> right;
    
    GasStation() {
        
    }
    
    GasStation(int price) {
        this -> price = price;
    }
};

#endif
