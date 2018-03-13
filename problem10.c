//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//Find the sum of all the primes below two million.


//COMPLETE
#include <stdio.h>
#include <stdbool.h>
#define MAX 2000000

unsigned long long int sumList(bool boolArr[]);

bool boolArr[MAX + 1];

int main() {

	for (int i = 0; i < MAX + 1; boolArr[i++] = true);

	unsigned long long int sum;
	for (int i = 2; i < MAX + 1; i++)
	{
		if (boolArr[i] == true)
		{
			for (int j = i + i; j < MAX + 1; j += i)
			{
				boolArr[j] = false;
			}
		}
	}

	sum = sumList(boolArr);

	printf("The sum of all the primes below two million is %llu\n", sum);
	return 0;
}

unsigned long long int sumList(bool boolArr[])
{
	unsigned long long int sum = 0;
	for (int i = 2; i < MAX + 1; i++)
	{
		if (boolArr[i] == true)
		{
			sum += i;
		}
	}
	return sum;
}