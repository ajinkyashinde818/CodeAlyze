#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string A[n];
	string B[m];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		A[i] = s;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		B[i] = s;
	}
	bool res = false;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			bool all = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					all = (A[i + k][j + l] == B[k][l]);
					if (!all)
						break;
				}
				if (!all)
					break;
 			}
 			if (all) {
 				res = all;
 			}
 			if (res)
 				break;
		}
		if (res)
			break;
	}
	cout << (res?"Yes":"No") << "\n";
	return 0;
}
