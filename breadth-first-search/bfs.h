/*
	This header implementes breadth first search using adjacency list representation of a graph.
*/

#ifndef __BFS_BFS__
#define __BFS_BFS__

#include<unordered_map>
#include<forward_list>	
#include<vector>	
#include<iostream>	
#include<queue>
#include "vertex.h"

class Bfs{

	private:	

		std::unordered_map<int, Vertex*> v;							// map from vertex name to vertex reference
		std::unordered_map<int, std::forward_list<Vertex*> > adj;	// map from vertex name to adjacency list		
		int s = -1;													// source


	protected:

		// Prints path from source s to vertex u. 
		// Time Complexity: O(N) 		N - length of path	
		void printPath(int u);


	public:	

	/* 	Constructs Bfs object - initialized vertices and adjacency list	
		n - number of vertices (1 to n)
		m - number of edges
		edges - 2D vector of edges. Dimension M x 2 where each row is undirected edge of form (x,y)
		s - source/ starting vertex
		
	*/

		Bfs(int n, int m, std::vector<std::vector<int>> edges, int s);


		// Traverses in breadth first fashion and prints traversal
		// Time Complexity: O(V + E)  		V - no. of vertices, E - no. of edges

		void traverse();


		// Prints distance of all vertices from source
		// Time complexity: O(V) 	V - no. of vertices

		void printDistances();


		// Prints path of all vertices from source

		void printAllPaths();


		// Deallocates vertices
		// Time Complexity: O(V)     V - no. of vertices


		void deallocateVertices();

};


#endif	