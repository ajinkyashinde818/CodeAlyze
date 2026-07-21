#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int64_t> v(n);
	int64_t sum = 0;
	int64_t minn = 1e9 + 7;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += abs(v[i]);
		minn = min(minn, abs(v[i]));
	}
	int neg = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] < 0) {
			neg = (neg == 0);
		}
	}
	if (neg) {
		cout << sum - 2 * minn;
	}else {
		cout << sum;
	}
}
