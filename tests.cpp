// tests.cpp
#include <iostream>
#include "graph.h"
#include <gtest/gtest.h>

using namespace std;

TEST(AddEdge,Test1){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.PrintOutAdjacencyMatrix();
    assert(A.A[0][2] == 1);
}	

TEST(AddEdge,Test2){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,4);
    A.addEdge(4,2);
    A.PrintOutAdjacencyMatrix();
    assert(A.A[3][4] == 1);
}

TEST(RemoveEdge,Test1){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.removeEdge(0,2);
    A.PrintOutAdjacencyMatrix();
    assert(A.A[0][2] == 0);
}	

TEST(RemoveEdge,Test2){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,4);
    A.addEdge(4,2);
    A.removeEdge(4,2);
    A.PrintOutAdjacencyMatrix();
    assert(A.A[4][2] == 0);
}

TEST(HasEdge,Test1){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.PrintOutAdjacencyMatrix();
    ASSERT_TRUE(A.hasEdge(0,2));
}	

TEST(HasEdge,Test2){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,4);
    A.addEdge(4,2);
    A.removeEdge(4,2);
    A.PrintOutAdjacencyMatrix();
    ASSERT_TRUE(A.hasEdge(2,1));
}

TEST(OutEdges,Test1){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.PrintOutAdjacencyMatrix();
    vector<int> x;
    x.push_back(2);
    assert(A.outEdges(0) == x);
}	

TEST(OutEdges,Test2){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,4);
    A.addEdge(4,2);
    A.PrintOutAdjacencyMatrix();
    vector<int> x;
    x.push_back(2);
    x.push_back(3);
    assert(A.outEdges(0) == x);
}

TEST(InEdges,Test1){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.PrintOutAdjacencyMatrix();
    vector<int> x;
    x.push_back(0);
    assert(A.inEdges(2) == x);
}	

TEST(InEdges,Test2){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,4);
    A.addEdge(4,2);
    A.PrintOutAdjacencyMatrix();
    vector<int> x;
    x.push_back(0);
    x.push_back(4);
    assert(A.inEdges(2) == x);
}

TEST(DepthFirst,Test1){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,4);
    A.addEdge(4,2);
    A.DepthFirstSearch(0, 4, A.DFSvis, found, beenThere);
    cout << A.DFSvis << endl;
	A.PrintOutAdjacencyMatrix();
    ASSERT_TRUE(found);
}

TEST(DepthFirst,Test2){
	graph A(15);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,4);
    A.addEdge(4,2);
    A.addEdge(7,10);
    A.addEdge(10,14);
    A.addEdge(10,5);
    A.addEdge(5,13);
    A.addEdge(13,11);
    A.addEdge(14,3);
    A.addEdge(9,8);
    A.addEdge(8,6);
    A.addEdge(6,12);
    A.addEdge(0,14);
    A.DepthFirstSearch(0, 14, A.DFSvis, found, beenThere);
    cout << A.DFSvis << endl;
	A.PrintOutAdjacencyMatrix();
    ASSERT_TRUE(found);
}

TEST(BreadthFirst,Test1){
	graph A(5);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,0);
    A.addEdge(1,4);
    A.BreadthFirstSearch(0, 4, A.BFSvis, found, beenThere);
    cout << A.BFSvis << endl;
	A.PrintOutAdjacencyMatrix();
    ASSERT_TRUE(found);
}

TEST(BreadthFirst,Test2){
	graph A(15);
    bool found = false;
    vector<bool> beenThere(5);
    A.addEdge(0,2);
    A.addEdge(0,3);
    A.addEdge(2,1);
    A.addEdge(3,4);
    A.addEdge(4,2);
    A.addEdge(7,10);
    A.addEdge(10,14);
    A.addEdge(10,5);
    A.addEdge(5,13);
    A.addEdge(13,11);
    A.addEdge(14,3);
    A.addEdge(9,8);
    A.addEdge(8,6);
    A.addEdge(6,12);
    A.addEdge(0,14);
    A.BreadthFirstSearch(0, 14, A.BFSvis, found, beenThere);
    cout << A.BFSvis << endl;
	A.PrintOutAdjacencyMatrix();
    ASSERT_TRUE(found);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
