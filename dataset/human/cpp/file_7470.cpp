#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll sum = accumulate(a.begin(), a.end(), 0LL);  // 第三引数を0とするとint型とみなされるためオーバーフロー

	vector<ll> s(n);
	s[0] = a[0];
	for (int i = 1; i < n - 1; i++) s[i] = s[i - 1] + a[i];

	ll ans = INT_MAX;
	for (int i = 0; i < n - 1; i++) ans = min(ans, abs(s[i] - (sum - s[i])));
	cout << ans << endl;
}
