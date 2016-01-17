/*
	This header define merge sort on std::vector of int
*/

#ifndef __MERGE_SORT__
#define __MERGE_SORT__

#include<vector>
#include<limits>

class Mergesort{

	protected:

		// Sorts vector A between indices p and r, inclusive
		static void mergesort(std::vector<int> &A, int p, int r);

		// Merges sorted range p..q and (q+1)..r into single sorted range p..r in A

		static void merge(std::vector<int> &A, int p, int q, int r);



	public:	

		//Sorts vector A using mergesort
		// Time Complexity: O(n*log(n))
		// Space Complexity: O(n)		n - size of vector A
		// Stable

		static void mergesort(std::vector<int> &A);
	


};

#endif 
