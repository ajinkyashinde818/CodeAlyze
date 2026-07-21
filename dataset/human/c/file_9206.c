#include <stdio.h>

int main()
{
	int i, N, K, h, ans = 0;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d", &h);
		if (h >= K) ans++;
	}
	printf("%d\n", ans);
	fflush(stdout);
	return 0;
}
