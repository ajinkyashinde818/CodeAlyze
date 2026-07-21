#include<bits/stdc++.h>
using namespace std;
string S[50],T[50];int n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>S[i];
	for(int i=0;i<m;i++)cin>>T[i];
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			bool OK=true;
			for(int k=i;k<i+m;k++){
				if(T[k-i]!=S[k].substr(j,m))OK=false;
			}
			if(OK==true){cout<<"Yes"<<endl;return 0;}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
