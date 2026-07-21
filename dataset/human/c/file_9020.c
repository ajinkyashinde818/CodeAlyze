#include<stdio.h>
int main() {
	int n;
	int k;
	int h[100000];
	int count = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
		if (h[i] >= k) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
