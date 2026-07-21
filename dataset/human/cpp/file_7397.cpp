#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<long long> vals;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long next;
		cin >> next;
		vals.push_back(next);
		sum += next;
	}


	long long best = 1e16, cur = sum * -1;
	for (int i = 0; i < n - 1; i++) {
		cur += vals.at(i) * 2;
		if (abs(cur) < best) {
			best = abs(cur);
		}
	}

	cout << best << endl;

	return 0;

}
