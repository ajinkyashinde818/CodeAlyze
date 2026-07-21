#include <stdio.h>
#include <inttypes.h>

uint64_t gcd(uint64_t a, uint64_t b) {
	while (b > 0) {
		uint64_t r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {
	uint64_t A, B;
	if (scanf("%" SCNu64 "%" SCNu64, &A, &B) != 2) return 1;
	printf("%" PRIu64 "\n", A / gcd(A, B) * B);
	return 0;
}
