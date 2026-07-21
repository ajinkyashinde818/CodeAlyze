#include <stdio.h>

int main(void) {
	int N, D, X, A[100];
	scanf("%d%d%d", &N, &D, &X);
	for (int i = 0;i < N;i++) {
		scanf("%d", &A[i]);
	}

	int day[100], eat[100];
	for (int i = 0;i < N;i++) {
		day[i] = 1;
		eat[i] = 0;
	}

	for (int i = 1;i <= D;i++) {
		for (int j = 0;j < N;j++) {
			if (day[j] == i) {
				eat[j]++;
				day[j] += A[j];
			}
		}
	}

	int eat_all = X;
	for (int i = 0;i < N;i++) {
		eat_all += eat[i];
	}

	printf("%d\n", eat_all);

	return 0;
}
