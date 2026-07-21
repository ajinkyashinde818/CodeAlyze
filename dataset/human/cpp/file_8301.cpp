#include<bits/stdc++.h>
using namespace std;
char a[51][51],b[51][51];
int main(){
	int n,m,i;
	cin>>n>>m;
	getchar();
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		cin>>b[i];
	}
	
	for(i=0;i+m-1<n;i++){
		for(int j=0;j+m-1<n;j++){
			bool flag=true;
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(a[i+k][j+l]!=b[k][l]){
						flag=false;
					}
				}
			}
			if(flag){
				cout<<"Yes";
				return 0;
			}
			flag=true;
		}
	}
	cout<<"No";
	return 0;
}
