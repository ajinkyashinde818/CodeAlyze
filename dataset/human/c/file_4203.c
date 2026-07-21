#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(void) {
	int n, m, a[(int)1e+5] = {}, ans = 1, ans_1 = 1, ans_2 = 1, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		a[t] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (a[i - 1]) {
			ans = ans_2;
			if (a[i - 2]) {
				ans = 0;
				break;
			}
		}
		else if (a[i - 2]) {
			ans = ans_1;
		}
		else {
			ans = (ans_1 + ans_2) % 1000000007;
		}
		ans_2 = ans_1;
		ans_1 = ans;
	}
	printf("%d\n",ans);
	return 0;
}
