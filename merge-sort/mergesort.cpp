/*
	Definition for mergesort.h
*/

#include "mergesort.h"

// Sorts vector A between indices p and r, inclusive
void Mergesort::mergesort(std::vector<int> &A, int p, int r){

	// if there are two or more elements to be sorted
	if(p<r){

		// find middle index	
		int q = (p+r)/2;

		// sort left half
		mergesort(A, p, q);

		// sort right half
		mergesort(A, q+1, r);

		// merge the two halves
		merge(A, p, q, r);

	}		


}


// Merges sorted range p..q and (q+1)..r into single sorted range p..r in A

void Mergesort::merge(std::vector<int> &A, int p, int q, int r){

	// find lengths of left and right halves
	int lenLeft = q - p + 1;
	int lenRight = r - q;

	// define auxiliary arrays Left (L) and Right (R)
	int L[lenLeft +1];
	int R[lenRight +1];

	// copy left and right halves into auxiliary arrays
	int k = 0;
	for(int i=p;i<=q;i++)
		L[k++] = A[i];

	k = 0;
	for(int i=q+1;i<=r;i++)
		R[k++] = A[i];

	// set last element of auxiliary arrays as maximum int value
	L[lenLeft] = R[lenRight] = std::numeric_limits<int>::max();

	// merge sorted sections into the original vector range p..r
	int li = 0, ri = 0;   // Left and Right half index

	for(int i=p;i<=r;i++){

		if(L[li] <= R[ri])
			A[i] = L[li++];
		else
			A[i] = R[ri++];
	}

}


//Sorts vector A using mergesort
// Time Complexity: O(n*log(n))
// Space Complexity: O(n)
// Stable

void Mergesort::mergesort(std::vector<int> &A){

	// Call overloaded mergesort
	mergesort(A, 0, A.size()-1);
}
