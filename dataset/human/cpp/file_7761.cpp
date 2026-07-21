#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, a[200000];
	cin >> n;
	long long snuke_sum = 0;
	long long araiguma_sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		snuke_sum += a[i];
	}
	long long ans = LONG_MAX;
	for (int i = 0; i < n - 1; ++i) {
		snuke_sum -= a[i];
		araiguma_sum += a[i];
		ans = min(ans, abs(snuke_sum - araiguma_sum));
	}
	cout << ans << endl;

	return 0;
}
