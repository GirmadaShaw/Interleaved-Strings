/*
Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B.
C is said to be interleaving A and B, if it contains all and only characters of A and B and 
order of all characters in individual strings is preserved. 

Input: strings: "XXXXZY", "XXY", "XXZ"
Output: XXXXZY is interleaved of XXY and XXZ
The string XXXXZY can be made by 
interleaving XXY and XXZ
String:    XXXXZY
String 1:    XX Y
String 2:  XX  Z

Input: strings: "XXY", "YX", "X"
Output: XXY is not interleaved of YX and X
XXY cannot be formed by interleaving YX and X.
The strings that can be formed are YXX and XYX

*/
#include <iostream>
#include <string.h>
using namespace std;


bool isInterleaved(string A, string B, string C)
{
	// Base Case: If all strings are empty
	if (A.empty() && B.empty() && C.empty()) {
		return true;
	}

	// If C is empty and any of the two strings is not empty
	if (C.empty()) {
		return false;
	}

	// If any of the above mentioned two possibilities is true,
	// then return true, otherwise false
	return ((C[0] == A[0]) && isInterleaved(A.substr(1), B, C.substr(1)))
			|| ((C[0] == B[0]) && isInterleaved(A, B.substr(1), C.substr(1)));
}


int main()
{
    std :: cout << isInterleaved("XXXXZY", "XXY", "XXZ") ;
}