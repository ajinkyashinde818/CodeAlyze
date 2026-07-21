#include <bits/stdc++.h>
using namespace std;
 
char a[51][51], b[51][51];
 
int main() {
	vector<pair<int,int>> v; 
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n;i++)
			for(int j=0; j<n;j++) cin>>a[i][j];
 
 
	for(int i=0; i<m;i++)
			for(int j=0; j<m;j++) cin>>b[i][j];
	

	int t=m-1;
	bool l;
	for(int i=0; i<n;i++)
			for(int j=0; j<n;j++) {
				if(i+t<n && j+t<n && a[i][j]==b[0][0] && a[i+t][j]==b[t][0] 
					&& a[i+t][j+t]==b[t][t] && a[i][j+t]==b[0][t])
				v.emplace_back(i,j);
			}
	for(auto & u:v){
		int first=u.first;
		int second=u.second;
		l=0;
		//cout<<a<<" "<<b<<endl;
		for(int i=0; i<m;i++)
			for(int j=0; j<m;j++) 
			if(b[i][j]!=a[i+first][j+second]) l=1;
			
		if(l==0) {
			cout<<"Yes"<<endl;
			return 0;
		}		
	}
	cout<<"No"<<endl;
	return 0;
}
