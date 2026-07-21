#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

int add (int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul (ll a, ll b) {
	a *= b;
	if (a >= mod) a %= mod;
	return a;
}

vector <int> cnt(26);
int ans;

void rec (int in, int res) {
	if (in == 26) {
		ans = add(ans, res);
		return;
	}
	rec (in+1, res);
	rec (in+1, mul(res, cnt[in]));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for (int i=0; i<n; i++) {
		cnt[s[i]-'a'] ++;
	}
	rec (0, 1);
	ans --;
	if (ans < 0) ans += mod;
	cout << ans;
	return 0;
}
