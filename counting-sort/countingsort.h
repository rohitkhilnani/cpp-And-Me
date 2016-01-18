/*
	This header defines counting sort on std::vector of int
*/

#ifndef __COUNTING_SORT__
#define __COUNTING_SORT__

#include<vector>
#include<unordered_map>

class CountingSort{

public:

	// Sorts vector A using counting sort
	// Run time: O(n + k)
	// n - size of the vector
	// k - upper bound on the values contained in vector A.

	static void sort(std::vector<int> &A, int k);

};



#endif	