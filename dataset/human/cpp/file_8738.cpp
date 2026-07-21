#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin>>n>>m;
	vector<string> A(n);
	vector<string> B(m);

	for (int i=0; i<n; i++)
		cin>>A[i];
	for (int i=0; i<m; i++)
		cin>>B[i];

	bool yes=false;
	for (int i=0; i<=n-m; i++) {
		for (int j=0; j<=n-m; j++) {
			bool possible=true;
			for (int k=0; k<m; k++) {
				for (int l=0; l<m; l++) {
					if (A[i+k][j+l] != B[k][l]) {
						possible=false;	
						break;
					}
				}
			}
			if (possible)
				yes=true;
		}
	}

	if (yes) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
