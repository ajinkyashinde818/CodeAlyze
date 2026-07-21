#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<string>a(n),b(m),t(m);
	for(int i=0;i<n;++i)cin>>a.at(i);
	for(int i=0;i<m;++i)cin>>b.at(i);
	bool yes=false;
	for(int i=0;i<=n-m;++i){
		for(int j=0;j<=n-m;++j){
			for(int k=0;k<m;++k){
				t.at(k)=a.at(i+k).substr(j,m);
			}
			if(b==t)yes=true;
		}
	}
	cout<<(yes?"Yes"s:"No"s)<<"\n"s;
}
