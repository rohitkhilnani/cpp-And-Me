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


	// Deletes node at specified index i

	void LinkedList::delete_node(int i){


		// if list is empty, print underflow message
		if(head == nullptr){
			std::cout<<"List empty";
			return;
		}

		// if index is invalid, print error message and return
		if(i<0 || i>=length){

			std::cout<<"invalid index "<<i<<std::endl;
			return;
		}


		// Handle deletion at beginning
		if(i == 0){

			// save head
			Node *temp = head;

			// Move head to next node
			head = head->getNext();

			// deallocate temp's memory
			delete temp;
		}
		else {  // Handle other cases

			// get pointer to head
			Node *ptr = head;

			// move ptr ahead (i-1) times
			for(int k = 0;k<(i-1);k++)
				ptr = ptr->getNext();

			// save pointer to ptr's next
			Node *temp = ptr->getNext();

			// point ptr's next to ptr's next's next
			ptr->setNext(ptr->getNext()->getNext());			


			// deallocate temp's memory
			delete temp;

		}

		// reduce length by 1
		length--;

	}


	// Reverses linked list

	void LinkedList::reverse(){

		// Dont do anything if list has less than two nodes
		if(head == nullptr || head->getNext() == nullptr)
			return;

		// Obtain three pointers 
		Node *prev = nullptr, *curr = head, *next = head->getNext();

		// repeat while curr is not null
		while(curr!=nullptr){

			// point curr's next to prev
			curr->setNext(prev);

			// move prev to curr
			prev = curr;

			// move curr to next
			curr = next;

			// if next is not null, move next to its next 
			if(next!=nullptr)
				next = next->getNext();


		}

		// make prev new head
		head = prev;

	}


	// (Pair-wise) reverses linked list

	void LinkedList::pairwiseReverse(){

		// if there are less than two nodes in linked list, 

		// Dont do anything if list has less than two nodes
		if(head == nullptr || head->getNext() == nullptr)
			return;

		// Obtain three pointers 
		Node *prev = nullptr, *curr = head, *next = head->getNext();

		// set next as new head
		head = next;

		// repeat while both curr and next are not null
		while(curr!=nullptr && next!=nullptr){

			// set curr's next to next's next
			curr->setNext(next->getNext());

			// set next's next to curr
			next->setNext(curr);

			// if prev is not null, set prev's next to next
			if(prev!=nullptr){

				prev->setNext(next);	
			}


			// move prev to curr
			prev = curr;

			// move curr to its next
			curr = curr->getNext();

			// if curr is not null, move next to curr's next
			if(curr!=nullptr)
				next = curr->getNext();

		}



	}

	// Deallocate linked list

		LinkedList::~LinkedList(){

			// obtain two pointers
			Node *prev = nullptr, *curr = head;

			// while current is not null
			while(curr!=nullptr){

				// move prev to curr
				prev = curr;

				// move curr to its next
				curr = curr->getNext();

				// deallocate prev
				delete prev;
			}


		}