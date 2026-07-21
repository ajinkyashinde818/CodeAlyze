#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define GYOU_MAX 256


int main(void) {

	int K, S;
	scanf("%d%d", &K, &S);

	int count = 0;
	int z;
	for (int i = 0;; i++) {
		if (i > S||i > K) {
			break;
		}
		for (int j = 0;; j++) {
			if (i + j > S||j > K) {
				break;
			}
			z = S - i - j;
			if (z >= 0 && z <= K) {
				//printf("%d %d %d\n", i, j, z);
				count++;
			}
		}
	}
	printf("%d\n", count);

	return 0;
}
