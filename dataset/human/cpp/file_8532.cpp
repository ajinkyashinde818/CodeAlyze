#include <bits/stdc++.h>

using namespace std;

string A[55], B[55];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		A[i] = str;
	}
	for (int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		B[i] = str;
	}
	for (int i = 0; i < n - m + 1; i ++) {
		for (int j = 0; j < n - m + 1; j++) {
			bool ok = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; ++l) {
					if (A[i + k][j + l] != B[k][l]) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
			}
			if (ok) {
				printf("Yes");
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}
