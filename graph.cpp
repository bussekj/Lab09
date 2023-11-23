#include <iostream>
#include <queue>
#include <stack>
#include "graph.h"

using namespace std;

graph::graph(int n){
    nodes = n;
    vector<vector<int>> x(nodes, vector<int>(nodes, 0));
    A = x;
}

bool graph::addEdge(int i, int j){
    //adds edge from node i to node j
    if (A[i][j] == 0){
        A[i][j] = 1;
        return true;
    }
    return false;
}

bool graph::removeEdge(int i, int j){
    //removes any edge from node i to node j
    if (A[i][j] == 1){
        A[i][j] = 0;
        return true;
    }
    return false;
}

bool graph::hasEdge(int i, int j){
    //searches through array for edge
    if (A[i][j] == 1){
        return true;
    }
    return false;
}

vector<int> graph::outEdges(int i){
    vector<int> x;
    for (int j = 0; j < nodes; j++){
        //pushes back any nodes that are connected
        if (A[i][j] == 1){
            x.push_back(j);
            cout << j << " ";
        }
    }

    return x;
}

vector<int> graph::inEdges(int i){
    vector<int> x;
    for (int j = 0; j < nodes; j++){
        //pushes back any nodes that are connected
        if (A[j][i] == 1){
            x.push_back(j);
            cout << j << " ";
        }
    }
    return x;
}

vector<vector<int>> graph::PrintOutAdjacencyMatrix(){
    //prints each nodes connections in order of a matrix
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
        cout << A[i][j] << " ";
        if (j == nodes - 1){
            cout << endl;
        }
        }
    }
    return A;
}

bool graph::DepthFirstSearch(int i, int j, string& visited, bool& found, vector<bool>& beenThere){
    bool end = false;
    //checks to see if node is found and makes sure node isn't printed multiple times
    if (i == j && found != true){
        found = true;
        visited += to_string(i) + "\n";
        return true;
    }
    //runs for every node until desired node is found
    else if (found == false){
        beenThere[i] = true;
        stack<int> adj;
        adj.push(-1);
        visited += to_string(i);
        visited += " ";
        while (found == false && end == false){
            for (int k = nodes - 1; k >= 0; k--){
                if (A[i][k] == 1 && beenThere[k] == false){
                    adj.push(k);
                }
            }
            //recursively goes down a branch until it hits an end
            while (adj.size() != 0 && adj.top() != -1){
                i = adj.top();
                adj.pop();
                DepthFirstSearch(i, j, visited, found, beenThere);    
            }
            if (adj.top() == -1){
                end = true;
            }
        }
    }
    return true;
}

bool graph::BreadthFirstSearch(int i, int j, string& visited, bool& found, vector<bool>& beenThere){
    //creates a queue and puts initial node in visited vector
    queue<int> adj;
    visited += to_string(i);
    visited += " ";
    beenThere[i] = true;
    //sorts through first node connections
    for (int k = 0; k < nodes; k++){
        if (A[i][k] == 1 && beenThere[k] == false){
            beenThere[k] = true;
            adj.push(k);
            if (k == j){
                found = true;
                visited += "\n";
                return true;
            }
        }
    }
    //sorts through connections of first node then moves onto children nodes
    while (adj.size() != 0){
        i = adj.front();
        adj.pop();
        visited += to_string(i);
        visited += " ";
        for (int k = 0; k < nodes; k++){
            if (A[i][k] == 1 && beenThere[k] == false){
                beenThere[k] = true;
                adj.push(k);
                if (k == j){
                    found = true;
                    visited += to_string(adj.back()) + "\n";
                    return true;
                }
            }
        }
    }
    return true;
}

graph::~graph(){}
