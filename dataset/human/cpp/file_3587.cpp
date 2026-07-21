#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int64_t> A(N);
	int64_t minA = (1e9) + 1;
	int64_t sum = 0;
	int minus = 0;
	for (auto&i:A) {
		cin >> i;
		minA = min(minA, abs(i));
		if (i<0) {
			minus++;
		}
		sum += abs(i);
	}

	if (minus%2) {
		sum -= (minA*2);
	}

	cout << sum << "\n";

	return 0;
}
