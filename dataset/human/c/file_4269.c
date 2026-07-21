#include <stdio.h>
int main() {
	int n,m,i,j,t=0,a[100000];
	long long int ans[2] = { 0, 1 };
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) scanf("%d", &a[i]);
	for (i = 0; i < n; i++) {
		ans[i % 2] = (ans[0] + ans[1]) % 1000000007;
		for (j = t; j < m; j++) if (i == a[j] - 1) {
			ans[i % 2] = 0;
			t = j;
			break;
		}
	}
	printf("%lld", ans[(n+1)%2]);
}
