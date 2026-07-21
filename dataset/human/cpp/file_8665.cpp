#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
typedef long long ll;
const int MOD = 1000000007;
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	if (n == m) {
		bool flag = 1;
		for (int i = 0; i < n; i++)
			if (a[i] != b[i])
				flag = 0;
		if (flag) {
			cout << "Yes" << endl;
			return 0;
		}

	}

	//左上座標
	for (int i = 0; i < n - m; i++) {
		for (int j = 0; j < n - m; j++) {
			bool flag = 1;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[k + i][l + j] != b[k][l])
						flag = 0;
				}
			}
			if (flag) {
				cout << "Yes" << endl;
				return 0;
			}

		}
	}
	cout << "No" << endl;
	return 0;
}
