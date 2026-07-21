#include "bits/stdc++.h"
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	char a[n+1][n+1], b[m+1][m+1];

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cin >> a[i][j];
		}
	}

	for(int i=1;i<=m;i++) {
		for(int j=1;j<=m;j++) {
			cin >> b[i][j];
		}
	}


	for(int g=0; g <= n-m+1; g++) {
		for(int r=0; r <= n-m+1; r++) {
			bool flag = true;
			for(int i=1;i<=m;i++) {
				for(int j=1;j<=m;j++) {
					if(a[r+i][g+j] != b[i][j]) flag = false;
				}
			}
			if(flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
}
