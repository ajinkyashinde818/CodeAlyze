#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void) {
	int n, b[100001][2] = { 0 }, next = 1,r;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i][0]);
	}
	for (r = 0;; r++) {
		if (next == 2)break;
		b[next][1]++;
		if (b[next][1] > 1) {
			printf("-1\n");
			return 0;
		}
		next = b[next][0];
	}
	printf("%d", r);
}
