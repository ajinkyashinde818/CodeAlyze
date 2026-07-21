#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 55;
const int mod = (int) 1e9 + 9;
const int base = 3;

int n, m;
string a[MAXN], b[MAXN];
ll p[MAXN];
ll ha[MAXN][MAXN];
ll hb[MAXN];

void init() {
	p[0] = 1;
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] * base % mod;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ha[i][j + 1] = (ha[i][j] + (a[i][j] == '#' ? 1 : 2) * p[j]) % mod;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			(hb[i] += ((b[i][j] == '#' ? 1 : 2) * p[j]) % mod) %= mod;
		}
	}
}

bool check(int x, int y) {
	for (int i = 0; i < m; i++) {
		ll cur_hash = (ha[x + i][y + m] - ha[x + i][y] + mod) % mod;
		ll pattern_hash = hb[i] * p[y] % mod;
		if (cur_hash != pattern_hash)
			return 0;
	}
	return 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	init();
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (check(i, j)) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
