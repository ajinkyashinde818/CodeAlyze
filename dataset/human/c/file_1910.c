#include<stdio.h>
#include<string.h>

int main() {
	
	int N, A[20], B[20], C[20];
	int ans = 0;
	int ago_a = 0;
	int Ci = 0;

	scanf("%d", &N);
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
		ans += B[A[i] - 1];
		if (ago_a + 1 == A[i] && ago_a - 1 >= 0) {
			Ci = ago_a - 1;
			ans += C[Ci];
		}
		ago_a = A[i];
		
	}

	printf("%d", ans);

	return 0;
}
