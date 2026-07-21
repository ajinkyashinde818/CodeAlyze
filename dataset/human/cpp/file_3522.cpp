#include<bits/stdc++.h>

using namespace std;
const int nn = 2e5 + 5;
long long dp[nn][3], n, arr[nn];

long long rek(int idx, int bef) {
	if (idx == n) return 0;
	if (dp[idx][bef] == -1) {
		if (bef == 0) {
			if (idx == n - 1) dp[idx][bef] = rek(idx + 1, 0) + arr[idx];
			else dp[idx][bef] = max(rek(idx + 1, 0) + arr[idx], 
							   rek(idx + 1, 1) - arr[idx]);
		} else {
			if (idx == n - 1) dp[idx][bef] = rek(idx + 1, 0) - arr[idx];
			else dp[idx][bef] = max(rek(idx + 1, 0) - arr[idx], 
							   rek(idx + 1, 1) + arr[idx]);
		}
	}
	return dp[idx][bef];
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", & n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", & arr[i]);
	}	
	long long ans = rek(0, 0);
	printf("%lld\n", ans);
}
