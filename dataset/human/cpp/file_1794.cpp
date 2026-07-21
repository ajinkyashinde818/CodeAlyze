#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef vector<int> VI;

int main() {
	int n, m;
	while (cin >> n >> m) {
		VI A(m);
		for (auto& x : A) {cin >> x; --x; }
		VI used(n, 0);
		VI sol;
		reverse(A.begin(), A.end());
		for (int x : A) {
			if (!used[x]) {
				sol.push_back(x);
				used[x] = 1;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!used[i]) sol.push_back(i);
		}
		for (auto x : sol) cout << x+1 << '\n';
	}
}
