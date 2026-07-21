#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	const ll MOD = 1e9 + 7;
	int N;
	cin >> N;
	string s;
	cin >> s;

	map<char, ll> mp;
	for (int i = 0; i < N; ++i) {
		mp[s[i]] += 1;
	}

	ll res = 1;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		res = (res * (it->second + 1)) % MOD;
	}

	cout << (res - 1 + MOD) % MOD << endl;

	return 0;
}
