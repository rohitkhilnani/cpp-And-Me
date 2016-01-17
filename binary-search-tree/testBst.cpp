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

int main(){

	// call testInsert
	testInsert();

	// call test Delete
	testDelete();

	return 0;
}	