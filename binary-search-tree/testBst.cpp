/*
	This program test Binary Search Tree (Bst) class
*/

#include<iostream>
#include<vector>
#include "bst.h"	

// Tests Insertion

void testInsert(){

	std::cout<<"Testing Insertion:\n";

	// define values

	std::vector<int> values = {10,7,5,3,9,8,11,17,19,14};

	// create bst

	Bst bst;

	// insert values

	for(int i=0;i<values.size();i++)
		bst.insert(values[i]);

	// print inorder traversal
	std::cout<<"In order: ";
	bst.inOrder();

	// print preorder traversal
	std::cout<<"Pre order: ";
	bst.preOrder();

	// print postorder traversal
	std::cout<<"Post order: ";
	bst.postOrder();

	// print level order traversal
	std::cout<<"Level order: ";
	bst.levelOrder();

}


// Tests Deletion
	void testDelete(){

	std::cout<<"Testing Deletion:\n";	

	// define values

	std::vector<int> values = {50,30,70,10,40,60,90,5,15,35,55,95,100,51};

	// create bst

	Bst bst;

	// insert values

	for(int i=0;i<values.size();i++)
		bst.insert(values[i]);

	// print inorder and level order traversals
	std::cout<<"In Order: ";
	bst.inOrder();
	std::cout<<"Level Order: ";
	bst.levelOrder();

	// delete key with two child subtrees
	std::cout<<"Delete 50\n";
	bst.deleteKey(50);

	// print inorder and level order traversals
	std::cout<<"In Order: ";
	bst.inOrder();
	std::cout<<"Level Order: ";
	bst.levelOrder();

	//delete key with only left subtree
	std::cout<<"Delete 60\n";
	bst.deleteKey(60);

	// print inorder and level order traversals
	std::cout<<"In Order: ";
	bst.inOrder();
	std::cout<<"Level Order: ";
	bst.levelOrder();

	//delete key with only right subtree
	std::cout<<"Delete 90\n";
	bst.deleteKey(90);

	// print inorder and level order traversals
	std::cout<<"In Order: ";
	bst.inOrder();
	std::cout<<"Level Order: ";
	bst.levelOrder();	

	// delete key with no child subtree
	std::cout<<"Delete 5\n";
	bst.deleteKey(5);

	// print inorder and level order traversals
	std::cout<<"In Order: ";
	bst.inOrder();
	std::cout<<"Level Order: ";
	bst.levelOrder();


	}

// tests find

	void testFind(){

		std::cout<<"Testing Find:\n";	

		// define values

		std::vector<int> values = {50,30,70,10,40,60,90,5,15,35,55,95,100,51};

		// create bst

		Bst bst;

		// search in empty tree
		std::cout<<"19 exists?: ";
		if(bst.find(19)!=nullptr)
			std::cout<<"Yes\n";
		else
			std::cout<<"No\n";


		// insert values

		for(int i=0;i<values.size();i++)
			bst.insert(values[i]);

		
		values.push_back(5000);
		values.push_back(-50);
		values.push_back(32);
		values.push_back(96);

		for(int i=0;i<values.size();i++){

			std::cout<<values[i]<<" exists?: ";
		if(bst.find(values[i])!=nullptr)
			std::cout<<"Yes\n";
		else
			std::cout<<"No\n";


		}

	}	

int main(){

	// call testInsert
	testInsert();

	// call testDelete
	testDelete();

	// call testFind
	testFind();

	return 0;
}	