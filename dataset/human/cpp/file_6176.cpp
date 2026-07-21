#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

ll x[MAXN], v[MAXN], pref[MAXN], pref_max[MAXN], suf[MAXN], suf_max[MAXN];

ll n, C, res = 0;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> C;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> v[i];
	x[0] = 0, x[n + 1] = C;
	for (int i = 1; i <= n; i++)
	{
		pref[i] = pref[i - 1] + v[i] - (x[i] - x[i - 1]);
		pref_max[i] = max(pref[i], pref_max[i - 1]);
	}
	for (int i = n; i >= 1; i--)
	{
		suf[i] = suf[i + 1] + v[i] - 2 * (x[i + 1] - x[i]);
		suf_max[i] = max(suf[i], suf_max[i + 1]);
	}
	for (int i = 0; i <= n; i++)
		res = max(res, pref_max[i] + suf_max[i + 1]);
	for (int i = 1; i <= n; i++)
	{
		pref[i] = pref[i - 1] + v[i] - 2 * (x[i] - x[i - 1]);
		pref_max[i] = max(pref[i], pref_max[i - 1]);	
	}
	for (int i = n; i >= 1; i--)
	{
		suf[i] = suf[i + 1] + v[i] - (x[i + 1] - x[i]);
		suf_max[i] = max(suf[i], suf_max[i + 1]);	
	}
	for (int i = 0; i <= n; i++)
		res = max(res, pref_max[i] + suf_max[i + 1]);
	cout << res << endl;
	return 0;	
}
