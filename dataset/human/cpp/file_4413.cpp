#include <bits/stdc++.h>
using namespace std;

int n,a[100009],b[100009],c1,c2,cntw,col[100009];vector<int>x,y,X[100009];

void dfs(int pos){
	if(col[pos]>=1) return;
	col[pos]=cntw;
	for(int i=0;i<X[pos].size();i++) dfs(X[pos][i]);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];c1^=a[i];x.push_back(a[i]);} x.push_back(c1);
	for(int i=1;i<=n;i++){cin>>b[i];c2^=b[i];y.push_back(b[i]);} y.push_back(c2);
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	if(x!=y){cout<<"-1"<<endl;return 0;}
	
	x.erase(unique(x.begin(),x.end()),x.end());
	y.erase(unique(y.begin(),y.end()),y.end());
	
	int cnt=0;for(int i=1;i<=n;i++){if(a[i]!=b[i]){cnt++;}}
	
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(x.begin(),x.end(),a[i])-x.begin();
		b[i]=lower_bound(y.begin(),y.end(),b[i])-y.begin();
		if(a[i]!=b[i]){
			X[a[i]].push_back(b[i]);
			X[b[i]].push_back(a[i]);
		}
	}
	c1=lower_bound(x.begin(),x.end(),c1)-x.begin();
	c2=lower_bound(y.begin(),y.end(),c2)-y.begin();
	if(c1!=c2){
		X[c1].push_back(c2);
		X[c2].push_back(c1);
	}
	else{
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i] && b[i]==c1) flag=true;
		}
		if(flag==false) cntw++;
	}
	for(int i=0;i<x.size();i++){
		if(col[i]>=1 || X[i].size()==0) continue;
		cntw++;dfs(i);
	}
	if(cnt==0) cout<<"0"<<endl;
	else cout<<cnt+cntw-1<<endl;
	return 0;
}
