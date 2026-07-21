#include "bits/stdc++.h"
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> used(n+1,0);
	vector<int> ans(m);
	
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		ans[i]=a;
		used[a]=1;
	}
	
	vector<int> syu(n+1,0);
	
	for(int i=0;i<m;i++){
		if(syu[ans[m-i-1]]!=1){
			cout<<ans[m-i-1]<<endl;
			syu[ans[m-i-1]]=1;
		}
	}
	
	for(int i=1;i<n+1;i++){
		if(used[i]==0)cout<<i<<endl;
	}
	
	return 0;
}
