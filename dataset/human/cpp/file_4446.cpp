#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int kInf = 1e9;

int p[100010];

void Read(vector<int>& a, int n) {
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum ^= a[i];
	}
	a[n+1] = sum;
}

int parent(int x) {
	if (p[x] != 0) {
		return p[x] = parent(p[x]);
	}
	return x;
}

bool unite(int x, int y) {
	x = parent(x);
	y = parent(y);

	if (x != y) {
		p[x] = y;
		return true;
	}
	return false;
}

void Solve() {
	int n;
	cin >> n;

	vector<int> a(n+2), b(n+2);
	Read(a, n);
	Read(b, n);

	vector<int> go(n+1);
	vector<bool> viz(n+1);

	map<int, vector<int>> where;
	map<int, int> seen;

	for (int i = 1; i <= n+1; ++i) {
		if (a[i] == b[i])
			continue;

		where[b[i]].push_back(i);
	}

	for (int i = 1; i <= n+1; ++i) {
		if (a[i] == b[i])
			continue;

		if (where[a[i]].empty()) {
			cout << -1 << "\n";
			return;
		}

		go[i] = where[a[i]].back();
		where[a[i]].pop_back();
	}

	if (a[n+1] == b[n+1]) {
		seen[a[n+1]] = n+1;
	}

	int ans = 0;

	for (int i = 1; i <= n+1; ++i) {
		if (!viz[i] && a[i] != b[i]) {
			int cnt = 0;
			int special = 0;
			bool merged = false;

			vector<int> now;
			for (int j = i; !viz[j]; j = go[j]) {
				// cerr << j << " ";
				++cnt;
				viz[j] = true;
				if (j == n+1)
					special += 2;
				if (seen.find(a[j]) != seen.end() && !merged) {
					special += unite(seen[a[j]], i);
				}
				now.push_back(a[j]);
			}
			// cerr << "\n";

			for (auto el : now) {
				seen[el] = i;
				// cerr << el << " ";
			}
			// cerr << "\n";

			ans += cnt + 1 - special;
		}
	}

	cout << ans << "\n";
}

int main() {
	int tests = 1;
	for (;tests; --tests) {
		Solve();
	}
}
