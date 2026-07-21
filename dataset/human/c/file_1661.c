#include <stdio.h>

int N, A[22], B[22], C[22];

int main()
{
	scanf ("%d", &N);
	for (int i = 1; i <= N; i++) scanf ("%d", &A[i]);
	for (int i = 1; i <= N; i++) scanf ("%d", &B[i]);
	for (int i = 1; i < N; i++) scanf ("%d", &C[i]);

	int a = 0;
	for (int i = 1, L = N + 2; i <= N; i++){
		a += B[A[i]];
		if (L + 1 == A[i]) a += C[L];
		L = A[i];
	}
	printf ("%d\n", a);
	return 0;
}
