#include <stdio.h>
#include <stdbool.h>

int main() {
	long long int i, j = 1, n, m, fibo = 1, fi = 1, f = 0, a[100000], sum = 1;
	bool flag = true;

	// 壊れている床の数
	scanf("%lld %lld", &n, &m);

	// 壊れている床の段
	a[0] = -1;
	for (i = 1; i <= m; i++) {
		scanf("%lld", &a[i]);
	}

	// 登れるかチェック
	for (i = 1; i <= m; i++) {
		if (a[i] - a[i - 1] == 1) {
			printf("0\n");
			return 0;
		}
	}

	for (i = 1; i <= n; i++) {
		flag = true;
		for (j = 1; j <= m; j++) {
			if (a[j] == i) {
				a[j] = 0;
				flag = false;
				sum = (sum * fibo) % 1000000007;
				fibo = 1;
				fi = 1;
				f = 0;
				i++;
				break;
			}
		}
		if (flag == true) {
			fibo = (fi + f) % 1000000007;
			f = fi;
			fi = fibo;
		}
	}
	sum = (sum * fibo) % 1000000007;

	printf("%lld\n", sum % 1000000007);

	return 0;
}
