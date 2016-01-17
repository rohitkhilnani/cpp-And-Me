#include<iostream>
#include<vector>
#include "mst.h"	// My implementation of prim's Minimum Spanning Tree algorithm

/*
	This program tests Prim's MST algorithm
*/


// tests MST

void testMstA(){

	int n = 5;		// no. of vertices
	int m = 8; 		// no. of edges

	std::vector<std::vector<int>> edges = { 		// edges

												{1,2,4},
												{1,4,1},
												{1,3,4},
												{2,3,2},
												{2,5,2},
												{3,4,1},
												{3,5,2},
												{4,5,3}

											};
	int s = 1;		// source for mst										

	// Create mst object
	Mst mst(n,m,edges,s);

	// Find mst
	mst.find();

	// Print mst edges
	mst.printMstEdges();
}


// tests MST

void testMstB(){

	int n = 8;		// no. of vertices
	int m = 13; 		// no. of edges

	std::vector<std::vector<int>> edges = { 		// edges

												{1,2,8},
												{2,3,6},
												{3,4,14},
												{4,5,5},
												{5,6,2},
												{6,7,5},
												{7,1,3},
												{2,7,4},
												{3,5,7},
												{2,8,3},
												{3,8,3},
												{7,8,2},
												{5,8,1}


											};
	int s = 1;		// source for mst										

	// Create mst object
	Mst mst(n,m,edges,s);

	// Find mst
	mst.find();

	// Print mst edges
	std::cout<<"MST Edges: \n";
	mst.printMstEdges();
}

int main(){


	// Call testMstA
	testMstA();

	// Call testMstB
	testMstB();

	return 0;
}