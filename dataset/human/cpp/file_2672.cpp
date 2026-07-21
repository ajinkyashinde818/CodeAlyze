#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lf;

ll N, A[100005], dp[100005][2];

ll solve(ll n, bool t) {
	if (dp[n][t] != -1) return dp[n][t];
	if (n == N-1) {
		if (t) return -A[n];
		else return A[n];
	}
	ll s = 0;
	if (t) {
		s = max(solve(n+1, true) + A[n], solve(n+1, false) - A[n]);
	}
	else {
		s = max(solve(n+1, true) - A[n], solve(n+1, false) + A[n]);
	}
	return dp[n][t] = s;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> A[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, false) << "\n";
	
}
