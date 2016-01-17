/*
	This header defines Binary Search Tree
*/

#ifndef __BST_BST__
#define __BST_BST__	

#include<iostream>
#include "node.h"  	// My implementation of node 
#include<queue>

class Bst{

	private:

		Node* root = nullptr;

	protected:
	
		// Inserts new node with specified value at sub-tree rooted at n. 
		// Returns root.

		Node* insert(Node* n, int value);


		// Visits Node in in order fashion

		void inOrderVisit(Node *n);


		// Visits Node in pre order fashion

		void preOrderVisit(Node *n);


		// Visits Node in post order fashion	

		void postOrderVisit(Node *n);


		// Deletes key k from tree rooted at n
		// Returns n (root of the subtree)

		Node* deleteKey(Node* n, int key);

		
		// Returns pointer to inorder successor of node n if exists

		Node* findSucc(Node *n);



	public:	

		// Inserts new node with specified value in the tree

		void insert(int value);


		// In order traversal of tree

		void inOrder();


		// Pre order traversal of tree

		void preOrder();


		// Post order traversal of tree

		void postOrder();


		// Level order traversal of tree

		void levelOrder();


		// Deallocates tree rooted at n

		void deallocate(Node *n);


		// Destructor - deallocates tree

		~Bst();


		// Deletes key k from tree 

		void deleteKey(int key);




};




#endif	