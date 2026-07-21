#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char a[51][51],b[51][51];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>b[i][j];
		}
	}
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			int p=0; 
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(a[i+k][j+l]!=b[k][l]){
						p=1;
						break;
					}
				}
				if(p==1){
					break;
				}
			}
			if(p==0){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
