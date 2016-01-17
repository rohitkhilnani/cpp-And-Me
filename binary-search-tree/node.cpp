/*
	Definition for node.h
*/

#include "node.h"

// Constructs Node with specified value

	Node::Node(int v){
		value = v;	
	}	


	// Constructs node with default values

	Node::Node(){

	}


	// Sets value

	void Node::setValue(int v){
		value = v;
	}


	// Sets Left subtree

	void Node::setLeft(Node* l){
		left = l;
	}


	// Sets Right subtree

	void Node::setRight(Node* r){
		right = r;
	}


	// Returns value

	int Node::getValue(){
		return value;
	}


	// Returns left subtree

	Node* Node::getLeft(){
		return left;
	}


	// Returns right subtree

	Node* Node::getRight(){
		return right;
	}
