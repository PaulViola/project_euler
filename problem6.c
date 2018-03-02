//The sum of the squares of the first ten natural numbers is,
//1^2 + 2^2 + ... + 10^2 = 385

//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)2 = 552^2 = 3025

//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

//COMPLETE
#include <stdio.h>
#define UPPPERNUM 100


int square(int numToSquare);
int sumSquares(int upperNum);
int squareSum(int upperNum);

int main(void) {
	int sumOfSquares = sumSquares(UPPPERNUM);
	int squareOfSum = squareSum(UPPPERNUM);
	int difference = squareOfSum - sumOfSquares;
	printf("The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is: %i\n", difference);
	return 0;
}

int square(int numToSquare) {
	return numToSquare * numToSquare;
}

int sumSquares(int upperNum) {
	int accumulator = 0;
	for (int i = 1; i <= upperNum; i++) {
		accumulator += square(i);
	}
	return accumulator;
}

int squareSum(int upperNum) {
	int accumulator = 0;
	for (int i = 1; i <= upperNum; i++) {
		accumulator += i;
	}
	return square(accumulator);
}