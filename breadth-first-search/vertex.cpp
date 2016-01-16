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


		// Sets distance

		void Vertex::setDistance(int d){
			distance = d;
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


		// Returns distance

		int Vertex::getDistance(){
			return distance;
		}


		// Returns Color

		char Vertex::getColor(){
			return color;
		}	

