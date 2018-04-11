//The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
//What is the greatest product of four adjacent numbers in the same direction(up, down, left, right, or diagonally) in the 20×20 grid ?


//COMPLETE
#include <stdio.h>
#define ROWSIZE 20
#define COLSIZE 20
#define READINGFRAME 4;

int numMatrix[20][20] = {
	{8, 02, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
	{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 0},
	{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
	{52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91},
	{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
	{24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
	{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
	{67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21 },
	{24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
	{21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95 },
	{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 4, 62, 16, 14, 9, 53, 56, 92},
	{16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
	{86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
	{19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
	{4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
	{88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
	{4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
	{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
	{20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
	{1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}
};

unsigned long long int checkProduct(unsigned long long int currLarge, unsigned long long int intToCheck);
unsigned long long int largestHorizontalProduct(const int matrix[20][20], unsigned long long int currLargest);
unsigned long long int rowCheck(const int matrix[20][20], int rowIndex, int colIndex);
unsigned long long int largestVerticalProduct(const int matrix[20][20], unsigned long long int currLargest);
unsigned long long int colCheck(const int matrix[20][20], int rowIndex, int colIndex);
unsigned long long int largestDiagonalProduct(const int matrix[20][20], unsigned long long int currLargest);
unsigned long long int diagForwardCheck(const int matrix[20][20],int rowIndex,int colIndex);
unsigned long long int diagBackwardCheck(const int matrix[20][20],int rowIndex,int colIndex);

int main(){

	unsigned long long int largestProduct = 0;
	largestProduct = largestHorizontalProduct(numMatrix, largestProduct);
	largestProduct = largestVerticalProduct(numMatrix, largestProduct);
	largestProduct = largestDiagonalProduct(numMatrix, largestProduct);

	printf("The greatest product of four adjacent numbers in the same direction is %llu\n", largestProduct);
	return 0;
}


unsigned long long int checkProduct(unsigned long long int currLarge, unsigned long long int intToCheck)
{
	return currLarge > intToCheck ? currLarge : intToCheck;
}

unsigned long long int rowCheck(const int matrix[20][20], int rowIndex, int colIndex)
{
	unsigned long long int product = matrix[rowIndex][colIndex];
	int stoppingPoint = colIndex + READINGFRAME;

	for (int i = colIndex+1; i < stoppingPoint; i++) {
		product *= matrix[rowIndex][i];
	}
	return product;
}

unsigned long long int largestHorizontalProduct(const int matrix[20][20], unsigned long long int currLargest)
{
	unsigned long long int largest = currLargest; 
	int rowIndex = 0;
	int colIndex = 0;
	int finalColIndex = COLSIZE - READINGFRAME;

	while(rowIndex < ROWSIZE){
		while(colIndex < finalColIndex)
		{
			largest = checkProduct(largest, rowCheck(matrix, rowIndex, colIndex));
			colIndex++;
		};
		colIndex = 0;
		rowIndex++;
	};
	return largest;
};

unsigned long long int colCheck(const int matrix[20][20], int rowIndex, int colIndex)
{
	unsigned long long int product = matrix[rowIndex][colIndex];
	int stoppingPoint = rowIndex + READINGFRAME;

	for (int i = rowIndex+1; i < stoppingPoint; i++) {
		product *= matrix[i][colIndex];
	}
	return product;
}

unsigned long long int largestVerticalProduct(const int matrix[20][20], unsigned long long int currLargest)
{
	unsigned long long int largest = currLargest; 
	int rowIndex = 0;
	int colIndex = 0;
	int finalRowIndex = ROWSIZE - READINGFRAME;
	while(colIndex < COLSIZE)
	{
		while(rowIndex < finalRowIndex)
		{
			largest = checkProduct(largest, colCheck(matrix, rowIndex, colIndex));
			rowIndex++;
		};
		rowIndex = 0;
		colIndex++;
	};
	return largest;
}

unsigned long long int diagForwardCheck(const int matrix[20][20],int rowIndex,int colIndex)
{
	unsigned long long int product = matrix[rowIndex][colIndex];
	int count =1;
	while(count < 4)
	{
		product *= matrix[rowIndex+count][colIndex+count];
		count++;
	};
	return product;
}

unsigned long long int diagBackwardCheck(const int matrix[20][20],int rowIndex,int colIndex)
{
	unsigned long long int product = matrix[rowIndex][colIndex];
	int count =1;
	while(count < 4)
	{
		product *= matrix[rowIndex+count][colIndex-count];
		count++;
	};
	return product;
}



unsigned long long int largestDiagonalProduct(const int matrix[20][20], unsigned long long int currLargest)
{
	unsigned long long int largest = currLargest; 
	int rowIndex = 0;
	int colIndex = 0;
	int finalRowIndex = ROWSIZE - READINGFRAME;
	int finalColIndex = COLSIZE - READINGFRAME;
	while(rowIndex < finalRowIndex)
	{
		while(colIndex < finalColIndex)
		{
			largest = checkProduct(largest, diagForwardCheck(matrix, rowIndex, colIndex));
			colIndex++;
		}
		colIndex = 0;
		rowIndex++;
	}

	rowIndex = 0;
	colIndex = COLSIZE -1;

	while(rowIndex < finalRowIndex)
	{
		while(colIndex >= 4)
		{
			largest = checkProduct(largest, diagBackwardCheck(matrix, rowIndex, colIndex));
			colIndex--;
		}
		colIndex = COLSIZE -1;
		rowIndex++;
	}

	return largest;
}