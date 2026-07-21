#include <stdio.h>

int main(void) {
	int N, D, X;
	int A[100];
	int count = 0;
	scanf("%d%d%d", &N, &D, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < D; j++) {
			if (D>= j * A[i] + 1) {

				count++;

			}
		}
	}



	printf("%d\n", count + X);



	return 0;

}
