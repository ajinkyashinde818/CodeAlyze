#include<stdio.h>
int main() {
	int N, D, X, A[100], i, a = 0, b = 0;
	scanf("%d", &N);
	scanf("%d %d", &D, &X);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < N; i++) {
		if (D%A[i] == 0) {
			a = D / A[i];
			b = b + a;
		}
		else {
			a = D / A[i] + 1;
			b = b + a;
		}
	}
	b = b + X;
	printf("%d", b);
	return 0;
}
