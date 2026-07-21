#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	char a[50][50], b[50][50];
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
	int f = 0;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (b[k][l] != a[i + k][j + l]) {
						f = 1;
					}
				}
			}
			if (f == 0) {
				cout << "Yes" << endl;
				return 0;
			}
			f = 0;
		}
	}
	cout << "No" << endl;
}
