#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int compare_f(const void *a, const void *b) {
	return *((size_t *)a) > *((size_t *)b) ? -1 : 1;
}

static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	for (size_t i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

static size_t countDivisors(const size_t n)
{
	size_t count = 1;

	for (size_t i = 2; i <= n; i++) {
		if (n%i == 0) {
			count++;
		}
	}

	return count;
}

int main(void) {
	size_t N, i;

	scanf("%zu %zu", &N, &i);

	printf("%zu\n", N - i + 1);

	return 0;
}
