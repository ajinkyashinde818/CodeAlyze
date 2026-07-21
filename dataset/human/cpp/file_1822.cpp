#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> used(n), st;
	for (int i = 0, e; i < m; i++) {
		cin >> e;
		st.push_back(e);
	}
	while (!st.empty()) {
		if (!used[st.back() - 1]) {
			used[st.back() - 1] = 1;
			cout << st.back() << endl;
		}
		st.pop_back();
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cout << i + 1 << endl;
		}
	}
	return 0;
}
