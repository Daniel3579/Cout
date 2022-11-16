#ifndef Graph_h
#define Graph_h

#include "Node.h"
#include <vector>

class Graph {
private:
    Node *matrix;
    int endNode;
    int nodesAmount;
    vector <pair <int, vector <int>>> paths;
    
public:
    Graph();
    void findWay();
    void showGraph();
    void showMatrix();
    void showPaths();
    
private:
    void fillGraph();
    bool findWayHelper(const int &start, vector <int> path, int length);
};

#endif
