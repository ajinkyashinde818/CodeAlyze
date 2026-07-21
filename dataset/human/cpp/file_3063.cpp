#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pos;
const ll MOD = 1000000007,N=100010;
ll n, a[N], ans, dp[N][2];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) { dp[i][0] = a[i]; dp[i][1] = -INT_MIN; }
		else {
			dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
			dp[i][1] = max(dp[i - 1][0] - 2 * a[i - 1] - a[i], dp[i - 1][1] + 2 * a[i - 1] - a[i]);
		}
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
	return 0;
}
