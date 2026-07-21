#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

const int IINF = 2002002002;
const ll LINF = 9009009009009009009LL;

//===

const ll mod = static_cast<int>(1e9 + 7);


int main()
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	
	if (S[0] == 'W' || S[2 * N - 1] == 'W') {
		cout << 0 << endl;
		return 0;
	}

	Vi a(2 * N);
	a[0] = 1;
	for (int i = 1; i < 2 * N; ++i) {
		if (S[i - 1] != S[i]) {
			a[i] = a[i - 1];
		}
		else {
			a[i] = 1 - a[i - 1];
		}
	}

	ll ans = 1;
	ll num0 = 0;
	for (int i = 2 * N - 1; i >= 0; --i) {
		if (a[i] == 0) {
			++num0;
			num0 %= mod;
		}
		else {
			ans *= num0;
			ans %= mod;
			--num0;
		}
	}
	if (num0 != 0) {
		cout << 0 << endl;
	}
	else {
		ll fracN = 1;
		for (ll i = 1; i <= N; ++i) {
			fracN *= i;
			fracN %= mod;
		}

		ans *= fracN;
		ans %= mod;

		cout << ans << endl;
	}

}
