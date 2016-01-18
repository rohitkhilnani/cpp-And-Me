/*
	This class defines a binary max heap
*/

#ifndef __HEAP_MAX_HEAP__
#define __HEAP_MAX_HEAP__

#include<vector>
#include<iostream>
#include<limits>

class Maxheap{

	private:

		int heapSize = 0;		// Identifies the number of elements (starting from index 0) which are valid heap
		std::vector<int> heap;	// vector to hold the elements of heap 


	protected:
	
		// Returns left child of index i
		// Time Complexity: O(1)

		int left(int i);


		// Returns right child of index i
		// Time Complexity: O(1)

		int right(int i);


		// Returns parent of index i
		// Time Complexity: O(1)
		int parent(int i);


		// Pushes down element at index i to its appropriate position in the heap.
		// Assumes left and right children of index i are valid heaps
		// Time Complexity: O(log(n))	n - heapSize

		void max_heapify(int i);


	public:
	
		// Constructs empty heap

		Maxheap();	


		// Constructs empty heap with reserved capacity as specified

		Maxheap(int cap);


		// Constructs heap with input vector.
		// Note, does not check for valid heap.

		Maxheap(std::vector<int> v);


		// Prints heap (valid heap and beyond)

		void print_heap();

	
		// Makes the entire vector 'heap' a valid max-heap
		// Changes heap size to be size of heap
		// Time Complexity: O(n) 	n - heapSize	

		void make_max_heap();


		// Removes max element from heap and puts it in the end of heap, effectively reducing heapSize by 1		
		// Time Complexity: O(log(n))	n - heapSize

		void extract_max();


		// Sorts entire heap (from index 0 up to heapSize-1)
		// Time Complexity: O(n*log(n))		n - heapSize

		void sort_heap();


		// Increases key value at index i to newKey
		// requires newKey is greater than current key, else returns
		// Time Complexity: O(log(n))	n - heapSize

		void increase_key(int i, int newKey);


		// Inserts new key in heap
		// Requires entire heap be a valid heap, otherwise cannot insert
		// Time Complexity: O(log(n))	n - heapSize

		void insertKey(int key);


		// Deletes element at index i
		// Time Complexity: O(log(n) + d)		n - heapSize,  d = heap.size (elements in vector) - heapSize (elements that form valid heap)
		// Note: complexity is increased due to shifting the remaining elements of vector (if any)
		// If entire heap is valid heap i.e. heapSize = heap.size, then complexity is: O(log(n))

		void deleteKey(int i);

};

#endif	











