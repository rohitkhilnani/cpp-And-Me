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


// tests reverse
void testReverse(){

	std::cout<<"Test Reverse\n";

	// define vector of values
	std::vector<int> values = {10,9,8,7,6,5,4,3,2,1};

	// Create linked list
	LinkedList ll;

	for(auto x: values){

		ll.insertFirst(x);
	}	

	ll.print();

	ll.reverse();

	ll.print();

	ll.delete_node(0);

	ll.print();

	ll.reverse();

	ll.print();

	for(int i=0;i<7;i++)
		ll.delete_node(0);

	ll.print();

	ll.reverse();

	ll.print();

	ll.delete_node(0);

	ll.print();

	ll.reverse();

	ll.print();

	ll.delete_node(0);

	ll.print();

	ll.reverse();

	ll.print();


}


// tests pairwiseReverse
void testpairwiseReverse(){

	std::cout<<"Test Pairwise Reverse\n";

	// define vector of values
	std::vector<int> values = {10,9,8,7,6,5,4,3,2,1};

	// Create linked list
	LinkedList ll;

	for(auto x: values){

		ll.insertFirst(x);
	}	

	ll.print();

	ll.pairwiseReverse();

	ll.print();

	ll.delete_node(0);

	ll.print();

	ll.pairwiseReverse();

	ll.print();

	for(int i=0;i<6;i++)
		ll.delete_node(0);

	ll.print();

	ll.pairwiseReverse();

	ll.print();

	ll.delete_node(0);

	ll.print();

	ll.pairwiseReverse();

	ll.print();

	ll.delete_node(0);

	ll.print();

	ll.pairwiseReverse();
	
	ll.print();


}


// tests hasLoop

void testHasLoop(){

	LinkedList l1(1);

	if(l1.hasLoop()!=nullptr)
		std::cout<<"\nl1 has loop";
	else
		std::cout<<"\nl1 does not have loop";

	LinkedList l2;
	for(int i=1;i<=5;i++)
		l2.insertLast(i);

	if(l2.hasLoop()!=nullptr)
		std::cout<<"\nl2 has loop";
	else
		std::cout<<"\nl2 does not have loop";


	LinkedList l3(2);

	if(l3.hasLoop()!=nullptr)
		std::cout<<"\nl3 has loop";
	else
		std::cout<<"\nl3 does not have loop";


	LinkedList l4(3);

	if(l4.hasLoop()!=nullptr)
		std::cout<<"\nl4 has loop";
	else
		std::cout<<"\nl4 does not have loop";
}


//tests remove loop

void testRemoveLoop(){

	LinkedList l1(1);

	Node * loopnode1 = l1.hasLoop();

	if(loopnode1!=nullptr)
		std::cout<<"\nl1 has loop";
	else
		std::cout<<"\nl1 does not have loop";

	l1.removeLoop(loopnode1);

	loopnode1 = l1.hasLoop();

	if(loopnode1!=nullptr)
		std::cout<<"\nl1 has loop";
	else
		std::cout<<"\nl1 does not have loop";

	l1.print();


	LinkedList l3(2);

	Node * loopnode3 = l3.hasLoop();

	if(loopnode3!=nullptr)
		std::cout<<"\nl3 has loop";
	else
		std::cout<<"\nl3 does not have loop";

	l3.removeLoop(loopnode3);

	loopnode3 = l3.hasLoop();

	if(loopnode3!=nullptr)
		std::cout<<"\nl3 has loop";
	else
		std::cout<<"\nl3 does not have loop";
	
	l3.print();

	
	LinkedList l4(3);

	Node *loopnode4 = l4.hasLoop();

	if(loopnode4!=nullptr)
		std::cout<<"\nl4 has loop";
	else
		std::cout<<"\nl4 does not have loop";

	l4.removeLoop(loopnode4);

	loopnode4 = l4.hasLoop();

	if(loopnode4!=nullptr)
		std::cout<<"\nl4 has loop";
	else
		std::cout<<"\nl4 does not have loop";	

	l4.print();

}


// test find length

void testFindLength(){

	std::cout<<"Test Find length\n";

	// define vector of values
	std::vector<int> values = {9,8,7,6,5,4,3,2,1};

	// create linked list
	LinkedList ll;

	std::cout<<"\nList: ";
	ll.print();
	std::cout<<"Length: "<<ll.findLength()<<"\n";

	// insert values into linked list (always at beginning i.e. index 0)
	for(auto x: values){
		ll.insertFirst(x);
		std::cout<<"\nList: ";
		ll.print();
		std::cout<<"Length: "<<ll.findLength()<<"\n";
	}




}



// test single swap kth

void testSwapKth(LinkedList ll, int k){
	std::cout<<"k = "<<k<<"\n";
	std::cout<<"Before: ";
	ll.print();
	ll.swapKth(k);
	std::cout<<"After: ";
	ll.print();

}



// tests swapKth()

void testSwapKth(){

	std::cout<<"Test Swap Kth\n";

	LinkedList ll;
	testSwapKth(ll,2);

	ll.insertLast(10);
	testSwapKth(ll,1);

	ll.insertLast(15);
	testSwapKth(ll,1);
	testSwapKth(ll,2);

	ll.insertLast(20);
	testSwapKth(ll,1);
	testSwapKth(ll,2);
	testSwapKth(ll,3);
	testSwapKth(ll,4);

	for(int i=25;i<=45;i+=5)
		ll.insertLast(i);

	testSwapKth(ll,1);
	testSwapKth(ll,2);
	testSwapKth(ll,4);
	testSwapKth(ll,5);
	testSwapKth(ll,8);

}


void testRemoveDuplicates(LinkedList l){

	std::cout<<"Before: ";
	l.print();
	l.removeDuplicates();
	std::cout<<"After: ";
	l.print();
	std::cout<<"\n";
}


// tests remove duplicates

void testRemoveDuplicates(){

	std::cout<<"Testing remove duplicates: \n";

	LinkedList l1;
	testRemoveDuplicates(l1);

	l1.insertLast(5);
	testRemoveDuplicates(l1);

	
	LinkedList l2;
	
	for(int i = 1;i<=5;i++)
		l2.insertLast(i);
	
	for(int i = 1;i<=5;i++)
		l2.insertLast(i);

	for(int i = 6;i<=10;i++)
		l2.insertLast(i);
	
	testRemoveDuplicates(l2);


	LinkedList l3;

	for(int i = 1;i<=15;i++)
		l3.insertLast(2);

	testRemoveDuplicates(l3);


	LinkedList l4;
	
	for(int i=0;i<9;i++)
		l4.insertLast(i);

	testRemoveDuplicates(l4);


	LinkedList l5;
	
	l5.insertLast(2);
	l5.insertLast(2);
	l5.insertLast(5);
	l5.insertLast(8);
	l5.insertLast(8);

	testRemoveDuplicates(l5);


	LinkedList l6;

	for(int i = 0;i<5;i++)
		for(int j=0;j<2;j++)
			l6.insertLast(j);

	testRemoveDuplicates(l6);	

}



int main(){

	// test insert
	testInsert();

	// test B
	testB();

	// test delete
	testDelete();

	// test reverse
	testReverse();

	// test pairwise reverse
	testpairwiseReverse();

	// test hasLoop
	testHasLoop();

	// test remove loop
	testRemoveLoop();

	// test find length
	testFindLength();	

	testSwapKth();

	// test remove duplicates
	testRemoveDuplicates();

	return 0;
}
