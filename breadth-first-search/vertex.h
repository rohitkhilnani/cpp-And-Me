/*
	This header defines vertex for breadth first search
*/

#ifndef __BFS_VERTEX__
#define __BFS_VERTEX__


class Vertex{


	private:

		int name = -1;			// Vertex id/ name	
		int parent = -1;		// Parent vertex' name in bfs tree
		int distance = -1;		// distance from source Vertex
		char color = 'w';		// color of vertex (w: white, b: black, g: gray)

	public:
	
		// Constructs vertex with specified name

		Vertex(int n);

		// Sets parent

		void setParent(int p);


		// Sets distance

		void setDistance(int d);


		// Sets color

		void setColor(char c);


		// Returns name

		int getName();


		// Returns parent

		int getParent();

		// Returns distance

		int getDistance();


		// Returns Color

		char getColor();

};

#endif	