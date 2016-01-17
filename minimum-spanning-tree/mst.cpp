/*
	Definition for mst.h
*/

#include "mst.h"	

/* Constructs Mst object - initialize vertices and adjacency list

		n - no. of vertices
		m - no. of edges
		edges - 2D vector (M x 3), each row of form (x,y,w) where undirected edge (x,y) has weight w

	*/

	Mst::Mst(int n, int m, std::vector<std::vector<int>> edges, int s){


		// initialize vertices
		for(int i=1;i<=n;i++){
			v[i] = new Vertex(i);
			adj[i].clear();
		}

		// initialize adjacency list
		for(int i=0;i<m;i++){

			// edge (x,y) of weight w

			int x = edges[i][0];
			int y = edges[i][1];
			int w = edges[i][2];

			// Add x and y to each other's adjacency list

			adj[x].push_front(new WVertex(v[y],w));
			adj[y].push_front(new WVertex(v[x],w));


		}


		// initialize source

		this->s = s;

	}	

	// Finds MST
	// Time complexity: O(E*V)	E- no. of edges, V - no. of Vertices
	// NOTE: Original complexity is O(E*log(V)). There is increase in complexity because heapify has been called instead of 
	// decrease key while updateing key of vertex. STL does not support decrease key.

	void Mst::find(){

		// define priority queue (based on vector)
		std::vector<Vertex*> que;

		// define processed set
		std::unordered_set<int> processed;

		// set source's key = 0
		v[s]->setKey(0);

		// enqueue all vertices into queue
		for(int i=1;i<=v.size();i++){

			que.push_back(v[i]);
		}

		std::make_heap(que.begin(),que.end(), quecomp());

		// Repeat while	queue is not empty

		while(!que.empty())	{

			// remove vertex from queue
			std::pop_heap(que.begin(),que.end(),quecomp());
			Vertex *u = que.back();
			que.pop_back();

			// put u in processed set
			processed.insert(u->getName());

			// for all vertices in adjacency list of u
			for(auto x: adj[u->getName()]){

				// if x is not processed
				if(processed.find((x->v)->getName()) == processed.end() ){

					// If x's key is greater than weight of edge (u,x), update x's key and parent
					if((x->v)->getKey() > x->weight ){

						(x->v)->setKey(x->weight);
						(x->v)->setParent(u->getName());


						// reheapify queue

						make_heap(que.begin(),que.end(),quecomp());

					}


				}

			}




		}	


	}

	// Prints MST edges
	// Time complexity: O(V)	V - no. of Vertices
	void Mst::printMstEdges(){

		for(int i=1;i<=v.size();i++){
			if(i!=s)
				std::cout<<"("<<i<<","<<v[i]->getParent()<<")\n";
		}
	}	
	

	// Destructor - Deallocates vertices
	// Time complexity: O(V+E)	V - no. of Vertices, E - no. of edges
		Mst::~Mst(){

		// Deallocate vertices and adjacency list

		for(int i=1;i<=v.size();i++){
			delete v[i];

			for(auto x: adj[i]){
				delete x;
			}	
		}

	}	