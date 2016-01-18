/*
	This header defines linked list
*/

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include<iostream>
#include<limits>
#include "node.h" 		// My implementation of node

class LinkedList{


	private: 

		Node* head = nullptr; 		// points to first node of linked list
		int length = 0;				// number of nodes in linked list

	public:
	
		// Displays linked list

		void print();


		// Inserts node with specified value 'value' at specified location 'i'

		void insert_node(int i, int value);

		
		// Inserts node with specified value 'value' at beginning

		void insertFirst(int value);


		// Inserts node with specified value 'value' at end

		void insertLast(int value);


		// Returns length of linked list

		int getLength();


		// Returns value at specified location in linked list
		// returns numeric_limits<int>::min if index is invalid

		int valueAt(int i);


		// Deletes node at specified index i

		void delete_node(int i);


		// Reverses linked list

		void reverse();


		// (Pair-wise) reverses linked list

		void pairwiseReverse();

};




#endif