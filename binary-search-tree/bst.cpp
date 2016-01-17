/*
	Definition for bst.h

*/

#include "bst.h"

	// Inserts new node with specified value at sub-tree rooted at n. 
	// Returns root.

	Node* Bst::insert(Node* n, int value){

		// If n is null, allocate new node 
		if(n == nullptr){
			n = new Node(value);
		}

		else if(value < n->getValue()){  		// If value less than value at n

			// Insert in  left subtree of n
			n->setLeft(insert(n->getLeft(), value));
		}

		else{ // otherwise, insert in right subtree of n

			n->setRight(insert(n->getRight(), value));

		}

		// return n
		return n;	

	}


	// Visits Node in in order fashion

	void Bst::inOrderVisit(Node *n){

		// Return if n is null

		if(n==nullptr){
			return;
		}

		// Otherwise, visit left subtree
		inOrderVisit(n->getLeft());

		// print value at n
		std::cout<<n->getValue()<<" ";

		// visit right subtree
		inOrderVisit(n->getRight());


	}


	// Visits Node in pre order fashion

	void Bst::preOrderVisit(Node *n){

		// Return if n is null

		if(n==nullptr){
			return;
		}

		// print value at n
		std::cout<<n->getValue()<<" ";	

		// Otherwise, visit left subtree
		preOrderVisit(n->getLeft());

		
		// visit right subtree
		preOrderVisit(n->getRight());


	}


	// Visits Node in post order fashion

	void Bst::postOrderVisit(Node *n){

		// Return if n is null

		if(n==nullptr){
			return;
		}

		
		// Otherwise, visit left subtree
		postOrderVisit(n->getLeft());
		
		// visit right subtree
		postOrderVisit(n->getRight());

		// print value at n
		std::cout<<n->getValue()<<" ";	


	}


	// Inserts new node with specified value in the tree

	void Bst::insert(int value){

		root = insert(root, value);	
	}		


	// In order traversal of tree

	void Bst::inOrder(){

		inOrderVisit(root);
		std::cout<<std::endl;
	}


	// Pre order traversal of tree

	void Bst::preOrder(){

		preOrderVisit(root);
		std::cout<<std::endl;
	}


	// Post order traversal of tree

	void Bst::postOrder(){

		postOrderVisit(root);
		std::cout<<std::endl;
	}


	// Level order traversal of tree

	void Bst::levelOrder(){

		// Return if root is null
		if(root == nullptr)
			return;

		// define queue
		std::queue<Node*> que;

		// enqueue root
		que.push(root);

		//while que is non empty
		while(!que.empty()){

			// remove node (reference) from queue
			Node *u = que.front();
			que.pop();

			// print u
			std::cout<<u->getValue()<<" ";

			// enqueue left and right children of u, if they are not null
			if(u->getLeft()!=nullptr)
				que.push(u->getLeft());

			if(u->getRight()!=nullptr)
				que.push(u->getRight());

		}

		std::cout<<std::endl;


	}

	void Bst::deallocate(Node *n){

		// return if n is null
		if(n==nullptr)
			return;
		else{	
			// otherwise, deallocate left subtree
			deallocate(n->getLeft());

			// deallocate right subtree
			deallocate(n->getRight());

			// delete n
			delete n;	

		}

	}

	Bst::~Bst(){

			// deallocate tree rooted at root
			deallocate(root);
		}