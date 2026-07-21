#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	int k = 0;
	ll ans = 0, mi = 1e9 + 7;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] < 0)
		{
			k++;
		}
		ans += abs(a[i]);
		mi = min(mi, abs(a[i]));
	}
	if (k & 1)
	{
		ans -= 2 * mi;
	}
	cout << ans << endl;
}
