#include <stdio.h>
#include <inttypes.h>

int main(void) {
	uint64_t R, G, B, N;
	uint64_t i, j;
	uint64_t kotae = 0;
	if (scanf("%" SCNu64 "%" SCNu64 "%" SCNu64 "%" SCNu64, &R, &G, &B, &N) != 4) return 1;
	for (i = 0; R * i <= N; i++) {
		for (j = 0; R * i + G * j <= N; j++) {
			if ((N - (R * i + G * j)) % B == 0) kotae++;
		}
	}
	printf("%" PRIu64 "\n", kotae);
	return 0;
}
