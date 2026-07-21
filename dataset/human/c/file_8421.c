#include<stdio.h>
int main() {
	long long int a, b, c, d, m, n, k, count = 0, result = 0, key, zyou;
	long long int s[2005] = {}, sum[2005] = {}, two[50], num[500600] = {}, memo[500600][50] = {};
	char str[200005];
	two[0] = 1;
	for (int i = 1; i < 50; i++) {
		two[i] = two[i - 1] * 2;
	}
	scanf("%lld%lld", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);

		sum[i] = sum[i - 1] + s[i];

	}
	m = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {

			num[m] = sum[j] - sum[i];

			m++;
		}

	}
	for (int i = 49; 0 <= i; i--) {
		count = 0;
		for (int j = 0; j < m; j++) {
			if ((num[j] / two[i]) % 2 == 1) {
				memo[count][i] = j;
				count++;

			}

		}

		if (count >= k) {
			result += two[i];
			zyou = i;
			key = count;

			goto next;
		}
	}
next:
	for (int i = zyou - 1; 0 <= i; i--) {
		count = 0;
		for (int j = 0; j < key; j++) {

			if ((num[memo[j][zyou]] / two[i]) % 2 == 1) {
				memo[count][i] = memo[j][zyou];
				count++;


			}
			
		}
		if (count >= k) {

			result += two[i];
			zyou = i;
			key = count;

		}
	}
	printf("%lld", result);
}
