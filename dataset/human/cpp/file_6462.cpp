/*
─────────▄▄▄▄▄▄▄▄▄▄▄▄─────────
─────▄▄▀▀░░░░░░░░░░░░▀▀▄▄─────
───▄▀░░░░░░░░░░░░░░░░░░░░▀▄───
──█░░░░░▄▄▄▄▄░░░░▄▄▄▄▄░░░░░█──
─█░░░░░██░█░██▄▄██░█░██░░░░░█─
█░░░░░░░▀▀▀▀▀░░░░▀▀▀▀▀░░░░░░░█
█░░░░▄▄▄░░░░░░░░░░░░░░▄▄▄░░░░█
█░░░░██▀█▄▄▄▄▄▄▄▄▄▄▄▄██▀█░░░░█
─█░░░▀██▄████████▄▄▄▄██▄▀░░░█─
──█░░░░▀██▀▀▀▀████████▀░░░░█──
───▀▄░░░░▀▄▄▄▄██████▀░░░░▄▀───
─────▀▀▄▄░░░░░░░░░░░░▄▄▀▀─────
─────────▀▀▀▀▀▀▀▀▀▀▀▀─────────
*/
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int mul(int a, int b) {
	return int(1ll * a * b % mod);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		a[i] = (s[i] == 'B');
	}
	int ans = 1, cnt = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if ((cnt & 1) != a[i]) {
			++cnt;
		}
		else {
			ans = mul(ans, cnt--);

		}
	}
	if (cnt != 0) {
		ans = 0;
	}
	for (int i = 1; i <= n; ++i) {
		ans = mul(ans, i);
	}
	cout << ans;

	return 0;
}
