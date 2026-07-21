#include <bits/stdc++.h>
using namespace std;
const int MAXI = 1005;

int N, g[MAXI][MAXI];

int solve(int N) {
	for (int i = 1; i*(i-1)/2 <= N; i++) {
		if (i*(i-1)/2 == N) {
			int cnt = 0;
			for (int j = 1; j <= i; j++) {
				for (int k = j+1; k <= i; k++) {
					g[j][k] = g[k][j] = ++cnt;
				}
			}
			
			cout << "Yes\n";
			cout << i << "\n";
			for (int j = 1; j <= i; j++) {
				cout << i-1;
				for (int k = 1; k <= i; k++) {
					if (k == j) continue;
					cout << " " << g[j][k];
				}
				cout << "\n";
			}
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	solve(N);
	
	return 0;
}
