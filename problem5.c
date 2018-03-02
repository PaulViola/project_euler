//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?

//COMPLETE
#include <stdio.h>
#include <stdbool.h>
#define UPPERNUM 20

bool isEvenlyDivisible(int numToCheck);

int main(void) {
	int finalNum = 1;
	while (!isEvenlyDivisible(finalNum)) {
		finalNum++;
	}

	printf("Number divisible by all numbers from 1-20 is: %i\n",finalNum);
	return 0;
}

bool isEvenlyDivisible(int numToCheck) {
	for (int i = UPPERNUM; i >= 2; i--) {
		if (numToCheck % i != 0)
			return false;
	}
	return true;
}