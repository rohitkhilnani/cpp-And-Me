/*
	Definition for maxheap.h
*/

#include "maxheap.h"

	// Constructs empty heap

		Maxheap::Maxheap(){

		}	


		// Constructs empty heap with reserved capacity as specified

		Maxheap::Maxheap(int cap){
			heap.reserve(cap);
		}


		// Constructs heap with input vector.
		// Note, does not check for valid heap.

		Maxheap::Maxheap(std::vector<int> v){
					
			heap = v;
			heapSize = v.size();
		}


		// Prints heap (valid heap and beyond)

		void Maxheap::print_heap(){
			
			for(auto x: heap){
				std::cout<<x<<" ";
			}

			std::cout<<std::endl;
		}


	

		// Returns left child of index i
		// Time Complexity: O(1)

		int Maxheap::left(int i){

			return 2*(i+1) - 1;
		}


		// Returns right child of index i
		// Time Complexity: O(1)

		int Maxheap::right(int i){

			return 2*(i+1);
		}


		// Pushes down element at index i to its appropriate position in the heap.
		// Assumes left and right children of index i are valid heaps
		// Time Complexity: O(log(n))	n - heapSize

		void Maxheap::max_heapify(int i){


			// return if index i is invalid
			if(i>=heapSize || i < 0){

				std::cout<<"Error - cannot heapify index "<<i<<" when heap size is: "<<heapSize<<std::endl;
				return;
			}

			//Find element at which index is larger among i and its two children
			
			// Let i be larger
			int larger = i;

			// left child
			int l = left(i);

			// right child
			int r = right(i);


			// if left child of i exists
			if(l < heapSize){

				// if left child is larger, set it as larger
				if(heap[l] > heap[larger])
					larger = l;				


				// if right child exists
				if(r < heapSize){

					// if right child is even larger, set it as larger
					if(heap[r] > heap[larger])
						larger = r;
				}


			}


			// if any child is larger than i itself

			if(larger!=i){

				// exchange i and larger

				int t = heap[i];
				heap[i] = heap[larger];
				heap[larger] = t;

				// heapify index larger
				max_heapify(larger);
			}	

		}


	// Makes the entire vector 'heap' a valid max-heap
	// Changes heap size to be size of heap
	// Time Complexity: O(n) 	n - heapSize	


	void Maxheap::make_max_heap(){

		// dont do anything is heap size is 0
		if(heap.empty())
			return;

		// Set heap size
		heapSize = heap.size();

		// heapfify all elements at indices (n-1)/2 to 0
		for(int i = (heapSize-2)/2;i>=0;i--){
			max_heapify(i);
		}


	}

	// Removes max element from heap and puts it in the end of heap, effectively reducing heapSize by 1		
	// Time Complexity: O(log(n))	n - heapSize

	void Maxheap::extract_max(){

		// dont do anything if heapsize is zero	
		if(heapSize == 0)
			return;

		// swap last element and index 0
		int t = heap[0];
		heap[0] = heap[heapSize-1];
		heap[heapSize-1] = t;

		// reduce heapsize by 1
		heapSize--;

		// max-heapify index 0
		max_heapify(0);

	}

	// Sorts entire heap (from index 0 up to heapSize-1)
	// Time Complexity: O(n*log(n))		n - heapSize

	void Maxheap::sort_heap(){

		// Dont do anything if heap size = 0
		if(heapSize == 0)
			return;

		// extract max (heapSize-1) times
		int n = heapSize;
		for(int i=0;i<n-1;i++){
			extract_max();
		}

	}	


	// Returns parent of index i
	// Time Complexity: O(1)

	int Maxheap::parent(int i){
		return (i-1)/2;
	}


	// Increases key value at index i to newKey
	// requires newKey is greater than current key, else returns
	// Time Complexity: O(log(n))	n - heapSize

	void Maxheap::increase_key(int i, int newKey){

		// return if i is invalid
		if(i >= heapSize)
			return;

		if(newKey <= heap[i]){
			std::cout<<"New key must be greater than current key\n";
			return;
		}

		heap[i] = newKey;

		// while value at i is greater than value at its parent
		// and i is not root
		while(i>0 && heap[i] > heap[parent(i)]){

			// exchange value at i and its parent

			int t = heap[i];
			heap[i] = heap[parent(i)];
			heap[parent(i)] = t;

			// set i = parent
			i = parent(i);
		}
				
	}

	// Inserts new key in heap
	// Requires entire heap be a valid heap, otherwise cannot insert
	// Time Complexity: O(log(n))	n - heapSize

	void Maxheap::insertKey(int key){

		if(heapSize < heap.size()){

			std::cout<<"Entire heap must be valid heap. Call make_max_heap before calling insert";
			return;
		}

		// add new key with least negative value at end of heap	
		heap.push_back(std::numeric_limits<int>::min());

		// increase heap size by 1
		heapSize++;

		// increase key of last element to newKey

		increase_key(heapSize-1,key);

	}

	// Deletes element at index i
	// Time Complexity: O(log(n) + d)		n - heapSize,  d = heap.size (elements in vector) - heapSize (elements that form valid heap)
	// Note: complexity is increased due to shifting the remaining elements of vector (if any)
	// If entire heap is valid heap i.e. heapSize = heap.size, then complexity is: O(log(n))

	void Maxheap::deleteKey(int i){

		// return if i is not valid index
		if(i >= heapSize || i < 0)
			return;

		// if there is only one element in heap
		if(heapSize == 1){

			// reduce heap size by 1
			heapSize--;

			// delete position 0
			heap.erase(heap.begin());				

		}
		else { //   otherwise

			
			// if last key in heap is larger than key at i	
			if(heap[heapSize-1] > heap[i]){

				// save last key
				int lastKey = heap[heapSize-1];

				// delete last heap index
				heap.erase(heap.begin() + heapSize - 1);	 

				// reduce size of heap
				heapSize--;

				// increase key at index i to lastkey
				increase_key(i, lastKey);
			}

			else {  // otherwise, 

				// copy lastkey to index i
				heap[i] = heap[heapSize-1];

				// delete last key
				heap.erase(heap.begin() + heapSize-1);

				// reduce heap size
				heapSize--;

				// max_heapify index i
				max_heapify(i);		

			}

		}


	}


