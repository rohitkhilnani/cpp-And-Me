# Max Heap (Binary)

Class maxheap implements binary max heap of integers

Methods/ Operations implemented: 

	protected:
	
		int left(int i) - Returns left child of index i

		int right(int i) - Returns right child of index i

		int parent(int i) - Returns parent of index i

		void max_heapify(int i) - Pushes down element at index i to its appropriate position in the heap.


	public:

		Maxheap() - Constructs empty heap

		Maxheap(int cap) - Constructs empty heap with reserved capacity as specified

		Maxheap(std::vector<int> v) - Constructs heap with input vector.

		void print_heap() - Prints heap (valid heap and beyond)

		void make_max_heap() - Makes the entire vector 'heap' a valid max-heap

		void extract_max() - Removes max element from heap and puts it in the end of heap, effectively reducing heapSize by 1		

		void sort_heap() - Sorts entire heap (from index 0 up to heapSize-1)

		void increase_key(int i, int newKey)- Increases key value at index i to newKey

		void insertKey(int key) - Inserts new key in heap

		void deleteKey(int i) - Deletes element at index i