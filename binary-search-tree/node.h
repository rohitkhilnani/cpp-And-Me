/*
	This class defines node for binary search tree
*/

#ifndef __BST_NODE__
#define __BST_NODE__


class Node{

	private:

		int value = 0;			// Value stored
		Node* left=nullptr, *right=nullptr;		// Pointers to left and right sub tree

	public:
	
		// Constructs Node with specified value

		Node(int v);


		// Constructs node with default values

		Node();


		// Sets value

		void setValue(int v);


		// Sets Left subtree

		void setLeft(Node* l);


		// Sets Right subtree

		void setRight(Node* r);


		// Returns value

		int getValue();


		// Returns left subtree

		Node* getLeft();


		// Returns right subtree

		Node* getRight();

};

#endif	