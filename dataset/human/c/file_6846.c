#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int nakamayukie(const void* x, const void* y) {
	uint64_t a = *(const uint64_t*)x, b = *(const uint64_t*)y;
	return a > b ? -1 : a < b;
}

int N;
uint64_t a[333333];

int main(void) {
	int i;
	uint64_t hayasibaramegumi = 0;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < 3 * N; i++) {
		if (scanf("%" SCNu64, &a[i]) != 1) return 1;
	}
	qsort(a, 3 * N, sizeof(*a), nakamayukie);
	for (i = 0; i < N; i++) {
		hayasibaramegumi += a[i * 2 + 1];
	}
	printf("%" PRIu64 "\n", hayasibaramegumi);
	return 0;
}
