// The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?


//COMPLETE
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define TARGETNUM 600851475143

int largestFactor(bool* boolArr, int maxLimit);

int main() {
	int maxLimit = (int) sqrt(TARGETNUM);

	bool* boolArr = malloc(maxLimit * sizeof *boolArr);

	for (int i = 0; i < maxLimit + 1; boolArr[i++] = true);

	for (int i = 2; i < maxLimit + 1; i++)
	{
		if (boolArr[i] == true)
		{
			for (int j = i + i; j < maxLimit + 1; j += i)
			{
				boolArr[j] = false;
			}
		}
		if (boolArr[i] == true && TARGETNUM % i != 0)
		{
			boolArr[i] = false;
		}
	}
	int factor = largestFactor(boolArr, maxLimit);
	printf("The largest prime factor of the number 600851475143 is %i\n", factor);
	memset(boolArr, 0, maxLimit * sizeof *boolArr);
	return 0;
}

int largestFactor(bool* boolArr, int maxLimit)
{
	for (int i = maxLimit; i >= 2; i--)
	{
		if (boolArr[i] == true)
			return i;
	}
	return -1;
}
