#ifndef MYERS_H
#define MYERS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 三角形形状 */
typedef enum tagTriangleType {
	/* 正三角形 */
	Equilateral,
	/* 二等辺三角形 */
	Isosceles,
	/* 不等辺三角形 */
	Other
} TriangleType;

bool isArgumentValid(int argc, char *argv[], int *a, int *b, int *c);
bool isTriangle(int a, int b, int c);
TriangleType getTriangleType(int a, int b, int c);

#endif

