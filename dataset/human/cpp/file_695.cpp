#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;

ll a, b, c, n, ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> a >> b >> c >> n;
	for (ll i = 0; i * a <= n; i++)
		for (ll j = 0; i * a + j * b <= n; j++)
			ans += ((n - i * a - j * b) % c == 0);
	cout << ans;
	return 0;
}
