#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	string a[50],b[50];
	for(int i=0;i<n;++i)cin >> a[i];
	for(int i=0;i<m;++i)cin >> b[i];
	for(int i=0;i<=n-m;++i){
		for(int j=0;j<=n-m;++j){
			int x;
			for(x=0;x<m;++x){
				if(a[i+x].substr(j,m)!=b[x])break;
			}
			if(x==m){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
