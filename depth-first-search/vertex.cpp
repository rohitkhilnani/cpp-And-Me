/*
	Definition for vertex.h
*/

#include "vertex.h"

// Constructs vertex with specified name

		Vertex::Vertex(int n){
			name = n;
		}	


		// Sets parent

		void Vertex::setParent(int p){
			parent = p;
		}


		// Sets discovery time

		void Vertex::setD(int d){
			this->d = d;
		}


		// Sets finish time

		void Vertex::setF(int f){
			this->f = f;
		}


		// Sets color

		void Vertex::setColor(char c){
			color = c;
		}


		// Returns name

		int Vertex::getName(){
			return name;
		}


		// Returns parent

		int Vertex::getParent(){
			return parent;
		}


		// Returns discovery time

		int Vertex::getD(){
			return d;
		}


		// Returns finish time

		int Vertex::getF(){
			return f;
		}


		// Returns color

		char Vertex::getColor(){
			return color;
		}	