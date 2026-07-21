// C - Splitting Pile

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll a[200000];
ll cum_a[200000];

int main() {
	int N;
	cin >> N;

	ll tot = 0;
	for (int i=0; i<N; i++) {
		cin >> a[i];
		tot += a[i];
	}

	cum_a[0] = a[0];
	for (int i=1; i<N; i++) {
		cum_a[i] = cum_a[i-1] + a[i];
	}

	ll ans = INF;
	for (int i=0; i<N-1; i++) {
		ans = min(ans, abs(cum_a[i] - (tot - cum_a[i])));
	}

	cout << ans << endl;

	return 0;
}
