#include "Ring.hpp"
#include <string>
#include <iostream>

Ring::Ring() {
    string stationPrice;
    int roadCost;
    GasStation *next;
    
    cout << "Enter refueling price: ";
    cin >> stationPrice;
    
    if (stationPrice != "end") {
        this -> citiesAmount++;
        
        cout << "Enter road cost: ";
        cin >> roadCost;
        
        this -> refueling = new GasStation(stoi(stationPrice));
        this -> refueling -> right.first = roadCost;
        this -> refueling -> city = 1;
        
        next = new GasStation();
        next -> city = 2;
        this -> c = 3;
        next -> left.first = roadCost;
        next -> left.second = this -> refueling;
        
        this -> refueling -> right.second = next;
        
        this -> ringBuild(next);
    }
}

void Ring::ringBuild(GasStation *refueling) {
    string stationPrice;
    int roadCost;
    GasStation *next;
    
    cout << "Enter refueling price: ";
    cin >> stationPrice;
    
    if (stationPrice != "end") {
        this -> citiesAmount++;
        
        cout << "Enter road cost: ";
        cin >> roadCost;
        
        refueling -> price = stoi(stationPrice);
        
        next = new GasStation();
        next -> city = c;
        c++;
        next -> left.first = roadCost;
        next -> left.second = refueling;
        
        refueling -> right.first = roadCost;
        refueling -> right.second = next;
        
        this -> ringBuild(next);
        
    } else {
        refueling -> left.second -> right.second = this -> refueling;
        
        this -> refueling -> left.first = refueling -> left.second -> right.first;
        this -> refueling -> left.second = refueling -> left.second;
    }
}

int Ring::solveRight(GasStation *refueling) {
    int roadCost, nextStationPrice;
    
    roadCost = refueling -> right.first;
    nextStationPrice = refueling -> right.second -> price;
    
    if (currentPrice + roadCost < minPrice) {
        if (currentPrice + roadCost + nextStationPrice < minPrice) {
            minPrice = currentPrice + roadCost + nextStationPrice;
            cityNumber = refueling -> right.second -> city;
        }
        
        currentPrice += roadCost;
        
        if (c != citiesAmount) {
            c++;
            solveRight(refueling -> right.second);
        }
        
    }
    
    return minPrice;
}

int Ring::solveLeft(GasStation *refueling) {
    int roadCost, nextStationPrice;
    
    roadCost = refueling -> left.first;
    nextStationPrice = refueling -> left.second -> price;
    
    if (currentPrice + roadCost < minPrice) {
        if (currentPrice + roadCost + nextStationPrice < minPrice) {
            minPrice = currentPrice + roadCost + nextStationPrice;
            cityNumber = refueling -> left.second -> city;
        }
        
        currentPrice += roadCost;
        
        if (c != citiesAmount) {
            c++;
            solveLeft(refueling -> left.second);
        }
        
    }
    
    return minPrice;
}
