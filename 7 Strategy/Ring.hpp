#ifndef Ring_hpp
#define Ring_hpp

#include "GasStation.h"

class Ring {
public:
    GasStation *refueling;
    int citiesAmount = 0;
    int c;
    int minPrice;
    int currentPrice;
    int cityNumber;
    
public:
    Ring();
    void ringBuild(GasStation *refueling);
    int solveRight(GasStation *refueling);
    int solveLeft(GasStation *refueling);
};

#endif
