#include <stdio.h>

int main(void)
{
	int i, N, K, h[100000], count = 0;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++) {
		scanf("%d", &h[i]);
		if (K <= h[i]) {
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
