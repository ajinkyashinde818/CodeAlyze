#include <stdio.h>
#include <inttypes.h>

int main(void) {
	uint64_t A, B, C, D;
	uint64_t AB, CD;
	if (scanf("%" SCNu64 "%" SCNu64 "%" SCNu64 "%" SCNu64, &A, &B, &C, &D) != 4) return 1;
	AB = A * B;
	CD = C * D;
	printf("%" PRIu64 "\n", AB >= CD ? AB : CD);
	return 0;
}
