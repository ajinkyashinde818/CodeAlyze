#include <stdio.h>
#include <stdlib.h>

#define INF 1000000001

int main() {
	int n, x, k;
	long long ans;

	scanf("%d", &n);
	x = INF;
	ans = k = 0;
	while (n--) {
		int a;

		scanf("%d", &a);
		if (a <= 0)
			k++;
		a = abs(a);
		ans += a;
		if (x > a)
			x = a;
	}
	printf("%lld\n", k % 2 == 0 ? ans : ans - x * 2);
	return 0;
}
