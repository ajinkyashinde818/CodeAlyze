#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int A[100000];

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}
	int minusCnt = 0;
	long long sum = 0;
	int min = 1000000000;
	for (int i = 0; i < N; ++i) {
		if (A[i] < 0) {
			++minusCnt;
			A[i] *= -1;
		}
		if (min > A[i]) {
			min = A[i];
		}
		sum += A[i];
	}
	if (minusCnt % 2 == 1) {
		sum -= min * 2;
	}
	printf("%lld", sum);
	return 0;
}
