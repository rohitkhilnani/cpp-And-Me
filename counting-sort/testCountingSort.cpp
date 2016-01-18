/*
	This program tests Counting sort
*/

#include<iostream>
#include<vector>
#include "countingsort.h"	// My implementation of Counting sort

// Displays vector

void printVector(std::vector<int> A){
	for(auto x: A){
		std::cout<<x<<" ";

	}
	std::cout<<std::endl;	
}


// Tests Counting sort on vector A

void testCountingSort(std::vector<int> A, int k){

	std::cout<<"Before: ";
	printVector(A);
	CountingSort::sort(A, k);
	std::cout<<"After: ";
	printVector(A);
}


// tests Counting sort on several different inputs

void testCountingSort(){

	std::vector<int> v1 = {10,9,8,7,6,5,4,3,2,1};
	testCountingSort(v1, 10);

	std::vector<int> v2 = {5,4,3,2,1};
	testCountingSort(v2, 5);

	std::vector<int> v3 = {1,2,3,4,5,6,7,8,9,10};
	testCountingSort(v3, 10);

	std::vector<int> v4 = {6,5,4,7,8,9,9,5,4,9,2,0,3,1,5,9,8,7,4,5,6,3};
	testCountingSort(v4, 9);

	// test on empty vector
	std::vector<int> v5;
	testCountingSort(v5, 5);

	std::vector<int> v6 = {100,152,0,64,36,19,43,22,97,33,46,95,73,20};
	testCountingSort(v6, 152);

	std::vector<int> v7 = {1,2,3,4,5,6,7,8,9,0};
	testCountingSort(v7, 9);
}


int main(){

	// test Counting sort
	testCountingSort();

	return 0;
}

