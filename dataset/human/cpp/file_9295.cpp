#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,m;
	cin>>n>>m;
	char a[50][50],b[50][50];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cin>>a[i][j];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++)cin>>b[i][j];
	}
	bool ans=false;
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			bool flag=true;
			for(int k=0;k<m;k++){
				if(!flag)break;
				for(int l=0;l<m;l++){
					if(a[k+i][l+j]!=b[k][l]){
						flag=false;
						break;
					}
				}
			}
			if(flag){
				ans=true;
				break;
			}
		}
		if(ans)break;
	}
	if(ans)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

}
