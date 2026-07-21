#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int compare_f(const void *a, const void *b) {
	return *((int64_t *)a) < *((int64_t *)b) ? -1 : 1;
}

int compare_f2(const void *a, const void *b) {
	return *((uint64_t *)a) > *((uint64_t *)b) ? -1 : 1;
}

static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	for (size_t i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

static uint64_t combU64(const uint64_t n, const uint64_t r) {
	uint64_t result = 1;

	for (uint64_t i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

static uint64_t gcd(uint64_t m, uint64_t n)
{
	uint64_t temp;

	while (m%n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}

	return n;
}

static char S[100001];

static bool cExist['z' - 'a' + 1];

static void initCExist(void) {
	for (size_t i = 0; i < (size_t)('z' - 'a' + 1); i++) {
		cExist[i] = false;
	}
}

#define MOD_VAL (UINT64_C(1000000007))

static uint64_t aa(uint64_t a) {
	uint64_t result = 1;

	while (1 < a) {
		result = result * a % MOD_VAL;

		a--;
	}

	return result;
}

int main(void) {
	size_t N;

	scanf("%zu\n%s", &N, S);

	uint64_t count['z' - 'a' + 1];
	for (size_t i = 0; i < (uint64_t)('z' - 'a' + 1); i++) {
		count[i] = 0;
	}

	for (size_t i = 0; i < N; i++) {
		count[S[i] - 'a']++;
	}

	uint64_t result = 1;

	for (size_t i = 0; i < (uint64_t)('z' - 'a' + 1); i++) {
		result = result * (count[i] + 1) % MOD_VAL;
	}

	printf("%"PRIu64, result - 1);

	return 0;
}
