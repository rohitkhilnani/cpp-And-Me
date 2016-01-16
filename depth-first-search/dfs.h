/*
	This header implements depth first search using adjacency list representation of graph
*/

#ifndef __DFS_DFS__
#define __DFS_DFS__


#include<vector>
#include<iostream>
#include<forward_list>
#include<unordered_map>	
#include "vertex.h"

class Dfs{

	private:

		std::unordered_map<int, Vertex*> v;							// map from vertex name to vertex reference
		std::unordered_map<int,std::forward_list<Vertex*> > adj;	// map from vertex name to its adjacency list
		int time = 0;												// time reference	
		bool cyclic = false;										// whether graph is cyclic or not
		std::forward_list<int> topologicalSorted;						// list to hold topological sort order


	protected:

			// visits vertex u in depth first fashion
			// Time Complexity O(V+E)		V - no. of vertices,  E - no. of edges

			void visit(int u);
	


	public:
	
		/*	Constructs Dfs object
			n - number of vertices
			m - number of edges
			edges - 2D vector (M x 2) with each row containing edge of form  (x,y)
		
		*/

			Dfs(int n, int m, std::vector<std::vector<int>> edges);


		// Traverses in depth first fashion and prints traversal

		void traverse();


		// Returns true if graph is cyclic
		// Time Complexity O(1)
		bool isCyclic();


		// Prints topological sort order of vertices if graph is acyclic
		// Time Complexity O(V)		V - no. of vertices
		void topologicalSort();

};	

#endif