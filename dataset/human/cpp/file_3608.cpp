#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b, a%b);
}

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll sum = 0;
	for (int i = 0; i < n; i++) sum += abs(a[i]);
	int cnt = 0;
	for (int i = 0; i < n; i++) cnt += a[i] < 0;
	if (cnt & 1) {
		ll mi = 1e18;
		for (int i = 0; i < n; i++) {
			mi = min(mi, abs(a[i]));
		}
		cout << sum - 2 * mi << endl;
	}
	else cout << sum << endl;
	return 0;
}
