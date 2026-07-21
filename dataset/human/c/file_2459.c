#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int main(void) {
	char S[4];
	uint8_t count[3] = {0, 0, 0};

	scanf("%s", S);

	for (size_t idx = 0; idx < 3; idx++) {
		count[S[idx] - 'a']++;
	}

	printf("%s", count[0] * count[1] * count[2] != 0 ? "Yes" : "No");

	return 0;
}
