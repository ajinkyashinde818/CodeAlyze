#include<bits/stdc++.h>
using namespace std;

int a[100001],b[100001];
bool vis[100001];
struct UF{
	int p[100001],sz[100001];
	void I(int n){
		for(int i=0;i<n;i++)
			sz[p[i]=i]=1;
	}
	int F(int x){return x==p[x]?x:p[x]=F(p[x]);}
	bool U(int x,int y){
		x=F(x),y=F(y);
		if(x==y)	return false;
		if(sz[x]<sz[y])
			swap(x,y);
		p[y]=x;
		sz[x]+=sz[y];
		return true;
	}
}D;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> A,B;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[0]^=a[i],A.emplace_back(a[i]);
	A.emplace_back(a[0]);
	for(int i=1;i<=n;i++)
		cin>>b[i],b[0]^=b[i],B.emplace_back(b[i]);
	B.emplace_back(b[0]);
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	if(A!=B)	return cout<<-1<<endl, 0;
	A.resize(unique(A.begin(),A.end())-A.begin());
	map<int,int> M;
	for(int i=0;i<A.size();i++)
		M[A[i]]=i;
	D.I((int)A.size());
	int ans = -1;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]){
			vis[M[a[i]]]=true;
			vis[M[b[i]]]=true;
			D.U(M[a[i]],M[b[i]]);
			ans++;
		}
	vis[M[a[0]]]=true;
	vis[M[b[0]]]=true;
	for(int i=0;i<A.size();i++)
		if(vis[i])
			if(i==D.F(i))
				ans++;
	cout<<ans<<endl;
}
