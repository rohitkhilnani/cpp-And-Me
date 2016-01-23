/*
	This programtests class reverse_str
*/

#include "reverse_str.h"
#include<iostream>

void test_single(char* s){

	// avoid printing nullpointer
	if(s!=nullptr)
		std::cout<<"\nString: "<<s;
	else
		std::cout<<"\nnull";
	
	std::cout<<"\nLength: "<<Reverse_str::get_length(s);
	
	Reverse_str::reverse(s);
	
	// avoid printing nullpointer
	if(s!=nullptr)
		std::cout<<"\nReversed: "<<s;
	else
		std::cout<<"\nnull";

	std::cout<<"\n";
}

void test_all(){

	// null pointer
	char* s1 = nullptr;
	test_single(s1);

	// length 0
	char s2[] = "";
	test_single(s2);

	// length 1
	char s3[] = "r";
	test_single(s3);

	// length 2
	char s4[] = "rk";
	test_single(s4);

	//length 3
	char s5[] = "xyz";
	test_single(s5);

	// length 10
	char s6[] = "what's up!";
	test_single(s6);

	// length 17
	char s7[] = "let's do some c++";
	test_single(s7);

	std::cout<<"\n\n";
}





int main(){

	// test all
	test_all();

	return 0;
}	