/*
	This program test Binary Search Tree (Bst) class
*/

#include<iostream>
#include<vector>
#include "bst.h"	

// Tests Insertion

void testInsert(){

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


int main(){

	// call testInsert
	testInsert();

	return 0;
}	