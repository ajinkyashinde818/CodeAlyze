#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
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
	bool flag;
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			flag = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (b[k][l] != a[k + i][l + j]) {
						flag = false;
						break;
					}
				}
				if (flag == false) {
					break;
				}
			}
			if (flag == true) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
