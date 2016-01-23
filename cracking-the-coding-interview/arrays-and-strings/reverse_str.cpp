/*
	Definition for reverse_str.h
*/



#include "reverse_str.h"

/*
	Reverses a null terminated string in place.
	//Time Complexity: O(n)		n - no. of characters in string
*/	

	 void Reverse_str::reverse(char *str){

		// Dont do anything if str is null
		if(str == nullptr)
			return;

		// find length
		int len = get_length(str);

		// from index 0 to floor(len/2)-1
		for(int i=0;i<(len/2);i++){

			// swap index i and len-i-1
			char temp = str[i];
			str[i] = str[len-i-1];
			str[len-i-1] = temp;
		}

	}
	

	/* Returns length of null terminated string
	   Time Complexity: O(n)		n - no. of characters in string   */

	 int Reverse_str::get_length(char *str){

		// return 0 if str is null
		if(str == nullptr)
			return 0;

		// obtain pointer to start of string	
		char* p = str;

		// let length be 0
		int len = 0;

		// repeat while p is not null (and therefore is a valid character)
		while(*p!='\0'){

			// increment length
			len++;

			// move p ahead
			p++;
		}

		// return length
		return len;


	}		