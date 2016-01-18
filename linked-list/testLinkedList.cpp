/*
	This program tests class LinkedList
*/

#include<iostream>
#include<vector>
#include "linkedlist.h"

// tests insertion

void testInsert(){

	std::cout<<"Test Insert\n";

	// define vector of values
	std::vector<int> values = {6,5,4,3,2,1};

	// create linked list
	LinkedList ll;

	// insert values into linked list (always at beginning i.e. index 0)
	for(auto x: values){
		ll.insertFirst(x);
	}

	// display linked list
	ll.print();

	// insert 100 at end
	ll.insertLast(100);

	// display linked list
	ll.print();

	// insert in between
	ll.insert_node(3,5000);

	// display linked list
	ll.print();


}


// tests valueAt() and getLength()

void testB(){

	std::cout<<"Test B\n";

	// define vector of values
	std::vector<int> values = {6,5,4,3,2,1};

	// create linked list
	LinkedList ll;

	// insert values into linked list (always at beginning i.e. index 0)
	for(auto x: values){
		ll.insertFirst(x);
	}

	// insert 100 at end
	ll.insertLast(1000);

	// insert in between
	ll.insert_node(3,5000);

	// display linked list
	ll.print();	

	std::cout<<"Length: "<<ll.getLength();
	

	for(int i=0;i<ll.getLength();i++){
		
		std::cout<<"\nValut at "<<i<<": "<<ll.valueAt(i);

	}

}


int main(){

	// test insert
	testInsert();

	// test B
	testB();

	return 0;
}
