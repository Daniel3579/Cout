#include "Graph.h"
#include <iostream>
#include <iomanip>

Graph::Graph() {
    int i;
    
    cout << "Enter nodes amount: ";
    cin >> this -> nodesAmount;
    cout << endl;
    
    //Matrix creation
    this -> matrix = new Node[nodesAmount];
    
    for (i = 0; i < nodesAmount; i++) {
        matrix[i].linkNodes = new pair <int, int> [nodesAmount];
    }
    
    fillGraph();
}

void Graph::fillGraph() {
    int i;
    int node, path;
    string stop;
    
    //Graph filling
    for (i = 0; i < nodesAmount - 1; i++) {
        cout << i + 1 << ": ";
        
        //Node filling
        while (true) {
            cin >> node >> path >> stop;
            
            if (stop == ".") {
                break;
            }
            
            //Make direct connection
            matrix[i].linkNodes[node - 1].first = node;
            matrix[i].linkNodes[node - 1].second = path;
            
            //Make reverse connection
            matrix[node - 1].linkNodes[i].first = i + 1;
            matrix[node - 1].linkNodes[i].second = path;
            
            cout << setw(3) << "";
        }
    }
    
    cout << endl;
}

void Graph::showGraph() {
    int i, j;
    
    //Start
    cout << "+" << setw(5);

    //Zero line
    for (i = 0; i < nodesAmount; i++) {
        cout << setw(4) << i + 1;
    }

    cout << endl;

    //Show adjacency table
    for (i = 0; i < nodesAmount; i++) {
        cout << i + 1;

        //Show lines
        for (j = 0; j < nodesAmount; j++) {
            if (i == j) {
                cout << setw(4) << "+";

            } else {
                if (matrix[i].linkNodes[j].second == 0) {
                    cout << setw(4) << ".";
                    
                } else {
                    cout << setw(4) << matrix[i].linkNodes[j].second;
                }
            }
        }
        
        cout << endl;
    }
    
    cout << endl;
}

void Graph::findWay() {
    int start;
    int length = 0;
    vector <int> path;
    
    cout << "Enter start point and end point" << endl << endl;
    
    cout << "Start point: ";
    cin >> start;
    
    cout << "End point: ";
    cin >> this -> endNode;
    cout << endl;
    
    //True find way
    path.push_back(start);
    findWayHelper(start, path, length);
    
    //Sorting
    sort(paths.begin(), paths.end());
}

bool Graph::findWayHelper(const int &start, vector <int> path, int length) {
    int i, j, newStart, tempLength;
    bool flag;
    
    //Enumeration of all link nodes
    for (i = 0; i < nodesAmount; i++) {
        flag = true;
        newStart = matrix[start - 1].linkNodes[i].first;
        
        //if current node is equal to end node
        if (newStart == endNode) {
            path.push_back(newStart);
            tempLength = length + matrix[start - 1].linkNodes[i].second;
            this -> paths.push_back(make_pair(tempLength, path));
            path.pop_back();
            
        //For other cases when node isn't empty
        } else if (newStart != 0) {
            
            //Checking current node in existing path
            for (j = 0; j < path.size(); j++) {
                if (newStart == path[j]) {
                    flag = false;
                    break;
                }
            }
            
            //If node isn't in existing path
            if (flag) {
                path.push_back(newStart);
                tempLength = length + matrix[start - 1].linkNodes[i].second;
                flag = findWayHelper(newStart, path, tempLength);
                
                //If previous call ended with iterating over all link nodes
                if (!flag) {
                    path.pop_back();
                }
            }
        }
    }
    
    //When call ended with iterating over all link nodes
    return false;
}

void Graph::showMatrix() {
    int i, j;
    
    //Show current node
    for (i = 0; i < nodesAmount; i++) {
        cout << i + 1 << ": ";
        
        //Show all its link nodes
        for (j = 0; j < nodesAmount; j++) {
            if (matrix[i].linkNodes[j].first != 0) {
                cout << matrix[i].linkNodes[j].first << " ";                
            }
        }
        
        cout << endl;
    }
    
    cout << endl;
}

void Graph::showPaths() {
    int i, j;
    
    //If path is empty
    if (paths.size() == 0) {
        cout << "There are no such ways ☹️" << endl;
        
    } else {
        
        //Show path length
        for (i = 0; i < paths.size(); i++) {
            cout << paths[i].first << ": ";
            
            //Show path directly
            for (j = 0; j < paths[i].second.size(); j++) {
                if (j == paths[i].second.size() - 1) {
                    cout << paths[i].second[j];
                    
                } else {
                    cout << paths[i].second[j] << " -> ";
                }
            }
            
            cout << endl;
        }
    }
    
    cout << endl;
}
