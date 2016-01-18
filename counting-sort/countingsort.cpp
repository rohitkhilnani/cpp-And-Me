/*
	Definition for countingsort.h
*/


#include "countingsort.h"	

	// Sorts vector A using counting sort
	// Run time: O(n + k)
	// n - size of the vector
	// k - upper bound on the values contained in vector A.

	 void CountingSort::sort(std::vector<int> &A, int k){

		// if A is empty, return
		if(A.empty())
			return;

		std::unordered_map<int, int> count;

		// reserve memory for k key-value pairs
		count.reserve(k);

		// initialize counts to zero for 0..k
		for(int i=0; i<=k;i++)
			count[i] = 0;

		// count number of occurences of keys in A
		for(int i=0;i<A.size();i++)
			if(count.find(A[i])==count.end())
				count[A[i]] = 1;
			else
				count[A[i]]++;

		
		// convert counts to number of elements less or equal to a key
		for(int i=1;i<=k;i++)
			count[i] += count[i-1];

		
		// define auxiliary array to hold result
		int result[A.size()];

		// put keys in their correct position according to counts staring from last key in A
		for(int i=A.size()-1;i>=0;i--){

			result[ count[A[i]]-1 ] = A[i];

			// reduce count of A[i] by 1
			count[A[i]]--;	
		}			

		
		// copy result to actual vector
		for(int i=0;i<A.size();i++)
			A[i] = result[i];

	}
