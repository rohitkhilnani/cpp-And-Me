/*
	Definition for node.h
*/

#include "node.h"	

	// constructs Node with specified value

	Node::Node(int val){

		value = val;
	}	


	// constructs Node with default values

	Node::Node(){

	}		


	// sets value

	void Node::setValue(int val){

		value = val;
	}


	// sets next pointer

	void Node::setNext(Node* n){

		next = n;
	}


	// Returns value

	int Node::getValue(){
	
		return value;
	}


	// Returns next pointer

	Node* Node::getNext(){

		return next;
	}
