#include "myers.h"


bool isArgumentValid(int argc, char *argv[], int *a, int *b, int *c) {

	if (argc < 4) {
		return false;
	}

	*a = atoi(argv[1]);
	*b = atoi(argv[2]);
	*c = atoi(argv[3]);

	if (*a <= 0 || *b <= 0 || *c <= 0) {
		return false;
	}

	return true;

}


bool isTriangle(int a, int b, int c) {
	return (a + b > c) && (b + c > a) && (c + a > b);
}


TriangleType getTriangleType(int a, int b, int c) {

	if (a == b && b == c) {
		return Equilateral;
	}

	if (a == b || b == c || c == a) {
		return Isosceles;
	}

	return Other;

}
 
