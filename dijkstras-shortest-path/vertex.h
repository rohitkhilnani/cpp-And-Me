/*
	Vertex for Dijkstra's algorithm
*/
#ifndef __DIJKSTRAS_VERTEX__
#define __DIJKSTRAS_VERTEX__

#include<limits>

class Vertex{

	protected:

		int name = -1; 									// vertex id/ name
		int dist = std::numeric_limits<int>::max();		// distance from source vertex
		int parent = -1; 								// parent vertex in path from source to this vertex

	public:

		// Constructs vertex with default values

		Vertex();	


		// Constructs vertex with specified name

		Vertex(int n);


		// Returns name

		int get_name();


		// Sets distance

		void set_dist(int d);


		// Returns distance

		int get_dist();


		// Sets parent

		void set_parent(int p);


		// Returns Parent

		int get_parent();
};

#endif 