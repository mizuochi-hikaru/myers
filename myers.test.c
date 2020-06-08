#include "myers.h"


/* boolの戻り値からメッセージ出力 */
void testBoolean(bool result, const char truemsg[], const char falsemsg[]) {
	if (result) {
		puts(truemsg);
	} else {
		puts(falsemsg);
	}
}


/* isArgumentValidのテスト */
void test_isArgumentValid() {

	int a, b, c;

	puts("1. 引数の個数が不正");
	puts("1-1. 引数が足りない");
	testBoolean(isArgumentValid(3, NULL, &a, &b, &c), "NG", "OK");
	puts("1-2. 引数が多い");
	testBoolean(isArgumentValid(5, NULL, &a, &b, &c), "NG", "OK");

	puts("2. 引数で渡された値が不正");
	puts("2-1-1. aが空文字列");
	char *testarg211[] = {
		"test",
		"",
		"1",
		"1"
	};
	testBoolean(isArgumentValid(sizeof(testarg211) / sizeof(char *), testarg211, &a, &b, &c), "NG", "OK");
	puts("2-1-2. aが負の値");
	char *testarg212[] = {
		"test",
		"-1",
		"1",
		"1"
	};
	testBoolean(isArgumentValid(sizeof(testarg212) / sizeof(char *), testarg212, &a, &b, &c), "NG", "OK");

	/* 割愛 */

	puts("3. 正常");
	char *testarg3[] = {
		"test",
		"1",
		"1",
		"1"
	};
	testBoolean(isArgumentValid(sizeof(testarg3) / sizeof(char *), testarg3, &a, &b, &c), "OK", "NG");

}


/* isTriangleのテスト */
void test_isTriangle() {

	puts("1-1. a + b < c");
	testBoolean(isTriangle(1, 1, 3), "NG", "OK");
	puts("1-2. a + b = c");
	testBoolean(isTriangle(1, 1, 2), "NG", "OK");

	puts("2-1. b + c < a");
	testBoolean(isTriangle(5, 2, 2), "NG", "OK");
	puts("2-2. b + c = a");
	testBoolean(isTriangle(4, 2, 2), "NG", "OK");

	puts("3-1. c + a < b");
	testBoolean(isTriangle(3, 7, 3), "NG", "OK");
	puts("3-2. c + a = b");
	testBoolean(isTriangle(3, 6, 3), "NG", "OK");

	puts("4. OK");
	testBoolean(isTriangle(3, 4, 5), "OK", "NG");

}


/* TriangleTypeの戻り値からメッセージ出力 */
void testTriangleType(TriangleType result, TriangleType expected, const char truemsg[], const char falsemsg[]) {
	testBoolean(result == expected, truemsg, falsemsg);
}


/* getTriangleTypeのテスト */
void test_getTriangleType() {

	puts("1. 正三角形");
	testTriangleType(getTriangleType(1, 1, 1), Equilateral, "OK", "NG");

	puts("2. 正三角形");
	puts("2-1. A = B");
	testTriangleType(getTriangleType(2, 2, 1), Isosceles, "OK", "NG");
	puts("2-2. B = C");
	testTriangleType(getTriangleType(1, 2, 2), Isosceles, "OK", "NG");
	puts("2-3. C = A");
	testTriangleType(getTriangleType(2, 1, 2), Isosceles, "OK", "NG");

	puts("3. 不等辺三角形");
	testTriangleType(getTriangleType(3, 4, 5), Other, "OK", "NG");

}


int main(int argc, char *argv[]) {

	puts("*** isArgumentValidのテスト ***");
	test_isArgumentValid();

	puts("*** isTriangleのテスト ***");
	test_isTriangle();

	puts("*** getTriangleTypeのテスト ***");
	test_getTriangleType();

}
