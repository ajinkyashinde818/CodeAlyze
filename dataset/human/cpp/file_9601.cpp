#include <iostream>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	char a[100][100], b[100][100];
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

	bool is_found = false;
	for (int ly = 0; ly < n; ly++) {
		for (int lx = 0; lx < n; lx++) {
			if (ly + m - 1 >= n || lx + m - 1 >= n) continue;

			bool match = true;
			for (int y = 0; y < m; y++) {
				for (int x = 0; x < m; x++) {
					if (a[ly + y][lx + x] != b[y][x]) {
						match = false;
					}
				}
			}
			if (match) is_found = true;
		}
	}

	cout << (is_found ? "Yes" : "No") << endl;

	return 0;
}
