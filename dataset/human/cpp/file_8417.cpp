#include<bits/stdc++.h>
using namespace std;
string a[55],b[55];
int n,m;
int work(int i,int j){
	for(int k = 0;k<m;k++){
		for(int l = 0;l<m;l++){
			if(a[i+k][j+l]!=b[k][l]) return 0;
		}
	}
	return 1;
}
int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++) cin >> a[i];
	for(int i = 0;i<m;i++) cin >> b[i];
	for(int i = 0;i+m<=n;i++)
	for(int j = 0;j+m<=n;j++)
	if(work(i,j)){cout<<"Yes"<<endl;return 0;}
	cout<<"No"<<endl;
	return 0;
}
