#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<char>>a(n, vector<char>(n)), b(m, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++)for (int j = 0; j < m; j++)cin >> b[i][j];

	bool exist = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + m - 1 >= n || j + m - 1 >= n)continue;

			bool match = true;
			for (int by = 0; by < m; by++) {
				for (int bx = 0; bx < m; bx++) {
					if (a[i+by][j+bx] != b[by][bx])match = false;
				}
			}
			if (match)exist = true;
		}
	}
	cout << (exist ? "Yes" : "No") << endl;

	return 0;
}
