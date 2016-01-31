/*
	Implements Dijkstras Shortest Path Algorithm using adjacency list representation of graph
*/

#ifndef __DIJKSTRAS_DIJKSTRAS__
#define __DIJKSTRAS_DIJKSTRAS__

#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<forward_list>
#include<limits>
#include<iostream>
#include "vertex.h"	



class Dijkstras{

	private:

		// class to encapsulate vertex pointer and weight for adjacency list
		class WVertex: protected Vertex{

			public:

			Vertex* vertex = nullptr;
			int weight = 0;

			// Constructs WVertex with specified vertex pointer and weight

			WVertex(Vertex* v, int w){
				vertex = v;
				weight = w;
			}	

		};

		// comparator class for Vertex objects based on distance
		class vertex_comp{

			public:

			bool operator()(Vertex *a, Vertex *b){

				return a->get_dist() > b->get_dist();		
			}	

		};


	std::unordered_map<int, Vertex*> v;							// map from vertex name to vertex object
	std::unordered_map<int, std::forward_list<WVertex*> > adj;		//adjacency list  
	int s = -1;

	public:

		/*  Constructs Dijkstras object
			n - Number of vertices
			m - Number of edges
			edges - vector of vector of int (2D vector) of order m x 3 with each row representing an directed edge (u,v,w) between vertices u and v
			of weight w.
			s - source vertex

		*/

		Dijkstras(int n, int m, std::vector< std::vector<int> > edges, int s );


		/*
		Finds shortest paths from source to all vertices
		*/

		void find_paths();


		/*
		Prints path from source to vertex named u
		*/

		void print_path(int u);


		/*
		Returns length of paths from source to vertex named u
		*/

		int get_length(int u);


		/*
		Destructor
		*/

		~Dijkstras();

};

#endif	