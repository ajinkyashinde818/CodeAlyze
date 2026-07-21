#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, x;
int main() {
	cin >> n >> m;
	vector<pair<int, int> > w(n);
	for (int i = 0; i < n; i++) w[i] = make_pair(1, i + 1);
	for (int i = 0; i < m; i++) {
		cin >> x; --x;
		w[x].first = -i;
	}
	sort(w.begin(), w.end());
	for (int i = 0; i < n; i++) cout << w[i].second << endl;
	return 0;
}
