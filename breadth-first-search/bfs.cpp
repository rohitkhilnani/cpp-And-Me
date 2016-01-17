/*
	Definition for bfs.h
*/

#include "bfs.h"


/* 	Constructs Bfs object - initialized vertices and adjacency list	
		n - number of vertices (1 to n)
		m - number of edges
		edges - 2D vector of edges. Dimension M x 2 where each row is undirected edge of form (x,y)
		s - source/ starting vertex
		
*/

Bfs::Bfs(int n, int m, std::vector<std::vector<int>> edges, int s){

	// Initialize vertices
	
	for(int i=1;i<=n;i++){
		v[i] = new Vertex(i);
	}


	// Initialize adjacency list

	for(int i=0;i<m;i++){

		// edge (x,y)
		int x = edges[i][0];
		int y = edges[i][1];	

		// Add x and y to each other's adjacency list

		adj[x].push_front(v[y]);
		adj[y].push_front(v[x]);


	}

	// set source
	this->s = s;

}


// Traverses in breadth first fashion and prints traversal
// Time Complexity: O(V + E)  		V - no. of vertices, E - no. of edges

void Bfs::traverse(){

	// create queue	
	std::queue<Vertex*> que;
	
	// push source vertex reference on queue
	que.push(v[s]);	

	// change color of source to gray
	v[s]->setColor('g');

	// set source distance to 0
	v[s]->setDistance(0);

	// repeat while queue is not empty

	while(!que.empty()){

		// remove vertex from queue
		Vertex *u = que.front();
		que.pop();

		// print u
		std::cout<<u->getName()<<" ";

		// for each element in adjacency list of u

		for(auto v: adj[u->getName()]){

			// if v is white

			if(v->getColor() == 'w'){

				// set parent of v = u
				v->setParent(u->getName());

				// set distance of v as distance of u + 1
				v->setDistance(u->getDistance() + 1);

				// set v's color to gray
				v->setColor('g');

				// enqueue v

				que.push(v);

			}

		}


	}		



}

	
// Prints distance of all vertices from source	
// Time complexity: O(V) 	V - no. of vertices

void Bfs::printDistances(){

	for(int i=1;i<=v.size();i++){
		std::cout<<i<<": "<<v[i]->getDistance()<<std::endl;
	}
}

// Prints path of all vertices from source

void Bfs::printAllPaths(){

	for(int i=1;i<=v.size();i++){
		std::cout<<i<<": ";
		printPath(i);
		std::cout<<std::endl;
	}
}


// Prints path from source s to vertex u. 
// Time Complexity: O(N) 		N - length of path	

void Bfs::printPath(int u){

	// if path does not exits, return
	if(v[u]->getDistance() == -1){
		return;
	}

	// if u is source, print it.
	if(u == s){
		std::cout<<s<<" ";
	}
	else{ 		// otherwise

		// print path from s to parent of u
		printPath(v[u]->getParent());

		// print u
		std::cout<<u<<" ";		


	}

} 	


// Deallocates vertices
// Time Complexity: O(V)     V - no. of vertices

	Bfs::~Bfs(){

	for(int i=1;i<=v.size();i++){
		delete v[i];
	}
}