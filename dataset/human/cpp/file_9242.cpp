#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(n));
	vector<vector<char>> b(m, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	
	bool can = false;
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			bool tmpCan =true;
			for (int y = 0; y < m; y++) {
				for (int x = 0; x < m; x++) {
					if (a[i + y][j + x] != b[y][x]) tmpCan = false;				
				}
			}
			if (tmpCan) can = true;
		}
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
