/*
	This header defines linked list
*/

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include<iostream>
#include<limits>
#include<unordered_set>	
#include "node.h" 		// My implementation of node

class LinkedList{


	private: 

		Node* head = nullptr; 		// points to first node of linked list
		int length = 0;				// number of nodes in linked list

	public:
	

		// Displays linked list
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		void print();


		// Inserts node with specified value 'value' at specified location 'i'
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		void insert_node(int i, int value);

		
		// Inserts node with specified value 'value' at beginning
		// Time Complexity: O(1)

		void insertFirst(int value);


		// Inserts node with specified value 'value' at end
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		void insertLast(int value);


		// Returns length of linked list
		// Time Complexity: O(1)

		int getLength();


		// Returns value at specified location in linked list
		// returns numeric_limits<int>::min if index is invalid
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		int valueAt(int i);


		// Deletes node at specified index i
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		void delete_node(int i);


		// Reverses linked list
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		void reverse();


		// (Pair-wise) reverses linked list
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		void pairwiseReverse();


		// Deallocate linked list
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		~LinkedList();


		// Detects loop in linked list
		// Returns pointer to common node in list
		// Time Complexity: O(N) 	N - no. of nodes in linked list	

		Node* hasLoop();


		// Constructs linked list with default values

		LinkedList();


		// Constructs linkedlist with loop based on loop id
		// only to test loop related operations

		LinkedList(int id);


		// Removes loop from linked list
		// Assumes loopnode to be one of the nodes of the loop as detected and returned by hasLoop
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		void removeLoop(Node* loopnode);


		// Finds length, assuming length is not available before hand
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		int findLength();


		// Swaps kth node from beginning and end by exchanging pointers and without copying any data
		// Time Complexity: O(N) 	N - no. of nodes in linked list

		void swapKth(int k);


		// Add copy constructor

		LinkedList(const LinkedList &ll);


		// Removes duplicate nodes from list (unsorted)
		// Time Complexity: O(N)
		// Space Complexity: O(N)		N - no. of nodes in linked list
		// Preserves order of elements
		
		void removeDuplicates();

		

};




#endif