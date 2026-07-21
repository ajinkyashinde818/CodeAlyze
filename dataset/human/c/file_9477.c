#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#define MIN(a, b) ((a < b ? a : b))

int main(void) {
	uint32_t preparedNumChoco;
	uint32_t N, D, X;
	uint32_t A[100];

	scanf("%"PRIu32"\n%"PRIu32" %"PRIu32"\n", &N, &D, &X);
	preparedNumChoco = X;
	for (uint32_t idx = 0; idx < N - 1; idx++) {
		scanf("%"PRIu32"\n", &(A[idx]));
		preparedNumChoco += (D - 1) / A[idx] + 1;
	}
	scanf("%"PRIu32, &(A[N - 1]));
	preparedNumChoco += (D - 1) / A[N - 1] + 1;

	printf("%"PRIu32, preparedNumChoco);

	return 0;
}
