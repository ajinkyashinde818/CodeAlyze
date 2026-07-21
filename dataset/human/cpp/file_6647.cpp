#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 10;

int a[maxn];

int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n << 1; ++i) 
		a[i] = !i ? (s[i] == 'B') : (s[i] != s[i - 1]);

	int L = 0;
	long long ans = 1;
	for (int i = 0; i < n << 1; ++i) 
		if (a[i]) {
			L++;
		} else {
			if (!L) {
				puts("0");
				return 0;
			}
			ans = ans * L % MOD;
			L--; a[i + 1] ^= 1;
		}
	if (L > 0) ans = 0;
	for (int i = 1; i <= n; ++i) ans = ans * i % MOD;
	cout << ans << "\n";
	return 0;
}
