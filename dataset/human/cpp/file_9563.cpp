#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector< vector<char> > a(n, vector<char>(n));
	vector< vector<char> > b(m, vector<char>(m));
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
	bool h2 = false;
	for (int i = 0; i <= n-m; i++) {
		for (int j = 0; j <= n-m; j++) {
			bool h = true;
			for (int p = 0; p < m; p++) {
				for (int q = 0; q < m; q++) {
					if (a[i+p][j+q] != b[p][q]) {
						h = false;
					}
				}
			}
			if (h) {
				h2 = true;
			}
		}
	}
	if (h2) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
