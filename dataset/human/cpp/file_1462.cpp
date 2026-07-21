#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int k = int(sqrt(n * 8 + 1) + 1) / 2;
	if (k*(k - 1) != n * 2) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes\n" << k << '\n';
	vector<pair<int, int>> a;
	vector<int> b[1000];
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			a.emplace_back(i, j);
	for (int i = 0; i < a.size(); i++) {
		b[a[i].first].push_back(i);
		b[a[i].second].push_back(i);
	}
	for (int i = 0; i < k; i++) {
		cout << k - 1;
		for (int j = 0; j < k - 1; j++)
			cout << ' ' << b[i][j] + 1;
		cout << '\n';
	}
	cout << flush;
	return 0;
}
