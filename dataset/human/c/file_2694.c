#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <map>
#pragma warning(disable : 4996)


int main(void) {
	int k, s;
	scanf("%d %d", &k, &s);
	int sum = 0;
	for (int x = 0; x <= k; ++x) {
		for (int y = 0; y <= k; ++y) {
			if ((s - x - y >= 0) && (s - x - y <= k)) ++sum;
		}
	}
	printf("%d", sum);
	return 0;
}
