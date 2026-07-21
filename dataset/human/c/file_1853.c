#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void) {
	int N;
	scanf("%d", &N);
	int A[20];
	int B[20];
	int C[20];
	int sum = 0;
	int a = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &C[i]);
	}
	for (int i = 0; i < N; i++) {
		if (A[i]+1 == A[i+1]) {
			a = A[i];
			sum += C[a-1];
		}

		sum += B[i];
	}



	printf("%d", sum);




	return 0;

}
