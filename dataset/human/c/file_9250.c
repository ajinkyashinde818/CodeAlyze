#include <stdio.h>

int main()
{
	int N,K,h[100000];
	int count = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N-1; i++) {
		scanf("%d", &h[i]);
		if (h[i] >= K) {
			count++;
		}
	}
	printf("%d", count);
}
