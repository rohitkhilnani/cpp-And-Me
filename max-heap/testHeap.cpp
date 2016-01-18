/*
	This program tests heap.h
*/

#include<iostream>
#include "maxheap.h"
#include<vector>

// tests constructor, make_max_heap and sort heap

void  testHeapA(){

	std::cout<<"Test A\n";	

	// define vector
	std::vector<int> v1 = {6,4,99,5,7,5,0,3,1,6,4,8,9,56,9,2,3,2};
 
 	// create max heap and initialize with vector
	Maxheap mh1 = v1;

	// display
	mh1.print_heap();

	// make heap
	mh1.make_max_heap();	

	// display
	mh1.print_heap();

	// sort heap
	mh1.sort_heap();

	// display
	mh1.print_heap();

//--------------------------

	// define vector
	std::vector<int> v2 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
 
 	// create max heap and initialize with vector
	Maxheap mh2 = v2;

	// display
	mh2.print_heap();

	// make heap
	mh2.make_max_heap();	

	// display
	mh2.print_heap();

	// sort heap
	mh2.sort_heap();

	// display
	mh2.print_heap();


}	


// tests delete key

void testDelete(){

	std::cout<<"Test Delete\n";	

	// define vector
	std::vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
 
 	// create max heap and initialize with vector
	Maxheap mh1 = v1;

	// display
	mh1.print_heap();

	// make heap
	mh1.make_max_heap();	

	// display
	mh1.print_heap();

	mh1.extract_max();
	mh1.extract_max();

	mh1.print_heap();

	mh1.deleteKey(2);
	mh1.print_heap();

	mh1.deleteKey(5);
	mh1.print_heap();

	mh1.increase_key(5,6);
	mh1.print_heap();

	mh1.deleteKey(3);
	mh1.print_heap();

	for(int i=0;i<5;i++)
		mh1.deleteKey(0);

	mh1.print_heap();

}

// Tests insert key

void testInsert()
{
	std::cout<<"Test Insert\n";	

	// define vector
	std::vector<int> v1 = {100,50,40,20,30,35};
 
 	// create max heap and initialize with vector
	Maxheap mh1 = v1;

	mh1.print_heap();

	mh1.insertKey(30);
	mh1.print_heap();

	mh1.insertKey(70);
	mh1.print_heap();

	mh1.insertKey(200);
	mh1.print_heap();	



}

int main(){

	// tests constructor, make heap and sort heap
	testHeapA();	

	// test delete
	testDelete();

	// test insert
	testInsert();
}	