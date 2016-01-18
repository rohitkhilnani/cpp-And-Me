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

	ll.valueAt(-500);

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

	ll.valueAt(500);

}


// tests deletion

void testDelete(){

	std::cout<<"Test Delete\n";

	// define vector of values
	std::vector<int> values = {20,18,16,15,14,12,10,8,6,4,1,2,0};

	// Create linked list
	LinkedList ll;

	for(auto x: values){

		ll.insertFirst(x);
	}	

	ll.print();

	std::cout<<"\nDelete index: 9\n";
	ll.delete_node(9);
	ll.print();

	std::cout<<"\nDelete index : 2\n";
	ll.delete_node(2);
	ll.print();

	std::cout<<"\nDelete index: 0\n";
	ll.delete_node(0);
	ll.print();

	std::cout<<"\nDelete index: 9\n";
	ll.delete_node(9);
	ll.print();

}

int main(){

	// test insert
	testInsert();

	// test B
	testB();

	// test delete
	testDelete();

	return 0;
}
