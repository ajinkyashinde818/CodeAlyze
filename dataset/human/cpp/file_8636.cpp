#include <iostream>

using namespace std;

char a[50][50], b[50][50];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int flag = 0;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			for (int i2 = 0; i2 < m; i2++) {
				for (int j2 = 0; j2 < m; j2++) {
					//cout << "i+i2:" << i + i2 << "\tj+j2:" << j + j2 << endl;
					if (a[i + i2][j + j2] != b[i2][j2]) {
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
			if (!flag) {
				cout << "Yes" << endl;
				return 0;
			}
			flag = 0;
		}
	}

	cout << "No" << endl;
}
