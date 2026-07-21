#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char a[N][N], b[N][N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			a[i][j] = str[j];
		}
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			b[i][j] = str[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool fail = 0;
			if (i + m - 1 >= n || j + m - 1 >= n) continue;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l]) fail = 1;					
				}
			}
			if (!fail) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
