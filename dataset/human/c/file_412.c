#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
int main(void) {
	int n, r;
	scanf("%d%d", &n, &r);
	if (n >= 10) {
		printf("%d", r);
	}
	else {
		printf("%d", r + (100 * (10 - n)));
	}
	return 0;
}
