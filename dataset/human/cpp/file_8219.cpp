#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000007;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Int N;
	cin >> N;

	vector<Int> a(N);
	for (Int i = 0; i < N; i++) {
		cin >> a[i];
	}

	vector<Int> dp(N + 1);
	dp[0] = 0;

	for (Int i = 0; i < N; i++) {
		dp[i + 1] = dp[i] + a[i];
	}

	Int ans = INF;
	Int su, ar;
	for (Int i = 0; i < N-1; i++) {
		su = dp[i + 1];
		ar = dp[N] - dp[i + 1];
		ans = min(ans, abs(su - ar));
	}
	cout << ans << "\n";
}
