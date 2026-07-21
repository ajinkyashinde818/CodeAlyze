#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, N, a[51];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &(a[i]));
	
	int max = -10000000, min = 10000000, argmax, argmin;
	for (i = 1; i <= N; i++) {
		if (a[i] < min) {
			min = a[i];
			argmin = i;
		}
		if (a[i] > max) {
			max = a[i];
			argmax = i;
		}
	}
	
	if (max <= 0) {
		if (min == 0) printf("0\n");
		else {
			printf("%d\n", N);
			printf("%d %d\n", argmin, N);
			for (i = N - 1; i >= 1; i--) printf("%d %d\n", i + 1, i);
		}
	} else if (min >= 0) {
		printf("%d\n", N);
		printf("%d %d\n", argmax, 1);
		for (i = 1; i <= N - 1; i++) printf("%d %d\n", i, i + 1);
	} else if (max >= abs(min)) {
		printf("%d\n", N * 2);
		printf("%d %d\n%d %d\n", argmax, 1, argmax, 1);
		for (i = 1; i <= N - 1; i++) printf("%d %d\n%d %d\n", i, i + 1, i, i + 1);
	} else {
		printf("%d\n", N * 2);
		printf("%d %d\n%d %d\n", argmin, N, argmin, N);
		for (i = N - 1; i >= 1; i--) printf("%d %d\n%d %d\n", i + 1, i, i + 1, i);
	}	
	fflush(stdout);
	return 0;
}
