#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];
	
	bool ans = false;
	for (int i = 0; i + m <= n; i++) {
		for (int j = 0; j + m <= n; j++) {
			bool res = true;
			for (int x = 0; x < m; x++) {
				for (int y = 0; y < m; y++) {
					res &= (a[i + x][j + y] == b[x][y]);
				}
			}
			ans |= res;
		}
	}
	
	cout << (ans ? "Yes" : "No") << '\n';
	
	return 0;
}
