#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N - 1; i++) a[i + 1] += a[i];

	ll ans = abs(a[N - 1] - 2 * a[0]);
	for (int i = 1; i < N - 1; i++) {
		ans = min(ans, abs(a[N - 1] - 2 * a[i]));
	}
	cout << ans << endl;
}
