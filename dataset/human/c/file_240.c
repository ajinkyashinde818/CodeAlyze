#include <stdio.h>
 
int main() {
	int n, i;
	long long *A, sum = 0, cnt = 0, min = 1000000000;

	scanf("%d", &n);
	A = (long long*)calloc(n, sizeof(long long));
	for (i = 0; i < n; i++) {
		scanf("%lld", &A[i]);
	}

	for (i = 0; i < n; i++) {
		if (A[i] < 0) {
			cnt++;
			A[i] = (-A[i]);
		}
		if (min > A[i]) min = A[i];
		sum += A[i];
	}

	if (cnt % 2 == 1)
		sum -= (min * 2);

	printf("%lld", sum);
 
	return 0;
}
