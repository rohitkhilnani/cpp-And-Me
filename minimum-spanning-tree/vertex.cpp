/*
	Definition for vertex.h
*/

#include "vertex.h"

		// Constructs vertex with specified name

		Vertex::Vertex(int n){
			name = n;
		}	


		// Sets key

		void Vertex::setKey(int k){
			key = k;
		}


		// Sets parent

		void Vertex::setParent(int  p){
			parent = p;
		}


		// Returns name

		int Vertex::getName(){
			return name;
		}


		// Returns key

		int Vertex::getKey(){
			return key;
		}


		// Returns parent

		int Vertex::getParent(){
			return parent;
		}
