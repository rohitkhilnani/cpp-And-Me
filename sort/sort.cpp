/*
	Definition for sort.h
*/

#include "sort.h"

// Sorts vector of int using insertion sort.
// Time Complexity: O(n*n)
// Space Complexity: O(1)
// In place
// Stable	
void insertionSort(std::vector<int> &A){

	// Dont do anything if vector is empty
	if(A.empty())
		return;

	// for element at index 1 through n-1
	for(int i=1; i<A.size(); i++){

		// save value at i in key
		int key = A[i];

		// Shift elements forward if they are greater than key
		
		int j = i-1;
		while(j >= 0 && A[j] > key){

			A[j+1] = A[j];
			j--;
		}

		// Insert key in appropriate position
		A[j+1] = key;

	}

}	

