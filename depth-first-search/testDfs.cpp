/*
	Program to test Depth First Search
*/

#include<iostream>
#include<vector>
#include "dfs.h"		// My implementation of Depth First Search


// tests Dfs (acyclic)

void testDfsA(){

	int n = 10;
	int m = 10;

	std::vector<std::vector<int>> edges = {
												{1,2},
												{2,3},
												{2,4},
												{3,5},
												{4,5},
												{5,6},
												{1,6},
												{4,7},
												{7,8},
												{9,10}
			
										};

	// Initialize dfs object									
	Dfs dfs(n,m,edges);
	
	// Traverse
	std::cout<<"Traversal: ";

	dfs.traverse();			

	// Test if graph is cyclic
	std::cout<<"\nGraph is cyclic: "<<dfs.isCyclic();

	// Print toplogical sort order
	std::cout<<"\nTopological Sort: ";
	dfs.topologicalSort();


}	


//tests Dfs (cyclic)

void testDfsB(){

	int n = 10;
	int m = 11;

	std::vector<std::vector<int>> edges = {
												{1,2},
												{2,3},
												{2,4},
												{3,5},
												{4,5},
												{5,6},
												{1,6},
												{4,7},
												{7,8},
												{9,10},
												{6,1}		


										};

	// Initialize dfs object									
	Dfs dfs(n,m,edges);
	
	// Traverse
	std::cout<<"\nTraversal: ";

	dfs.traverse();			

	// Test if graph is cyclic
	std::cout<<"\nGraph is cyclic: "<<dfs.isCyclic();

	// Print toplogical sort order
	std::cout<<"\nTopological Sort: ";
	dfs.topologicalSort();


}	

int main(){


	// Call testDfsB()
	testDfsA();

	// Call testDfsB()
	testDfsB();


	return 0;
}	