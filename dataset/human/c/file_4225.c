#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DIV 1000000007

int main(void){
	long long n, m;
	long long a[200000] = { 0 };
	long long ans = 1;
	long long f[200000] = { 0 };
	int flag = 0;

	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%lld", &a[i]);
		if (i && a[i] == a[i - 1] + 1) flag = 1;
	}
	if (flag)printf("0");
	else {
		f[0] = 1, f[1] = 1;
		for (int i = 2; i <= n; i++)
			f[i] = (f[i - 1] % DIV + f[i - 2] % DIV) % DIV;

		if (m == 0)printf("%lld", f[n]);
		else {
			for (int i = 0; i <= m; i++) {
				if (i == 0)ans = (ans * f[a[i] - 1]) % DIV;
				else if (i == m)ans = (ans * f[n - a[i - 1] - 1]) % DIV;
				else ans = (ans * f[a[i] - a[i - 1] - 2]) % DIV;
			}
			printf("%lld", ans);
		}
	}
	return 0;
}
