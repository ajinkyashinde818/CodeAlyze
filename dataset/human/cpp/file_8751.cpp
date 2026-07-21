#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[55][55], b[55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
	cin >> n >> m;

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

	for (int i = 0; i <= n-m; i++) {
		for (int j = 0; j <= n-m; j++) {
			bool same = 1;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (b[k][l] != a[i+k][j+l]) {
						same = 0;
					}
				}
			}

			if (same) {
				cout << "Yes\n";
				return 0;
			}
		}
	}

	cout << "No\n";
 
	return 0;
}
