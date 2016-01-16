/*
	Definition for dfs.h
*/

#include "dfs.h"

/*	Constructs Dfs object
	n - number of vertices
	m - number of edges
	edges - 2D vector (M x 2) with each row containing edge of form  (x,y)
	Note: edges assume directed
*/

	Dfs::Dfs(int n, int m, std::vector<std::vector<int>> edges){


		// initialize vertices

		for(int i=1;i<=n;i++){
			v[i] = new Vertex(i);
		}


		// Initialize adjacency list

		for(int i=0;i<m;i++){

			// edges (x,y)

			int x = edges[i][0];
			int y = edges[i][1];

			// add y to x's adjacency list

			adj[x].push_front(v[y]);
	

		}



	}


	// Traverses in depth first fashion and prints traversal

	void Dfs::traverse(){

		// set time to 0
		time = 0;


		// if there are no vertices, return
		if(v.size()<1)
			return;

		// visit vertex 1 
		visit(1);

		// visit any remaining white vertices
		for(int i=2;i<=v.size();i++){
			if(v[i]->getColor() == 'w')
				visit(i);
		}

	}	


	// visits vertex u in depth first fashion
	// Time Complexity O(V+E)		V - no. of vertices,  E - no. of edges
	
	void Dfs::visit(int u){

			// set color of u to gray
			v[u]->setColor('g');

			// set discovery time of u
			v[u]->setD(++time);

			// print u
			std::cout<<u<<" ";

			// for each vertex x in adjacency list of u

			for(auto x: adj[u]){

				// if x is white

				if(x->getColor() == 'w'){

					// set parent of x as u

					x->setParent(u);

					// visit x

					visit(x->getName());

				}

				else if (x->getColor() == 'g'){    // If gray vertex is encountered in adjacency list

						cyclic = true;		// set cyclic as true
				}

			}


			// set u as black
			v[u]->setColor('b');

			// set finish time of u
			v[u]->setF(++time);

			// Add u to sorted list (Topological sort)
			topologicalSorted.push_front(u);

		}


	// Returns true if graph is cyclic
	// Time Complexity O(1)

	bool Dfs::isCyclic(){
		return  cyclic;
	}


	// Prints topological sort order of vertices if graph is acyclic
	// Time Complexity O(V)		V - no. of vertices

	void Dfs::topologicalSort(){

		if(cyclic){
			std::cout<<"Graph is cyclic";
			return;
		}


		for(auto x: topologicalSorted)
			std::cout<<x<<" ";
	}
