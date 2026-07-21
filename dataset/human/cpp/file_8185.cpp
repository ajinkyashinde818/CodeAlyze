#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

int main() {
	ll n, x = 0, y = 0, ans = 100000000000;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x += a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		x -= a[i];
		y += a[i];
		ans = min(ans, abs(x - y));
	}
	cout << ans << endl;

	return 0;
}
