#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll r, g, b, n;
	cin >> r >> g >> b >> n;
	ll ans = 0;
	for(ll i = 0; i <= 3000; i++) {
		for(ll j = 0; j <= 3000; j++) {
			ll x = n - r * i - g * j;
			if(x >= 0 && x % b == 0) ans++;
		}
	} cout << ans << "\n";
	return 0;
}
