#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, m, f = 0,cnt=0;
	char a[50][50], b[50][50];
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			for (int p = 0; p < m; p++) {
				for (int r = 0; r < m; r++) {
					if (a[i+p][j+r] != b[p][r]) f = 1;
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
	return 0;
}
