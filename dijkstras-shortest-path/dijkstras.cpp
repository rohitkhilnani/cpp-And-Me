/*
	Implementation for dijkstras.h
*/

#include "dijkstras.h"	

	/*  Constructs Dijkstras object
		n - Number of vertices
		m - Number of edges
		edges - vector of vector of int (2D vector) of order m x 3 with each row representing an directed edge (u,v,w) between vertices u and v
		of weight w.
		s - source vertex

	*/

	Dijkstras::Dijkstras(int n, int m, std::vector< std::vector<int> > edges, int s ){

		// Create and initialize vertices
		for(int i = 1; i <= n; i++){

			v[i] = new Vertex(i);
			adj[i].clear();
		}


		// Create adjacency list based on edges

		for(int i = 0; i < m; i++){

			// edge(x,y,w)

			int x = edges[i][0];
			int y = edges[i][1];
			int w = edges[i][2];

			// Add y to x's adjacency list

			adj[x].push_front(new WVertex(v[y], w));
			
		}

		// set source
		this->s = s;

	}


	/*
	Finds shortest paths from source to all vertices
	*/

	void Dijkstras::find_paths(){

		// set source's distance = 0 
		v[s]->set_dist(0);

		// put all vertices (references) in priority queue (using vector)

			// put all vertices into vector
		std::vector<Vertex*> que;
		for(int i=1;i<=v.size();i++)
			que.push_back(v[i]);

			// convert the vector to priority  queue

		std::make_heap(que.begin(), que.end(), vertex_comp());

		// define a set to identify processed vertices
		std::unordered_set<int> processed;	

		// repeat while there are vertices in que

		while(!que.empty()){

			// remove vertex from queue

			std::pop_heap(que.begin(), que.end(), vertex_comp());
			Vertex* u = que.back();
			que.pop_back();

			// add  u to processed
			processed.insert(u->get_name());

			// if u is itslelf unreachable, ignore it and move to next vertex in que
			if(u->get_dist() == std::numeric_limits<int>::max())
				continue;

			// for all vertices adjacent to u
			for(auto x: adj[u->get_name()]){

				// if x is not in processed
				if( processed.find( x->vertex->get_name() ) == processed.end() ){

					// if current distance of x is larger than distance of u + edge 
					if (x->vertex->get_dist() > u->get_dist() + x->weight){

						// update x's weight
						x->vertex->set_dist(u->get_dist() + x->weight);

						// set x'a parent as u
						x->vertex->set_parent(u->get_name());

						// reheapify queue
						std::make_heap(que.begin(), que.end(), vertex_comp());
					}

				}


			}




		}



	}


	/*
	Prints path from source to vertex named u
	*/

	void Dijkstras::print_path(int u){

		// if u is source, print it
		
		if(u == s)
			std::cout<<s<<" ";
		else {

			// print path till u's parent
			print_path(v[u]->get_parent());

			// print u
			std::cout<<u<<" ";
		}

	}


	/*
	Returns length of paths from source to vertex named u
	*/

	int Dijkstras::get_length(int u){

		return v[u]->get_dist();
	}

	/*
	Destructor
	*/

	Dijkstras::~Dijkstras(){

		for(int i=1;i<=v.size();i++){
			delete v[i];

			for(auto x: adj[i]){
				delete x;
			}	
		}
	}