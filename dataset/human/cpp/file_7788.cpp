#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	int n; cin >> n;
	vector<ll>a(n + 1, 0);
	ll sum = 0;
	for (int i = 1; i <= n;i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i < n; i++)a[i + 1] += a[i];

	ll ans = 1e12;
	for (int i = 1; i < n; i++) {
		ll snuke = a[i] - a[0], arai = sum - snuke;
		ans = min(ans, abs(snuke - arai));
	}
	cout << ans << endl;

	return 0;
}
