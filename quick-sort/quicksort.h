/*
	This header defines quick sort on std::vector of int
*/

#ifndef __QUICK_SORT__
#define __QUICK_SORT__	

#include<vector>

class Quicksort{

	protected:

		// Partitions A between indices p and r (inclusive) about pivot element.
		// Pivot is element at index r i.e. A[r]
		// All elements on left of pivot are smaller or equal to pivot.
		// All elements on right of pivot are larger than pivot
		// Returns index of pivot element

		static int partition(std::vector<int> &A, int p, int r);


		// Sorts range p..r in A using quick sort

		static void quicksort(std::vector<int> &A,  int p, int r);


	public:
	
		// Sorts vector A using quicksort
		// Time Complexity: 
		// 			Average Case: O(n*log(n))     n - size of A
		//			Worst Case: O(n*n)
		// Space Complexity: O(n)
		// Not Stable
		

		static void quicksort(std::vector<int> &A);




};	

#endif
