#include<stdio.h>
int main(void) {
	int N, D, X,ans=0;
	int a;

	scanf("%d", &N);
	int A[100];
	scanf("%d %d", &D, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j*A[i] + 1 <= D; j++) {
			ans++;
		}
	}
	printf("%d", ans + X);
	return 0;
}
