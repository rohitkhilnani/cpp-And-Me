#include<iostream>
#include "bfs.h"  // My implementation of breadth first search
#include<vector>

// tests Bfs traversal, distances and paths

void testBfs(){

	// edges
	std::vector<std::vector<int> > edges = {	{1,5},
												{3,5},
												{2,4},
												{1,4},
												{5,7},
												{7,6},
												{2,6}

											};

	int n = 8;	// no. of vertices
	int m = 7;	// no. of edges
	int s = 1;	// source vertex									


	Bfs bfs(n, m, edges, s);


	// print traversal

	std::cout<<"Traversal: ";
	bfs.traverse();

	// print distances of vertices from source

	std::cout<<"\nDistances:\n";
	bfs.printDistances();

	// print path from source to all vertices

	std::cout<<"Paths: \n";
	bfs.printAllPaths();


	// deallocate vertices
	bfs.deallocateVertices();
}


int main(){

	// call testBfs

	testBfs();



	return 0;
}