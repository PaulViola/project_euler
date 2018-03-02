//A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3 - digit numbers.

#include <stdio.h>
#include <stdbool.h>


//Need to convert int into array of chars for comparisons in palindrome check
char * intToCharArray(int number);
bool isPalindrome(char* strNumToCheck);

int main(void) {
	int numToCheck = 9009;
	//char* asCharArr = intToCharArray(numToCheck);
	if (isPalindrome(asCharArr))
		printf("It is a palindrome");

	free(asCharArr);
	return 0;
}


bool isPalindrome(char* strNumToCheck) {
	int end = strlen(strNumToCheck)-1;
	int halfWay = end / 2;
	for (int i = 0; i < halfWay; i++) {
		if (strNumToCheck[i] != strNumToCheck[end - i])
			return false;
	}
	return true;
}