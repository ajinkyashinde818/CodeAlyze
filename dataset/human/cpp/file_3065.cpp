#include <bits/stdc++.h>

using namespace std;

int main(void) {
	long long N;
	cin >> N;
	vector<long long> A;
	vector<long long> abs_vals;
	long long sum = 0;
	long long sign = 1;
	for(int i = 0; i < N; ++i) {
		long long a;
		cin >> a;
		if(a < 0) sign *= -1;
		A.push_back(a);
		abs_vals.push_back(abs(a));
		sum += abs(a);
	}
	sort(abs_vals.begin(), abs_vals.end());
	if(sign == 1) {
		cout << sum << '\n';
	} else {
		cout << (sum - 2 * abs_vals[0]) << '\n';
	}
	return 0;
}
