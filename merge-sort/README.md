# Merge Sort

Class mergesort implements merge sort on std::vector of int

Methods/ Operations implemented:
	
	
	static void mergesort(std::vector<int> &A, int p, int r); - Sorts vector A between indices p and r, inclusive

	static void merge(std::vector<int> &A, int p, int q, int r) - Merges sorted range p..q and (q+1)..r into single sorted range p..r in A

	static void mergesort(std::vector<int> &A) - Sorts vector A using mergesort
	