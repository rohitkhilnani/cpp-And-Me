/*
	This header defines vertex for minimum spanning tree algorithm
*/

#ifndef __MST_VERTEX__
#define __MST_VERTEX__	

#include<limits>

class Vertex{

	private:

		int name = -1;									// vertex name or id
		int key = std::numeric_limits<int>::max();		// vertex key (shortest distance to mst set - during algorithm run)
		int parent = -1;								// parent vertex in mst	


	public:

		// Constructs vertex with specified name

		Vertex(int n);


		// Default constructor

		Vertex(){
			// Do nothing
		}


		// Sets key

		void setKey(int k);


		// Sets parent

		void setParent(int  p);


		// Returns name

		int getName();


		// Returns key

		int getKey();


		// Returns parent

		int getParent();


};	

#endif