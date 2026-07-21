#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	char a[n][n], b[m][m];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin>>a[i][j];
	for (int i=0; i<m; i++)
		for (int j=0; j<m; j++)
			cin>>b[i][j];
	for (int i=0; i<=n-m; i++) for (int j=0; j<=n-m; j++) {
		bool ok=true;
		for (int x=0; x<m; x++) for (int y=0; y<m; y++)
			if(a[i+x][j+y]!=b[x][y]) ok=false;
		if(ok) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
