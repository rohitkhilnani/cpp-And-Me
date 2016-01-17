/*
	This program tests insertion sort
*/

#include<iostream>
#include<vector>
#include "sort.h"	// My implementation of some sorting algorithms on std::vector of int

// Displays vector

void printVector(std::vector<int> A){
	for(auto x: A){
		std::cout<<x<<" ";

	}
	std::cout<<std::endl;	
}


// Tests insertion sort on vector A

void testInsertionSort(std::vector<int> A){

	std::cout<<"Before: ";
	printVector(A);
	insertionSort(A);
	std::cout<<"After: ";
	printVector(A);
}


// tests insertion sort on several different inputs

void testInsertionSort(){

	std::vector<int> v1 = {10,9,8,7,6,5,4,3,2,1};
	testInsertionSort(v1);

	std::vector<int> v2 = {5,4,3,2,1};
	testInsertionSort(v2);

	std::vector<int> v3 = {1,2,3,4,5,6,7,8,9,10};
	testInsertionSort(v3);

	std::vector<int> v4 = {6,5,4,7,8,9,9,5,4,9,2,0,3,1,5,9,8,7,4,5,6,3};
	testInsertionSort(v4);

	// test on empty vector
	std::vector<int> v5;
	testInsertionSort(v5);

	std::vector<int> v6 = {2,4,-6,1,-9,3,0};
	testInsertionSort(v6);

	std::vector<int> v7 = {1,2,3,4,5,6,7,8,9,0};
	testInsertionSort(v7);
}


int main(){

	// test insertion sort
	testInsertionSort();

	return 0;
}

