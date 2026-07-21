#include <stdio.h>

int main(void) {

	int N,i,K,P;
	int a[100];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {

		scanf("%d%d", &K, &P);

		if (K < P) a[i] = K;
		else if (K%P != 0) a[i] = K%P;
		else if (K%P == 0) a[i] = P;
	}
	for (i = 0; i < N; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
