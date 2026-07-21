#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	string a[51];
	string b[51];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=0;i<n-m+1;i++){
		for(int j=0;j<n-m+1;j++){
			int flag=0;
			for(int k=i;k<i+m;k++){
				for(int l=j;l<j+m;l++){
					if(a[k][l]!=b[k-i][l-j]){
						flag=1;
						break;
					}
				}
				if(flag==1){
					break;
				}
			}
			if(flag==0){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
