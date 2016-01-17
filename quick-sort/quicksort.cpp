/*
	Definition for quicksort.h
*/

// Partitions A between indices p and r (inclusive) about pivot element.
// Pivot is element at index r i.e. A[r]
// All elements on left of pivot are smaller or equal to pivot.
// All elements on right of pivot are larger than pivot
// Returns index of pivot element


#include "quicksort.h"

int Quicksort::partition(std::vector<int> &A, int p, int r){

	// Set pivot as last element in range
	int pivot = A[r];

	// elements upto index i would be less or equal to pivot. Assume there are no such elements
	int i = p - 1;

	// for elements at p through (r-1)
	int j=p;
	
	for(j=p; j<r; j++){

		// If element at j is less or equal to pivot (it should go on left of pivot)
		if(A[j] <= pivot){

			// increment i and swap A[i] with A[j]
			i++;

			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}

	}

	// Swap index r and i+1 so that pivot is in its correct position

	int t = A[r];
	A[r] = A[i+1];
	A[i+1] = t;

	// return pivot index
	return i+1;
}


// Sorts range p..r in A using quick sort

void Quicksort::quicksort(std::vector<int> &A,  int p, int r){

	// If there are two or more elements in range p..r
	if(p<r){

		// Partition A and get pivot index
		int q = partition(A, p, r);

		// Sort Left half 
		quicksort(A, p, q-1);

		// Sort Right half
		quicksort(A, q+1, r); 

	}
}



// Sorts vector A using quicksort
// Time Complexity: 
// 			Average Case: O(n*log(n))     n - size of A
//			Worst Case: O(n*n)
// Space Complexity: O(n)
// Not Stable

void Quicksort::quicksort(std::vector<int> &A){

	// call quicksort on A
	quicksort(A, 0, A.size()-1);

}

