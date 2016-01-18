/*
	Definition for linkedlist.h
*/

#include "linkedlist.h"

// Displays linked list

	void LinkedList::print(){

		// Point to head
		Node* n = head;

		// repeat while n is not null
		while(n!=nullptr){

			std::cout<<n->getValue()<<" ";

			// Move n to next node
			n = n->getNext();
		}

		std::cout<<"\n";

	}		


// Inserts node with specified value 'value' at specified location 'i'

	void LinkedList::insert_node(int i, int value){

		// if invalid index i, print error message and return
		if(i < 0 || i > length){

			std::cout<<"Invalid location: "<<i<<std::endl;
			return;
		}

		// Create new node with specified value
		Node *n = new Node(value);


		// Handle insertion at beginning
		if(i == 0){

			// set n's next to head
			n->setNext(head);	

			// set n as head
			head = n;
		}
		else {  // Handle other cases


			// Get a pointer to head
			Node *ptr = head;

			// Move pointer ahead (i-1) times
			for(int k=0;k<(i-1);k++)
				ptr = ptr->getNext();

			// point n's next to ptr's next
			n->setNext(ptr->getNext());

			// point ptr's next to n
			ptr->setNext(n);

		}

		// increment length of linked list
		length++;


	}

	// Inserts node with specified value 'value' at beginning

	void LinkedList::insertFirst(int value){
		insert_node(0,value);
	}


	// Inserts node with specified value 'value' at end

	void LinkedList::insertLast(int value){
		insert_node(length,value);
	}	


	// Returns length of linked list

	int LinkedList::getLength(){

		return length;
	}

	// Returns value at specified location in linked list
	// returns numeric_limits<int>::min if index is invalid

	int LinkedList::valueAt(int i){

		// if index is invalid, print error message and return
		if(i<0 || i>=length){

			std::cout<<"Invalid index"<<i<<std::endl;
			return std::numeric_limits<int>::min();
		}

		// get pointer to head
		Node* ptr = head;

		// move pointer ahead i times
		for(int k=0;k<i;k++)
			ptr = ptr->getNext();

		// return value at pointer
		return  ptr->getValue();

	}






