#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		sum += a.at(i);
	}
	ll snu = a.at(0);
	ll ara = sum - snu;
	ll ans = abs(snu - ara);
	for (int i = 1; i < n - 1; i++) {
		snu += a.at(i);
		ara -= a.at(i);
		ans = min(ans, abs(snu - ara));
	}
	cout << ans << endl;

}
