#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);
	int h[100000];
	int count = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &h[i]);
		if (h[i] >= K) {
			count++;
		}
	}

	printf("%d", count);



	return 0;
}
