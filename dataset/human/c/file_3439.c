#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	long long int K;
	static int A[200000];
	scanf("%d%lld", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		A[i]--;
	}

	// next[k][i]: 2^k
	const int LOG = 62;
	static int next[LOG][200000];
	for (int i = 0; i < N; i++) {
		next[0][i] = A[i];
	}
	for (int k = 1; k < LOG; k++) {
		for (int i = 0; i < N; i++) {
			next[k][i] = next[k - 1][next[k - 1][i]];
		}
	}

	int ans = 0;
	for (int k = LOG - 1; k >= 0; k--) {
		int use = (K & (1LL << k)) != 0;
		if (use) {
			ans = next[k][ans];
		}
	}
	printf("%d\n", ans + 1);

	return 0;
}
