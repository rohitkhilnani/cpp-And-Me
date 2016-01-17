/*
	This program tests Quick sort
*/

#include<iostream>
#include<vector>
#include "quicksort.h"	// My implementation of Quick sort

// Displays vector

void printVector(std::vector<int> A){
	for(auto x: A){
		std::cout<<x<<" ";

	}
	std::cout<<std::endl;	
}


// Tests Quick sort on vector A

void testQuickSort(std::vector<int> A){

	std::cout<<"Before: ";
	printVector(A);
	Quicksort::quicksort(A);
	std::cout<<"After: ";
	printVector(A);
}


// tests Quick sort on several different inputs

void testQuickSort(){

	std::vector<int> v1 = {10,9,8,7,6,5,4,3,2,1};
	testQuickSort(v1);

	std::vector<int> v2 = {5,4,3,2,1};
	testQuickSort(v2);

	std::vector<int> v3 = {1,2,3,4,5,6,7,8,9,10};
	testQuickSort(v3);

	std::vector<int> v4 = {6,5,4,7,8,9,9,5,4,9,2,0,3,1,5,9,8,7,4,5,6,3};
	testQuickSort(v4);

	// test on empty vector
	std::vector<int> v5;
	testQuickSort(v5);

	std::vector<int> v6 = {2,4,-6,1,-9,3,0};
	testQuickSort(v6);

	std::vector<int> v7 = {1,2,3,4,5,6,7,8,9,0};
	testQuickSort(v7);
}


int main(){

	// test Quick sort
	testQuickSort();

	return 0;
}

