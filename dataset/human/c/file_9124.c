#include<stdio.h>

int main(voud) {
	int cnt = 0, N, K, h[100000];
	scanf("%d %d", &N, &K);

	for(int i = 0; i < N; ++i) {
		scanf("%d", &h[i]);
		if(h[i] >= K) {
			++cnt;
		}
	}
	printf("%d\n", cnt);
}
