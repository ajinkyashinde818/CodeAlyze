#include <stdio.h>

int alg (int x, int y) {
	if (x % y == 0) {
		return y;
	}
	else {
		alg(y, x % y);
	}
}
int main(void) {
	int a, b, k, memo;
	int ans[100];
	scanf("%d %d %d", &a, &b, &k);
	if (a < b) {
		memo = b;
		b = a;
		a = memo;
	}

	ans[0]=alg(a, b);
	int n = 0;
	for (int i = ans[0]-1; i  ; --i) {
		if (a % i == 0 && b % i == 0) {
			ans[++n] = i;
		}
	}
	printf("%d", ans[k - 1]);

	return 0;
}
