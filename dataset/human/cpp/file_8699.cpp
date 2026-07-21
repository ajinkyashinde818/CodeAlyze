#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(50, vector<char>(50)), b(50, vector<char>(50));
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
	bool ans = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + m - 1 >= n || j + m - 1 >= n)continue;
			bool t = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l])t = false;
				}
			}
			if (t)ans = true;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}
