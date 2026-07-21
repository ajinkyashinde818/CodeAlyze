#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> a(n, 0);
	long long abs_sum = 0;
	long long abs_min = 1e18;
	int n_minus = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		if (a[i] < 0) {
			n_minus++;
		}

		abs_sum += abs(a[i]);
		abs_min = min(abs_min, abs(a[i]));
	}

	long long ans = abs_sum;
	if (n_minus % 2 == 1) {
		ans -= 2LL * abs_min;
	}
	cout << ans << endl;
	return 0;
}
