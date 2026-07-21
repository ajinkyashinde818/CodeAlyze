#include <iostream>
using namespace std;
int n, m;
string a[55], b[55];
int main() {
	int i, j, k;
	cin>>n>>m;
	for(i=0; i<n; i++) cin>>a[i];
	for(i=0; i<m; i++) cin>>b[i];
	for(i=0; i<=n-m; i++) for(j=0; j<=n-m; j++) {
		for(k=0; k<m; k++) if(a[i+k].substr(j,m) != b[k]) break;
		if(k==m) {cout<<"Yes"; return 0;}
	}
	cout<<"No";
	return 0;
}
