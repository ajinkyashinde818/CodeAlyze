#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int x = sqrt(8 * n + 1);
	x = (x + 1) / 2;
	if (x * (x - 1) != n + n) return cout << "No" << '\n',0;
	cout << "Yes" << '\n';
	int cur = 0;
	vector<vector<int>> res(x, vector<int>());
	for (int i = 0; i < x; ++i) {
		for (int j = i + 1; j < x; ++j) {
			++cur;
			res[i].push_back(cur);
			res[j].push_back(cur);
		}
	}
	cout << x << '\n';
	for (int i = 0; i < x; ++i) {
		cout << res[i].size() << ' ';
		for (int j : res[i]) cout << j << ' ';
		cout << '\n';
	} 
}
