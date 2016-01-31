// Definition for vertex.h

#include "vertex.h"

// Constructs vertex with default values

	Vertex::Vertex(){

	}


	// Constructs vertex with specified name

	Vertex::Vertex(int n){
		name = n;
	}


	// Returns name

	int Vertex::get_name(){
		return name;
	}


	// Sets distance

	void Vertex::set_dist(int d){
		dist = d;
	}


	// Returns distance

	int Vertex::get_dist(){
		return dist;
	}


	// Sets parent

	void Vertex::set_parent(int p){
		parent = p;
	}


	// Returns Parent

	int Vertex::get_parent(){
		return parent;
	}