#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	ll N;
	cin >> N;
	vector<ll> a(N), s(N+1);
	s[0] = a[0];
	for (ll i = 0; i < N; i++) {
		cin >> a[i];
		s[i+1] = s[i] + a[i];
	}

	ll mi=1e18;
	for (ll i = 1; i < N; i++) {
		ll x = s[i];
		ll y = s[N]-s[i];
		//cout << x <<" "<< y <<" "<< abs(x-y) << endl;
		mi = min(mi, abs(x-y));
	}

	cout << mi << endl;
}
