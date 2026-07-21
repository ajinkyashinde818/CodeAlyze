#include <stdio.h>
#include <string.h>

int main()
{
	int N, M, X;
	int C[12];
	int A[12][12];
	scanf("%d%d%d", &N, &M, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &C[i]);
		for (int t = 0; t < M; t++) {
			scanf("%d", &A[i][t]);
		}
	}

	const int INF = 1 << 30;
	int ans = INF;
	for (int bit = 0; bit < (1 << N); bit++) {
		int skill[12] = {0};
		int cost = 0;
		for (int i = 0; i < N; i++) {
			int use = (bit & (1 << i));
			if (use) {
				cost += C[i];
				for (int t = 0; t < M; t++) {
					skill[t] += A[i][t];
				}
			}
		}
		bool ok = true;
		for (int t = 0; t < M; t++) {
			if (skill[t] < X) {
				ok = false;
			}
		}
		if (ok) {
			ans = (cost < ans) ? cost: ans;
		}
	}

	if (ans == INF) {
		puts("-1");
	}
	else {
		printf("%d\n", ans);
	}

	return 0;
}
