/*
	This program tests merge sort
*/

#include<iostream>
#include<vector>
#include "mergesort.h"	// My implementation of merge sort

// Displays vector

void printVector(std::vector<int> A){
	for(auto x: A){
		std::cout<<x<<" ";

	}
	std::cout<<std::endl;	
}


// Tests merge sort on vector A

void testMergeSort(std::vector<int> A){

	std::cout<<"Before: ";
	printVector(A);
	Mergesort::mergesort(A);
	std::cout<<"After: ";
	printVector(A);
}


// tests merge sort on several different inputs

void testMergeSort(){

	std::vector<int> v1 = {10,9,8,7,6,5,4,3,2,1};
	testMergeSort(v1);

	std::vector<int> v2 = {5,4,3,2,1};
	testMergeSort(v2);

	std::vector<int> v3 = {1,2,3,4,5,6,7,8,9,10};
	testMergeSort(v3);

	std::vector<int> v4 = {6,5,4,7,8,9,9,5,4,9,2,0,3,1,5,9,8,7,4,5,6,3};
	testMergeSort(v4);

	// test on empty vector
	std::vector<int> v5;
	testMergeSort(v5);

	std::vector<int> v6 = {2,4,-6,1,-9,3,0};
	testMergeSort(v6);

	std::vector<int> v7 = {1,2,3,4,5,6,7,8,9,0};
	testMergeSort(v7);
}


int main(){

	// test merge sort
	testMergeSort();

	return 0;
}

