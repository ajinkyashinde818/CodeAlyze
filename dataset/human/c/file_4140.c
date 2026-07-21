#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define GYOU_MAX 256

int main(void) {

	int A, B, K;
	scanf("%d%d%d", &A, &B, &K);

	int count = 0;
	int X[100];
	for (int i = 1;i<=100; i++) {
		if (A%i == 0 && B%i == 0) {
			X[count] = i;
			count++;
		}
	}

	printf("%d\n", X[count - K]);

	return 0;
}
