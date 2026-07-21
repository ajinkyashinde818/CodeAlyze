#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <map>
#pragma warning(disable : 4996)



int main(void) {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d", (a*b > c *d) ? a*b : c*d);
	return 0;
}
