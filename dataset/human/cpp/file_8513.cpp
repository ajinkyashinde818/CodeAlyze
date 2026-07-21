#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for(int i = 0; i <= n-m; i++) {
		for(int j = 0; j <= n-m; j++) {
			bool ok = true;
			for(int k = 0; k < m; k++) {
				for(int l = 0; l < m; l++) {
					if(a[j+l][i+k] != b[l][k]) {
						ok = false;
						break;
					}
				}
				if(!ok)
					break;
			}
			if(ok) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
