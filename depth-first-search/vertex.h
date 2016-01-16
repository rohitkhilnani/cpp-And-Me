/*
	This header defines vertex for depth first search
*/

#ifndef __DFS_VERTEX__
#define __DFS_VERTEX__	


class Vertex{

	private:

		int name = -1;		// name of id or vertex
		int parent = -1;	// parent vertex id in depth first forest
		int d = -1;			// discovery time
		int f = -1;			// finish time
		char color = 'w';	// color of vertex

	public:
	
		// Constructs vertex with specified name

		Vertex(int n);


		// Sets parent

		void setParent(int p);

		// Sets discovery time

		void setD(int d);

		// Sets finish time

		void setF(int f);


		// Sets color

		void setColor(char c);


		// Returns name

		int getName();


		// Returns parent

		int getParent();


		// Returns discovery time

		int getD();


		// Returns finish time

		int getF();


		// Returns color

		char getColor();

};	

#endif