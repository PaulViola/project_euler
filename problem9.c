//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a2 + b2 = c2
//For example, 32 + 42 = 9 + 16 = 25 = 52.
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

//COMPLETE
#include <stdio.h>
#include <stdbool.h>

int productofTriplet();
bool addsToThousand(int a, int b, int c);
bool pythagCheck(int a, int b, int c);

int main() {
	int product = productofTriplet();
	printf("Product of the Pythagorean tiplet for which a + b + c = 1000 is %i\n", product);
	return 0;
}

int productofTriplet() {
	int a, b, c;
	for (int i = 1; i < 1000; i++) {
		a = i;
		for (int j = 1; j < 1000; j++) {
			b = j;
			c = (1000 - (a + b));
			if (addsToThousand(a, b, c) && pythagCheck(a, b, c)) {
				printf("a is %i\n", a);
				printf("b is %i\n", b);
				printf("c is %i\n", c);
				return a * b*(1000 - (a + b));
			}
		}
	}
	return -1;
}

bool addsToThousand(int a, int b, int c) {
	return a + b + c == 1000;
}

bool pythagCheck(int a, int b, int c) {
	return a * a + b * b == c * c;
}

