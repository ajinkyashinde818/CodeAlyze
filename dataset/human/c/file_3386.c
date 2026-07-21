#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

static size_t A[100000];

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

static char S[100001];

int main(void) {
	gets(S);

	const char sList[][8] = { "dream","dreamer","erase","eraser" };

	while (0 < strlen(S)) {
		const size_t len = strlen(S);
		bool matched = false;
		for (size_t listIdx = 0; listIdx < sizeof(sList) / sizeof(sList[0]); listIdx++) {
			const size_t cLen = strlen(sList[listIdx]);

			if (cLen <= len) {
				if (strcmp(&S[len - cLen], sList[listIdx]) == 0) {
					S[len - cLen] = '\0';
					matched = true;
					break;
				}
			}
		}

		if (!matched) {
			break;
		}
	}

	puts((0 < strlen(S) ? "NO" : "YES"));

	return 0;
}
