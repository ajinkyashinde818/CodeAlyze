#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;
using ll = long long;

int main() {

	int n;
	ll sum = 0, sum1 = 0,ans = 1e15;

	cin >> n;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < n; i++) {
		sum1 += a[i];
		if (i + 1 < n)ans = min(ans, abs(sum - 2 * sum1));
	}

	cout << ans << endl;

	return 0;
}
