//A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3 - digit numbers.

//COMPLETE
#include <stdio.h>
#include <cstring>
#include <stdbool.h>
#define MAXARRSIZE 7

void intToCharArray(int numToCheck, char intAsCharArr[]);
bool isPalindrome(char* strNumToCheck);
int largestPalindrome(char intAsCharArr[]);

int main(void) {
	int numToCheck = 0;
	char intAsCharArr[MAXARRSIZE];
	int maxPal= largestPalindrome(intAsCharArr);

	printf("The largest palindrome made from the product of two 3 - digit numbers is %i\n", maxPal);
	return 0;
}

void intToCharArray(int numToCheck, char intAsCharArr[]) {

	snprintf(intAsCharArr, MAXARRSIZE, "%i", numToCheck);
}

bool isPalindrome(char* strNumToCheck) {
	int end = strlen(strNumToCheck) - 1;
	int halfWay = strlen(strNumToCheck) / 2;
	for (int i = 0; i < halfWay; i++) {
		if (strNumToCheck[i] != strNumToCheck[end - i])
			return false;
	}
	return true;
}

int largestPalindrome(char intAsCharArr[]) {
	int maxPal = 0;
	for (int i = 999; i >= 100; i--) {
		for (int j = i; j >= 100; j--) {
			int numToCheck = i * j;
			intToCharArray(numToCheck, intAsCharArr);
			if (isPalindrome(intAsCharArr)) {
				if (maxPal == 0)
					maxPal = numToCheck;
				else {
					if (numToCheck > maxPal)
						maxPal = numToCheck;
				}
			}
		}
	}
	return maxPal;
}