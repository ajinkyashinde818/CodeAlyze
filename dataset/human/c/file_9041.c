#include<stdio.h>
int main(void) {
	int n, k;
	int c = 0;
	int tall[100000];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tall[i]);
		if (tall[i] >= k) {
			c = c + 1;
		}
	}
	printf("%d", c);
	return 0;
}
