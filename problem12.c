//What is the value of the first triangle number to have over five hundred divisors?


//Incomplete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define TARGETNUMDIVISORS 5

unsigned long long int currentTriangleNumberCount = 1;
unsigned long long int currentTriangleNumberValue = 0;

int findDivisorCount(unsigned long long int currentTriangleVal);

int main(){

    int numberOfDivisors = 0;

    while(numberOfDivisors < TARGETNUMDIVISORS)
    {
        currentTriangleNumberValue += currentTriangleNumberCount;
        numberOfDivisors = findDivisorCount(currentTriangleNumberValue);
        currentTriangleNumberCount++;
    };
    printf("The value of the first triangle number to have over five hundred divisors is %llu\n", currentTriangleNumberValue);
    return 0;
}

int findDivisorCount(unsigned long long int currentTriangleNumberValue)
{
    int count =0;
    int maxLimit = currentTriangleNumberValue;

	bool* boolArr = (bool*) malloc(maxLimit * sizeof *boolArr);

    memset(boolArr, 0, maxLimit * sizeof *boolArr);

    return count;
}