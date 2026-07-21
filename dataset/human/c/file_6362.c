#include <stdio.h>
#define N 200000
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int i, j, n, R[N];

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &R[i]);
	}

	int maxv = -1000000000;
	int minv = R[0];
 	
	for(i = 1; i < n; i++) {
		maxv = max(maxv, R[i] - minv);
		minv = min(minv, R[i]);
	}
	printf("%d\n", maxv);

	return 0;
}
