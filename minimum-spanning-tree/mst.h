/*
	This header implements Prim's Minimum Spanning Tree algorithm
*/

#ifndef __MST_MST__
#define __MST_MST__

#include<unordered_map>
#include<vector>
#include<unordered_set>	
#include<forward_list>
#include<algorithm>
#include<iostream>
#include "vertex.h"	

class Mst{

	private:
		
		// inner class WVertex to encapsulate weight with vertex for adjacency list

		class WVertex: protected Vertex{

			public:

			Vertex *v = nullptr;		// vertex reference
			int weight = -1;			// edge weight

			WVertex(Vertex* v, int w){
				this->v = v;
				weight = w;
			}

		};


		// inner class comparator for heap / priority queue

		class quecomp{

		public:

			bool operator()(Vertex *a, Vertex *b){

				return a->getKey() > b->getKey();
			}

		};


		std::unordered_map<int, Vertex*> v;				// map from vertex name to vertex reference
		std::unordered_map<int, std::forward_list<WVertex*>> adj;			// map from vertex name to adjacency list

		int s = -1;										// starting vertex



	public:

		/* Constructs Mst object - initialize vertices and adjacency list

			n - no. of vertices
			m - no. of edges
			edges - 2D vector (M x 3), each row of form (x,y,w) where undirected edge (x,y) has weight w

		*/

		Mst(int n, int m, std::vector<std::vector<int>> edges, int s);

		// Finds MST

		void find();

		// Prints MST edges

		void printMstEdges();

		// Destructor - Deallocates vertices vertices and adjacency list
		// Time complexity: O(V+E)	V - no. of Vertices, E - no. of edges
		~Mst();

};





#endif	