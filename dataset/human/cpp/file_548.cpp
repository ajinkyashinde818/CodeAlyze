#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
int a[3], n;
int64 dp[5005];

int main() {
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &n);

	dp[0] = 1;
	for(int i = 0; i < 3; i++) {
		for(int k = 1; k <= n; k++) {
			if(k >= a[i])
				dp[k] += dp[k - a[i]];
		}
	}

	printf("%lld\n", dp[n]);
	return 0;
}
