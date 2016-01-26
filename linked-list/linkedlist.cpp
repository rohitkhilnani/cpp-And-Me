/*
	Definition for linkedlist.h
*/

#include "linkedlist.h"

	// Displays linked list
	// Time Complexity: O(N) 	N - no. of nodes in linked list

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
	// Time Complexity: O(N) 	N - no. of nodes in linked list

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
	// Time Complexity: O(1)

	void LinkedList::insertFirst(int value){
		insert_node(0,value);
	}


	// Inserts node with specified value 'value' at end
	// Time Complexity: O(N) 	N - no. of nodes in linked list

	void LinkedList::insertLast(int value){
		insert_node(length,value);
	}	


	// Returns length of linked list
	// Time Complexity: O(1)

	int LinkedList::getLength(){

		return length;
	}

	// Returns value at specified location in linked list
	// returns numeric_limits<int>::min if index is invalid
	// Time Complexity: O(N) 	N - no. of nodes in linked list

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
	// Time Complexity: O(N) 	N - no. of nodes in linked list

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
	// Time Complexity: O(N) 	N - no. of nodes in linked list

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
	// Time Complexity: O(N) 	N - no. of nodes in linked list

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
	// Time Complexity: O(N) 	N - no. of nodes in linked list

		LinkedList::~LinkedList(){

		// to keep track of nodes deleted in case of loop in linked list. 
		// break when number of deleted nodes = length of list	
		int delCount = 0;	

		// obtain two pointers
		Node *prev = nullptr, *curr = head;

		// while current is not null
		while(curr!=nullptr && delCount < length){

			// move prev to curr
			prev = curr;

			// move curr to its next
			curr = curr->getNext();

			// deallocate prev
			delete prev;
			delCount++;
		}


		}

	// Detects loop in linked list
	// Returns pointer to common node in list
	// Time Complexity: O(N) 	N - no. of nodes in linked list	

		Node* LinkedList::hasLoop(){

			// if list is empty, return nullptr
			if(head == nullptr){
				return nullptr;
			}

			// Get two pointers to head
			// slow moves one node at a time and fast moves two nodes at a time	
			Node *slow = head, *fast = head;

			while(slow!=nullptr && fast!=nullptr && fast->getNext()!=nullptr){

				// move slow ahead by 1
				slow = slow->getNext();

				// move fast ahead by 2
				fast = fast->getNext()->getNext();

				// if slow == fast, loop exists. Return common node's pointer
				if(slow == fast)
					return slow;



			}

			// If loop breaks because of null pointer being encountered, loop does not exist. Return nullptr
			return nullptr;

		}		

	// Constructs linked list with default values

	LinkedList::LinkedList(){

	}


	// Constructs linkedlist with loop based on loop id
	// only to test loop related operations

	LinkedList::LinkedList(int id){

		// test linked list 1

		if(id == 1){

			for(int i=1;i<=5;i++)
				insertLast(i);

			Node *ptr = head;

			while(ptr->getNext()!=nullptr)
				ptr = ptr->getNext();

			// create loop
			ptr->setNext(head);

		}
	else if(id == 2){

			for(int i=1;i<=5;i++)
				insertLast(i);

			Node *ptr = head;

			while(ptr->getNext()!=nullptr)
				ptr = ptr->getNext();

			// create loop
			ptr->setNext(ptr);


	}

	else if(id == 3){

			for(int i=1;i<=3;i++)
				insertLast(i);

			Node *ptr = head;

			while(ptr->getNext()!=nullptr)
				ptr = ptr->getNext();

			for(int i=4;i<=7;i++)
				insertLast(i);

			Node *ptr2 = head;

			while(ptr2->getNext()!=nullptr)
				ptr2 = ptr2->getNext();

			// create loop
			ptr2->setNext(ptr);

	}	

	}


	// Removes loop from linked list
	// Assumes loopnode to be one of the nodes of the loop as detected and returned by hasLoop
	// Time Complexity: O(N) 	N - no. of nodes in linked list

	void LinkedList::removeLoop(Node* loopnode){


		// if loopnode is same as head (starting node of loop is head)
		if(loopnode == head){

			// traverse to last node
			Node *ptr = head;

			while(ptr->getNext()!=head)
				ptr=ptr->getNext();

			// set its next to null
			ptr->setNext(nullptr);

			// return
			return;
		}	


		// Otherwise, ...

		// obtain a pointer to save previous of ptr2 while traversing
		Node *save = nullptr;

		// obtain a pointer to head and loopnode
		Node *ptr = head, *ptr2 = loopnode;

		// move ptr and ptr2 forward by 1 until both are same
		while(ptr!=ptr2){

			// save ptr2
			save = ptr2;

			// move ptr1 and ptr2 ahead by 1
			ptr = ptr->getNext();
			ptr2 = ptr2->getNext();

			
		}

		// save is the last node. set its next to null
		save->setNext(nullptr);
	}

	// Finds length, assuming length is not available before hand
	// Time Complexity: O(N) 	N - no. of nodes in linked list

	int LinkedList::findLength(){

		
		// length is zero if list is empty
		if(head == nullptr)
			return 0;

		// obtain pointer to head
		Node *fast = head;

		// length 
		int len = 1;

		// repeat while fast, fast's next and fast's next's next are not null
		while(fast!=nullptr && fast->getNext()!=nullptr && fast->getNext()->getNext()!=nullptr){

			// increase length by 2
			len+=2;

			// move fast ahead by 2
			fast = fast->getNext()->getNext();

		}

		// check if one more node exists after fast. if yes, increment lenth by 1 
		while(fast->getNext()!=nullptr){
			
			len++;
			fast=fast->getNext();
		}

		return len;
	}

	// Swaps kth node from beginning and end by exchanging pointers and without copying any data
	// Time Complexity: O(N) 	N - no. of nodes in linked list

	void LinkedList::swapKth(int k){

		if(head == nullptr)
			return;

		// find length of list
		int n = findLength();

		// invalid k
		if(k > n){
			std::cout<<"Invalid k\n";
			return;
		}

		// swapping a node with itself - no change
		if(2*k == n + 1){
			return;
		}

		// obtain four pointers
		Node *prev1 = nullptr, *prev2 = nullptr , *curr1 = head, *curr2 = head;

		// move curr1 ahead k-1 times (such that prev1 is just before curr1)
		for(int i=0;i<k-1;i++){
			prev1 = curr1;
			curr1 = curr1->getNext();
		}

		// move curr2 ahead n-k times (such that prev2 is just before curr2)
		for(int i=0;i<n-k;i++){
			prev2 = curr2;
			curr2 = curr2->getNext();	
		}

		// if prev1 is not null, point its next to curr2
		if(prev1!=nullptr)
			prev1->setNext(curr2);
		else //  otherwise, set new head as curr2
			head = curr2;

		// if prev2 is not null, point its next to curr1		
		if(prev2!=nullptr)
			prev2->setNext(curr1);
		else // otherwise, set new head as curr1
			head = curr1;		


		// swap next pointers of curr1 and curr2
		Node *t = curr1->getNext();
		curr1->setNext(curr2->getNext());
		curr2->setNext(t);	

	}
		

	// Add copy constructor

	LinkedList::LinkedList(const LinkedList &ll){

		// obtain pointer to first element of list to be copied
		Node *ptr = ll.head;

		// insert each element into new list until ptr null
		while(ptr!='\0'){

			insertLast(ptr->getValue());

			// move ptr ahead
			ptr = ptr->getNext();

		}


	}

	// Removes duplicate nodes from list
	// Time Complexity: O(N)
	// Space Complexity: O(N)		N - no. of nodes in linked list
	// Preserves order of elements
	void LinkedList::removeDuplicates(){

		// do nothing if list is empty or has just one node
		if(head == nullptr || head->getNext() == nullptr)
			return;

		// Obtain two pointers to Node
		Node *prev = nullptr, *curr = head;

		// define set of discovered nodes
		std::unordered_set<int> keys;

		// repeat until curr is null
		while(curr!=nullptr){

			// if current node's value is not in set keys
			if(keys.find(curr->getValue()) == keys.end()){

				// insert the value in keys
				keys.insert(curr->getValue());

				// move prev to curr
				prev = curr;	

				// move curr to next node
				curr = curr->getNext();

			}
			else {  // if value is in keys (duplicate)

				// set prev's next to curr's next
				prev->setNext(curr->getNext());

				// deallocate memory used by curr
				delete curr;

				// set curr as prev's next
				curr = prev->getNext();	


			}

		}

	}