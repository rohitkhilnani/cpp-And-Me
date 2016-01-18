/*
	This header defines node for linked list
*/

#ifndef __LINKED_LIST_NODE__
#define __LINKED_LIST_NODE__


class Node{

	private: 

		int value = 0;				// stored value
		Node* next = nullptr;		// pointer to next node

	public:
	
		// constructs Node with specified value

		Node(int val);


		// constructs Node with default values

		Node();	


		// sets value

		void setValue(int val);


		// sets next pointer

		void setNext(Node* n);


		// Returns value

		int getValue();


		// Returns next pointer

		Node* getNext();


};




#endif	