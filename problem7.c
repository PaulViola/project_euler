//By listing the first six prime numbers : 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//What is the 10 001st prime number ?

//COMPLETE
#include <stdio.h>
#include <stdbool.h>
#define PRIMENUM 10001

bool isPrime(int numToCheck, int primeArr[], int primeArrCount);

int main(void) {
	int count = 1;
	int primeArr[PRIMENUM];
	primeArr[0] = 2;
	int number = 3;

	while (count < PRIMENUM) {
		if (isPrime(number, primeArr, count)) {
			primeArr[count] = number;
			count++;
		}
		number+=2;
	}

	printf("The 10,001st prime number is %i\n", primeArr[count-1]);
	return 0;
}


bool isPrime(int numToCheck, int primeArr[], int primeArrCount) {
	for (int i = 0; i < primeArrCount; i++) {
		if (numToCheck % primeArr[i] == 0) {
			return false;
			break;
		}
	}
	return true;
}