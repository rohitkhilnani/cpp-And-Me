/*
	Definition for bst.h

*/

#include "bst.h"

	// Inserts new node with specified value at sub-tree rooted at n. 
	// Returns root.
	// Time Complexity: 
	//		Worst Case: O(N) 			N - no. of nodes in tree
	//		Average Case: O(log(N)) 
	// Space Complexity: O(N)	

	Node* Bst::insert(Node* n, int value){

		// If n is null, allocate new node 
		if(n == nullptr){
			n = new Node(value);
		}

		else if(value < n->getValue()){  		// If value less than value at n

			// Insert in  left subtree of n
			n->setLeft(insert(n->getLeft(), value));
		}

		else{ // otherwise, insert in right subtree of n

			n->setRight(insert(n->getRight(), value));

		}

		// return n
		return n;	

	}


	// Visits Node in in order fashion
	// Time Complexity: O(N) 
	// Space Complexity: O(N)		


	void Bst::inOrderVisit(Node *n){

		// Return if n is null

		if(n==nullptr){
			return;
		}

		// Otherwise, visit left subtree
		inOrderVisit(n->getLeft());

		// print value at n
		std::cout<<n->getValue()<<" ";

		// visit right subtree
		inOrderVisit(n->getRight());


	}


	// Visits Node in pre order fashion
	// Time Complexity: O(N) 
	// Space Complexity: O(N)		


	void Bst::preOrderVisit(Node *n){

		// Return if n is null

		if(n==nullptr){
			return;
		}

		// print value at n
		std::cout<<n->getValue()<<" ";	

		// Otherwise, visit left subtree
		preOrderVisit(n->getLeft());

		
		// visit right subtree
		preOrderVisit(n->getRight());


	}


	// Visits Node in post order fashion
	// Time Complexity: O(N) 
	// Space Complexity: O(N)		

	void Bst::postOrderVisit(Node *n){

		// Return if n is null

		if(n==nullptr){
			return;
		}

		
		// Otherwise, visit left subtree
		postOrderVisit(n->getLeft());
		
		// visit right subtree
		postOrderVisit(n->getRight());

		// print value at n
		std::cout<<n->getValue()<<" ";	


	}


	// Inserts new node with specified value in the tree

	void Bst::insert(int value){

		root = insert(root, value);	
	}		


	// In order traversal of tree

	void Bst::inOrder(){

		inOrderVisit(root);
		std::cout<<std::endl;
	}


	// Pre order traversal of tree

	void Bst::preOrder(){

		preOrderVisit(root);
		std::cout<<std::endl;
	}


	// Post order traversal of tree

	void Bst::postOrder(){

		postOrderVisit(root);
		std::cout<<std::endl;
	}


	// Level order traversal of tree
	// Time Complexity: O(N) 
	// Space Complexity: O(N)		


	void Bst::levelOrder(){

		// Return if root is null
		if(root == nullptr)
			return;

		// define queue
		std::queue<Node*> que;

		// enqueue root
		que.push(root);

		//while que is non empty
		while(!que.empty()){

			// remove node (reference) from queue
			Node *u = que.front();
			que.pop();

			// print u
			std::cout<<u->getValue()<<" ";

			// enqueue left and right children of u, if they are not null
			if(u->getLeft()!=nullptr)
				que.push(u->getLeft());

			if(u->getRight()!=nullptr)
				que.push(u->getRight());

		}

		std::cout<<std::endl;


	}

	// Deallocates tree rooted at n
	// Time Complexity: O(N) 
	// Space Complexity: O(N)		

	void Bst::deallocate(Node *n){

		// return if n is null
		if(n==nullptr)
			return;
		else{	
			// otherwise, deallocate left subtree
			deallocate(n->getLeft());

			// deallocate right subtree
			deallocate(n->getRight());

			// delete n
			delete n;	

		}

	}

	Bst::~Bst(){

			// deallocate tree rooted at root
			deallocate(root);
		}


	// Deletes key k from tree rooted at n
	// Returns n (root of the subtree)
	// Time Complexity: 
	//		Worst Case: O(N) 			N - no. of nodes in tree
	//		Average Case: O(log(N)) 
	// Space Complexity: O(N)	

	Node* Bst::deleteKey(Node* n, int key){

		// if n is null, dont do anything
		if(n == nullptr);
			//do nothing
		else	
		// if key is smaller than value at n
		if(key < n->getValue()){

			// delete in left subtree of n

			n->setLeft(deleteKey(n->getLeft(), key));
		}

		// if key is greater than value of n
		else if (key > n->getValue()){

			// delete in right subtree of n
			n->setRight(deleteKey(n->getRight(), key));
		}
		
		else{  // if n is the node to be deleted (key matches value at n)

			// if left subtree of n is null
			if(n->getLeft() == nullptr){

				// if right subtree is also null
				if(n->getRight() == nullptr){

					// delete n and set it as null
					delete n;
					n = nullptr;
				}

				else {  // if right subtree is not null

					// delete n and point n to right subtree

					Node* temp = n->getRight();
					delete n;
					n = temp;

				}

			}	

			// if right subtree is null and left subtree is not null
			else if(n->getRight() == nullptr) {   

				// delete n and point it to left subtree

				Node* temp = n->getLeft();
				delete n;
				n = temp;

			}

			else {  // if both subtrees are not null

				// find inorder successor

				Node* succ = findSucc(n);

				// copy contents from succ to n
				n->setValue(succ->getValue());

				//delete succ in right subtree

				n->setRight(deleteKey(n->getRight(), succ->getValue()));	

			}


		}

		// return n
		return n;
		
	}

	// Returns pointer to inorder successor of node n if exists

	Node* Bst::findSucc(Node *n){

		if(n==nullptr || n->getRight()==nullptr)
			return nullptr;
		else{

			// move right once
			n = n->getRight();

			// move left till possible

			while(n->getLeft()!=nullptr)
				n = n->getLeft();

		}

		return n;
		
		
	}

	// Deletes key k from tree 

	void Bst::deleteKey(int key){

		root = deleteKey(root, key);
	}

	// Finds specified key in tree rooted at specified node n and returns pointer to its node
	// Otherwise, returns nullptr
	// Time Complexity: 
	//		Worst Case: O(N) 			N - no. of nodes in tree
	//		Average Case: O(log(N)) 
	// Space Complexity: O(N)	(May improve if tail recursion is optimized)

	Node* Bst::find(Node* n, int key){

		// Return null if tree is empty
		if(n == nullptr)
			return nullptr;

		//if key is same as value at n, return n
		if(key == n->getValue())
			return n;
		else if(key < n->getValue()) 				// if key is smaller than value at n
			return find(n->getLeft(), key); 		// find in left subtree of n
		else return find(n->getRight(), key); 		// else find in right subtree of n
	}

	// Finds key in tree and returns pointer to its node if it exists.
	// Otherwise returns null

	Node* Bst::find(int key){

		return find(root, key);
	}