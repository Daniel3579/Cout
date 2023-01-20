#include <iostream>
#include "GasStation.h"
#include <string>
#include "Ring.hpp"

void solve(Ring &circle, GasStation *refueling, int &f);

int main(int argc, const char * argv[]) {
    Ring circle;
    int f = 1;
    
    cout << endl;
    solve(circle, circle.refueling, f);
    cout << endl;
    
    return 0;
}

void solve(Ring &circle, GasStation *refueling, int &f) {
    int minPriceRight, minPriceLeft;
    
    circle.c = 0;
    circle.currentPrice = 0;
    circle.minPrice = refueling -> price;
    
    circle.cityNumber = refueling -> city;
    minPriceRight = circle.solveRight(refueling);
    cout << endl << "From city \"" << f << "\" to city \"" << circle.cityNumber << "\": " << minPriceRight << " by right";
    
    circle.c = 0;
    circle.currentPrice = 0;
    circle.minPrice = refueling -> price;
    
    circle.cityNumber = refueling -> city;
    minPriceLeft = circle.solveLeft(refueling);
    cout << endl << "From city \"" << f << "\" to city \"" << circle.cityNumber << "\": " << minPriceLeft << " by left\n";
    
    if (f != circle.citiesAmount) {
        f++;
        solve(circle, refueling -> right.second, f);
    }
}
