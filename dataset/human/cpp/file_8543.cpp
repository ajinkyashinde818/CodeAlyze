#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<string> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int y = 0; y <= n - m; y++) {
		for (int x = 0; x <= n - m; x++) {
			bool g = true;
			for (int cy = 0; cy < m; cy++) {
				for (int cx = 0; cx < m; cx++) {
					if (b[cy][cx] != a[y + cy][x + cx]) {
						g = false;
						cy = 99;
						break;
					}
				}
			}
			if (g) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";

	return 0;
}
