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

typedef struct {
	size_t idx;
	uint64_t x;
	uint64_t length;
} _xInfo;

int compare_f(const void *a, const void *b) {
	return ((_xInfo *)a)->x < ((_xInfo *)b)->x ? -1 : 1;
}

int compare_f2(const void *a, const void *b) {
	return ((_xInfo *)a)->idx < ((_xInfo *)b)->idx ? -1 : 1;
}

static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	for (size_t i = 0; i < r; i++) {
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

static uint64_t s[100000], t[100000];
static _xInfo xInfo[100000];

int main(void) {
	size_t A, B, Q;

	scanf("%zu %zu %zu\n", &A, &B, &Q);
	for (size_t i = 0; i < A; i++) {
		scanf("%"PRIu64"\n", &s[i]);
	}
	for (size_t i = 0; i < B; i++) {
		scanf("%"PRIu64"\n", &t[i]);
	}
	for (size_t i = 0; i < Q; i++) {
		scanf("%"PRIu64, &xInfo[i].x);
		xInfo[i].idx = i;
		xInfo[i].length = 0;
		if (i < Q - 1) {
			scanf("\n");
		}
	}

	qsort(xInfo, Q, sizeof(_xInfo), compare_f);

	size_t aSeqIdx = 0;
	size_t bSeqIdx = 0;

	for (size_t i = 0; i < Q; i++) {
		while (true) {
			if (aSeqIdx == A - 1) {
				break;
			}
			else if (s[aSeqIdx] <= xInfo[i].x && xInfo[i].x < s[aSeqIdx + 1]) {
				break;
			}
			else if (aSeqIdx == 0 && xInfo[i].x < s[aSeqIdx]) {
				break;
			}

			aSeqIdx++;
		}

		while (true) {
			if (bSeqIdx == B - 1) {
				break;
			}
			else if (t[bSeqIdx] <= xInfo[i].x && xInfo[i].x < t[bSeqIdx + 1]) {
				break;
			}
			else if (bSeqIdx == 0 && xInfo[i].x < t[bSeqIdx]) {
				break;
			}

			bSeqIdx++;
		}

		uint64_t min;

		{
			uint64_t length;

			length = ABSS(xInfo[i].x, s[aSeqIdx]);
			length += ABSS(s[aSeqIdx], t[bSeqIdx]);

			min = length;
		}

		if (bSeqIdx < B - 1){
			uint64_t length;

			length = ABSS(xInfo[i].x, s[aSeqIdx]);
			length += ABSS(s[aSeqIdx], t[bSeqIdx + 1]);

			if (length < min) {
				min = length;
			}
		}

		if (aSeqIdx < A - 1) {
			uint64_t length;

			length = ABSS(xInfo[i].x, s[aSeqIdx + 1]);
			length += ABSS(s[aSeqIdx + 1], t[bSeqIdx]);

			if (length < min) {
				min = length;
			}
		}

		if (aSeqIdx < A - 1 && bSeqIdx < B - 1){
			uint64_t length;

			length = ABSS(xInfo[i].x, s[aSeqIdx + 1]);
			length += ABSS(s[aSeqIdx + 1], t[bSeqIdx + 1]);

			if (length < min) {
				min = length;
			}
		}

		{
			uint64_t length;

			length = ABSS(xInfo[i].x, t[bSeqIdx]);
			length += ABSS(t[bSeqIdx], s[aSeqIdx]);

			if (length < min) {
				min = length;
			}
		}

		if (aSeqIdx < A - 1) {
			uint64_t length;

			length = ABSS(xInfo[i].x, t[bSeqIdx]);
			length += ABSS(t[bSeqIdx], s[aSeqIdx + 1]);

			if (length < min) {
				min = length;
			}
		}

		if (bSeqIdx < B - 1) {
			uint64_t length;

			length = ABSS(xInfo[i].x, t[bSeqIdx + 1]);
			length += ABSS(t[bSeqIdx + 1], s[aSeqIdx]);

			if (length < min) {
				min = length;
			}
		}

		if (aSeqIdx < A - 1 && bSeqIdx < B - 1) {
			uint64_t length;

			length = ABSS(xInfo[i].x, t[bSeqIdx + 1]);
			length += ABSS(t[bSeqIdx + 1], s[aSeqIdx + 1]);

			if (length < min) {
				min = length;
			}
		}

		xInfo[i].length = min;
	}

	qsort(xInfo, Q, sizeof(_xInfo), compare_f2);

	for (size_t idx = 0; idx < Q; idx++) {
		printf("%"PRIu64"\n", xInfo[idx].length);
	}

	return 0;
}
