/*
	This header defines method to reverse a null terminated string.
*/

#ifndef __CTCI_STRING_REVERSE__
#define __CTCI_STRING_REVERSE__



class Reverse_str{

	public:

	/*
		Reverses a null terminated string in place.
		//Time Complexity: O(n)		n - no. of characters in string
	*/	

	static void reverse(char *str);
	

	/* Returns length of null terminated string
	   Time Complexity: O(n)		n - no. of characters in string   */

	static int get_length(char *str);


};

#endif	