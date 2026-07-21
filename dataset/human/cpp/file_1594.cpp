#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int>ans[N + 1];

int main() {
	//freopen("d.in", "r", stdin);
	//freopen("d.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int t = 0;
	int x = 1;
	while (t < n) {
		t++;
		ans[1].push_back(t);
		ans[++x].push_back(t);
		for (int i = 2; i < x; i++) {
			t++;
			ans[i].push_back(t);
			ans[x].push_back(t);
		}
	}
	if (t > n) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		cout << x << endl;
		for (int i = 1; i <= x; i++) {
			int len = ans[i].size();
			cout << len;
			for (int j = 0; j < len; j++) cout << " " << ans[i].at(j);
			cout << endl;
		}
	}
	return 0;
}
