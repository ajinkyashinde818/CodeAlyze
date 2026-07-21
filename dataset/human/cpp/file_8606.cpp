#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
	int n, m;

	cin >> n >> m;
	string a[n], b[m];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}


	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == b[0][0]) {
				for (int k = 0; k < m; ++k) {

					for (int h = 0; h < m; ++h) {

						if (a[i + k][h + j] == b[k][h])
							cnt++;
						else
							goto y;
					}
				}
			}
//			cout<<cnt<<endl;
			if (cnt == m * m) {
				puts("Yes");
				return 0;
			}
			y: cnt = 0;
		}
		
	}

	puts("No");
}
