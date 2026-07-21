#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<string> b(m);
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	bool res=false;
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			bool ismatch=true;
			for(int ii=0;ii<m;ii++){
				for(int jj=0;jj<m;jj++){
					if(a[i+ii][j+jj]!=b[ii][jj]) ismatch=false;
				}
			}
			res=res|ismatch;
		}

	}
	cout<<(res?"Yes":"No")<<endl;
	return 0;
}
