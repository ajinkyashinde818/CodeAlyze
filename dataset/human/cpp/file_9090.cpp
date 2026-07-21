#include<bits/stdc++.h>
using namespace std;
int n,m;
int image[105][105];
int B[105][105];
bool check(int y,int x){
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			if(B[i][j]!=image[i+y][j+x]) return false;
		}
	}
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		for(int j=0; s[j]; j++){
			if(s[j]=='#') image[i][j] = 1;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) image[i][j+n] = image[i][j];
	}
	for(int i=0; i<m; i++){
		string s;
		cin>>s;
		for(int j=0; s[j]; j++){
			if(s[j]=='#') B[i][j] = 1;
		}
	}
	bool exist = false;
	for(int i=0; i<=n-m; i++){
		for(int j=0; j<n; j++){
			if(check(i,j)) exist = true;
		}
	}
	if(exist) cout<<"Yes";
	else cout<<"No";
}
