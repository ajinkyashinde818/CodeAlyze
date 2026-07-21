#include <bits/stdc++.h> 

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;

	ll k = 1;
	bool ok = false;
	while (k * k - k <= 2 * N) {
		if (k * k - k == 2 * N) {
			ok = true;
			break;
		}
		++k;
	}

	if (!ok) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	cout << k << endl;

	vector<vector<int>> s(k);
	int n = 1;
	int idx = k - 1;
	for (int i = 0; i < k; ++i) {
		while (s[i].size() < k - 1) {
			s[i].push_back(n);
			s[idx].push_back(n);
			++n;
			--idx;
			if (idx <= i) { break; }
		}
		idx = k - 1;
	}

	for (int i = 0; i < s.size(); ++i) {
		cout << s[i].size() << " ";
		for (int j = 0; j < s[i].size(); ++j) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
