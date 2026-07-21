#include <stdio.h>
int M(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int k,n,i;
	scanf("%d %d", &k, &n);
	int l[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &l[i]);
	}
	int m = k - l[n - 1] + l[0];
	for (i = 0; i < n-1; i++) {
		m = M(m, l[i + 1] - l[i]);
	}
	printf("%d", k - m);
	return 0;
}
