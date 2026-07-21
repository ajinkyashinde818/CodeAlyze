#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[50][50], b[50][50];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			cin >> b[i][j];

	for (int i = 0; i <= n - m; ++i) {
		for (int j = 0; j <= n - m; ++j) {
			bool f = true;
			for (int k = 0; k < m; ++k) {
				for (int l = 0; l < m; ++l) {
					if (a[i + k][j + l] != b[k][l]) f = false;
				}
			}

			if (f) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
}
