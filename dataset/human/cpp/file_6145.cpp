#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

nagai calc(int n, nagai c, vector<nagai> x, vector<nagai> v)
{
	vector<nagai> pref(n + 1);
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + v[i];
	vector<nagai> back(n);
	for (int i = 0; i < n; ++i)
		back[i] = pref.back() - pref[i] - (c- x[i]);
	for (int i = n - 1; i > 0; --i)
		back[i - 1] = max(back[i - 1], back[i]);
	nagai ans = 0;
	for (int forw = 0; forw < n; ++forw)
	{
		ans = max(ans, pref[forw + 1] - x[forw]);
		if (forw + 1 < n)
			ans = max(ans, pref[forw + 1] - 2 * x[forw] + back[forw + 1]);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	nagai c;
	cin >> n >> c;
	vector<nagai> x(n), v(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> v[i];
	nagai ans = calc(n, c, x, v);
	for (auto& y : x)
		y = c - y;
	reverse(x.begin(), x.end());
	reverse(v.begin(), v.end());
	ans = max(ans, calc(n, c, x, v));
	cout << ans << '\n';
}
