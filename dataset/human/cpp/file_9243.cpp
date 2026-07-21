#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, m;
	string a[50], b[50],ans="No";
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		a[i] = tmp;
	}
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		b[i] = tmp;
	}
	for (int x = 0; x <= n - m; x++) {
		for (int y = 0; y <= n - m; y++) {
			for (int i = 0; i < m*m; i++) {
				if (a[y + i / m][x + i%m] != b[i / m][i%m]) {
					break;
				}
				if (i == m*m - 1)ans = "Yes";
			}
		}
	}
	cout << ans << endl;
	return 0;
}
