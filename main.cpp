#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main()
{
	int nodes = -1;
	cout << "How many nodes are in graph?"<< endl;
	cin >> nodes;
	graph mat(nodes);
	cout << endl;

	int pick = -1;
	while(pick != 8){
		cout << "Pick which option to run."<< endl;
		cout << "Press 1 to add an edge to graph."<< endl;
		cout << "Press 2 remove an edge from graph."<< endl;
		cout << "Press 3 Find an edge in the graph."<< endl;
		cout << "Press 4 Find the out edges of a vertices"<< endl;
		cout << "Press 5 Find the in edges of a vertices"<< endl;
		cout << "Press 6 To Print out Adjacency Matrix"<< endl;
		cout << "Press 7 To Insert From .txt File"<< endl;
		cout << "Press 8 to quit."<< endl;
		cin >> pick;
		cout << endl;

		if(pick < 1 || pick > 8){
			cout <<"Error wrong pick"<< endl;
		}
		if (pick == 1){
			cout << "What nodes does this edge connect? Please enter first then next."<< endl;
			int i = -1;
			int j = -1;
			cin >> i;
			cin >> j;
			mat.addEdge(i,j);
			cout << endl;
		}
		else if (pick == 2){
			cout << "What nodes does the edge being removed connect? Please enter first then next."<< endl;
			int i = -1;
			int j = -1;
			cin >> i;
			cin >> j;
			mat.removeEdge(i,j);
			cout << endl;
		}
		else if (pick == 3){
			cout << "What nodes does the edge you're seeking connect? Please enter first then next."<< endl;
			int i = -1;
			int j = -1;
			cin >> i;
			cin >> j;
			cout << endl;
			if (mat.hasEdge(i,j)){
				cout << "There is an edge there." << endl << endl;
			}
			else{
				cout << "There is not an edge there." << endl << endl;
			}
			cout << endl;
		}
		else if (pick == 4){
			cout << "What verticie do you want the know the out edges for?"<< endl;
			int i = -1;
			cin >> i;
			cout << endl;
			mat.outEdges(i);
			cout << endl;
		}
		else if (pick == 5){
			cout << "What verticie do you want the know the in edges for?"<< endl;
			int i = -1;
			cin >> i;
			cout << endl;
			mat.inEdges(i);
			cout << endl;
		}
		else if (pick == 6){
			cout << "Printing matrix."<< endl << endl;
			mat.PrintOutAdjacencyMatrix();
			cout << endl;
		}
		else if (pick == 7){
			int a;
			cout << "Setting matrix to .txt file. (It will be 10 verticies with 16 edges)"<< endl << endl;
			ifstream myfile("matrix.txt");
			myfile.open("matrix.txt");
			for (int i = 0; i < 12; i++){
				for (int j = 0; j < 12; j++){
					myfile >> mat.A[i][j];
				}
			}
			myfile.close();
		}
		else if (pick == 8){
			cout << "End" << endl;
    		return 0;
		}
	}
}

