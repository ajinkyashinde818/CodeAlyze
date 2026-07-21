#include <stdio.h>
int main() {
	int i;
	int N, K;
	int h[100000];
	int cnt = 0;

	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%d", &h[i]);
		if (h[i] >= K) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
