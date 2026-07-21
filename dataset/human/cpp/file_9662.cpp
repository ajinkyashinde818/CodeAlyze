#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	string a[n];
	string b[m];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}

   for(int k=0;k<=n-m;k++){
	for(int i=0;i<=n-m;i++){
		int j;
		for(j=0;j<m;j++){
			if(b[j]!=a[j+k].substr(i,m)) break;
			//cout<<b[j]<<" "<<a[j+k].substr(i,m)<<endl;
		}
		if(j==m){
		 cout<<"Yes";
		 return 0;
		}
	}
}
	cout<<"No";

}
