#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<ll> psum(n);
	psum[0] = a[0];
	for (int i = 1; i < n; i++)
		psum[i] = psum[i - 1] + a[i];
	ll ans = abs(2 * psum[0] - psum[n - 1]);
	for (int i = 1; i < n - 1; i++) {
		if (ans > abs(2 * psum[i] - psum[n - 1]))
			ans = abs(2 * psum[i] - psum[n - 1]);
	}
	cout << ans << endl;
	return 0;
}
