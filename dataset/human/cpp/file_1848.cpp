#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<pair<int, int> > seq(n);
	for (int i = 0; i < n; ++i) seq[i] = make_pair(m + 1, i + 1);
	for (int i = 0; i < m; ++i) {
		int e; cin >> e;
		seq[e - 1].first = m - i;
	}
	sort(seq.begin(), seq.end());
	for (auto a : seq) cout << a.second << endl;

	return 0;
}
