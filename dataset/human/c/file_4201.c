#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define X (1000000007)

int main() {
	int A[100000] = { 0 };
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);
		A[tmp] = -1;
	}
	A[0] = 1;
	if (A[1] != -1)A[1] = 1;
	else A[1] = 0;
	int i = 2;
	while (i <= N) {
		if (A[i] == -1) {
			A[i] = 0;
			i++;
			if (A[i] == -1) {
				printf("0");
				return 0;
			}
			A[i] = A[i - 2];
			A[i] %= X;
			i++;
			continue;
		}
		else {
			A[i] += A[i - 2];
			A[i] += A[i - 1];
			A[i] %= X;
			i++;
		}
	}
	printf("%d", A[N]);

	return 0;

}
