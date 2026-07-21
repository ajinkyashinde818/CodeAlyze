#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,i,j,i2,j2,jud;
	cin >> n >> m;
	vector<string> a(n),b(m);
	for(i=0; i<n; i++){
		cin >> a[i];
	}
	for(i2=0; i2<m; i2++){
		cin >> b[i2];
	}
	for(i=0; i<=n-m; i++){
		for(j=0; j<=n-m; j++){
			jud=0;
			for(i2=0; i2<m && jud==0; i2++){
				for(j2=0; j2<m && jud==0; j2++){
					if(a[i+i2][j+j2]!=b[i2][j2]){
						jud++;
					}
				}
			}
			if(jud==0){
				cout << "Yes"; return 0;
			}
		}
	}
	cout << "No";
}
