#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool even = true;
	bool zero = false;
	int64_t sum = 0;
	int64_t mini = 1000000000;
	for (int i = 0; i < n; i++) {
		int64_t x;
		cin >> x;
		if (x < 0) {
			even = !even;
		}
		else if (x == 0)zero = true;
		else;
		mini = min(abs(x), mini);
		sum += abs(x);
	}
	if (zero == false && even == false)cout << sum - mini -mini<< endl;
	else cout << sum << endl;
}
