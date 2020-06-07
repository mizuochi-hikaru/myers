#include "myers.h"


int main(int argc, char *argv[]) {
	
	int a, b, c;
	
	if (!isArgumentValid(argc, argv, &a, &b, &c)) {
		puts("エラー");
		return -1;
	}

	if (!isTriangle(a, b, c)) {
		puts("三角形不成立");
		return -1;
	}

	switch (getTriangleType(a, b, c)) {
		case Equilateral:
			puts("正三角形");
			break;
		case Isosceles:
			puts("二等辺三角形");
			break;
		default:
			puts("不等辺三角形");
			break;
	}

	return 0;

}

