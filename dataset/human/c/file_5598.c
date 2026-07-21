#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <map>
#include <math.h>
#pragma warning(disable : 4996)

int main(void) {
	long long x;
	scanf("%lld", &x);
	long long op = (long long)(x / 11 + 0.5)*2;
	if (x % 11 != 0) {
		if (x % 11 > 6) {
			op += 2;
		} else{
			op += 1;
		}
	}
	printf("%lld", op);
	return 0;
}
