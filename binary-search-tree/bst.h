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
		// Time Complexity: 
		//		Worst Case: O(N) 			N - no. of nodes in tree
		//		Average Case: O(log(N)) 
		// Space Complexity: O(N)	

		Node* insert(Node* n, int value);


		// Visits Node in in order fashion
		// Time Complexity: O(N) 
		// Space Complexity: O(N)		

		void inOrderVisit(Node *n);


		// Visits Node in pre order fashion
		// Time Complexity: O(N) 
		// Space Complexity: O(N)		


		void preOrderVisit(Node *n);


		// Visits Node in post order fashion	
		// Time Complexity: O(N) 
		// Space Complexity: O(N)		


		void postOrderVisit(Node *n);


		// Deletes key k from tree rooted at n
		// Returns n (root of the subtree)
		// Time Complexity: 
		//		Worst Case: O(N) 			N - no. of nodes in tree
		//		Average Case: O(log(N)) 
		// Space Complexity: O(N)	

		Node* deleteKey(Node* n, int key);

		
		// Returns pointer to inorder successor of node n if exists
		// Time Complexity: O(N) 
		// Space Complexity: O(N)		


		Node* findSucc(Node *n);


		// Finds specified key in tree rooted at specified node n and returns pointer to its node
		// Otherwise, returns nullptr
		// Time Complexity: 
		//		Worst Case: O(N) 			N - no. of nodes in tree
		//		Average Case: O(log(N)) 
		// Space Complexity: O(N)	(May improve if tail recursion is optimized)

		Node* find(Node* n, int key);


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
		// Time Complexity: O(N) 
		// Space Complexity: O(N)		


		void levelOrder();


		// Deallocates tree rooted at n
		// Time Complexity: O(N) 
		// Space Complexity: O(N)		


		void deallocate(Node *n);


		// Destructor - deallocates tree

		~Bst();


		// Deletes key k from tree 

		void deleteKey(int key);


		// Finds key in tree and returns pointer to its node if it exists.
		// Otherwise returns null

		Node* find(int key);
	
};




#endif	