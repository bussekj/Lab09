#include <iostream>
#include <vector>
#include <string>

using namespace std;

class graph{
    public:
        graph(int n);

        bool addEdge(int i,int j);// – Add the edge (i,j) to E.

	    bool removeEdge(int i,int j);// – Remove the edge (i,j) from E.

    	bool hasEdge(int i,int j);// – Check if the edge (i,j) ∈ E.

    	vector<int> outEdges(int i);// – Return a list of all integers j such that edge (i,j) ∈ E.

    	vector<int> inEdges(int i);// – Return a list of all integers j such that edge (j,i) ∈ E.

    	vector<vector<int>> PrintOutAdjacencyMatrix();

    	bool DepthFirstSearch(int i,int j, string& visited, bool& found, vector<bool>& beenThere);// - where i is the start node, and j is target.  This will return a struct\class that contains a bool if found, and string that traces the path of nodes searched.

    	bool BreadthFirstSearch(int i,int j, string& visited, bool& found, vector<bool>& beenThere);// - where i is the start node, and j is target.  This will return a struct\class that contains a bool if found, and string that traces the path of nodes searched.

        ~graph();

        vector<vector<int>> A;

        string DFSvis;

        string BFSvis;

    private:
        int nodes;
};