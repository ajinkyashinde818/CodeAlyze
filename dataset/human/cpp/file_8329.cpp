#include<bits/stdc++.h>
using namespace std;

using ll=long long; 


void solve(){
	int n,m;
	cin>>n>>m;
	vector<string> fld1(n), fld2(m);
	for(auto& e:fld1)cin>>e;
	for(auto& e:fld2)cin>>e;
	for(int i=0; i<n-m+1; i++){
		for(int j=0; j<n-m+1; j++){
			//cout<<i<<" "<<j<<endl;
			bool flag=false;
			for(int ii=0; ii<m; ii++){
				for(int jj=0; jj<m; jj++){
					//cout<<i+ii<<" "<<j+jj<<endl;
					if(fld1[i+ii][j+jj]!=fld2[ii][jj]){
						flag=true;
						break;
					}
				}
			}
			if(!flag){
				cout<<"Yes"<<endl;
				return;
			}
		}
	}
	cout<<"No"<<endl;
}

signed main(){
	//while(1)
	solve();
}
