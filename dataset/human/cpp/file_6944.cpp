#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int n, a[200010], b[200010], c[200010], d[200010];
int cnt1[200010], cnt2[200010];
int ans[200010];

signed main() {
	std::random_device rnd;
	std::mt19937_64 mt(rnd());
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i], c[a[i]] = i, cnt1[a[i]]++;
	for (int i = 1; i <= n; i++)cin >> b[i], d[b[i]] = i, cnt2[b[i]]++;
	for (int i = 1; i <= n; i++)if (n < cnt1[i] + cnt2[i]) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)c[i] = max(c[i - 1], c[i]), d[i] = max(d[i - 1], d[i]);
	int ma = 0;
	for (int i = 1; i <= n; i++)ma = max(ma, c[i] - d[i - 1]);
	for (int i = 0; i < n; i++)ans[(i + ma) % n + 1] = b[i + 1];
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++)cout << ans[i] << " ";
	cout << endl;
}
