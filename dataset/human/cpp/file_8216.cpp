#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = (ll)1e15;
int N;
vector<ll> S;

int main(void) {
	cin >> N;

	S.resize(N + 1);
	S[0] = 0LL;
	for (int i = 1; i <= N; ++i) {
		ll a;
		cin >> a;
		S[i] = S[i - 1] + a;
	}

	ll ans = INF;
	for (int i = 1; i <= N - 1; ++i) {
		ll x = S[i];
		ll y = S[N] - x;
		ans = min(ans, abs(x - y));
	}

	cout << ans << '\n';
	return 0;
}
