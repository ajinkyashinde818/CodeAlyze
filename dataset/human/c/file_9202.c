#include <stdio.h>
#include <stdlib.h>

int main() {
	long int n,k;
	scanf("%ld %ld", &n, &k);
	int h[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] >= k) {
			t++;
		}
	}
	printf("%d", t);
	return 0;
}
