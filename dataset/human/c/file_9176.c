#include<stdio.h>
#include<string.h>


int main() {
	int N;
	int K;
	int h;
	int ans = 0;

	scanf("%d %d", &N, &K);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &h);
		if (h >= K){
			ans = ans + 1;

		}
	}

	printf("%d", ans);

	return 0;
}
