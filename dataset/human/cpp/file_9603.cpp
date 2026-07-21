#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, flag = 1;
	char a[51][51], b[51][51];
    int i,j,k,l;
 
	cin >> n >> m;
	for(i=0; i < n; i++)
		cin >>a[i];
	for(i=0; i < m; i++)
		cin>>b[i];
 
	for(i=0; i < n-m+1; i++) {
		for(j=0; j < n-m+1; j++) {
			for(k=0; k < m; k++) {
				for(l=0; l < m; l++) {
					if(a[i+k][j+l] != b[k][l])
						flag = 0;
				}
			}
			if(flag) {
				cout<<"Yes"<<endl;
				return 0;
			}
			flag = 1;
		}
	}
	cout <<"No"<<endl;
 
	return 0;
}
