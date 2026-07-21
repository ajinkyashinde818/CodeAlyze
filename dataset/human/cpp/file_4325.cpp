#include<bits/stdc++.h>
using namespace std;
typedef vector<int>VI;
const int N=1e5+5;
int a[N],b[N],n,i,ans,z;
inline VI F(int*be,int*en){VI a(be,en);sort(a.begin(),a.end());return a;}
map<int,VI>e;
set<int>s;
void dfs(int x){s.insert(x);z|=x==a[n+1];for(int y:e[x])if(!s.count(y))dfs(y);}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>a[i],a[n+1]^=a[i];for(i=1;i<=n;++i)cin>>b[i],b[n+1]^=b[i];
	if(F(a+1,a+n+2)!=F(b+1,b+n+2))return puts("-1"),0;
	for(i=1;i<=n;++i)if(a[i]!=b[i])e[a[i]].push_back(b[i]),e[b[i]].push_back(a[i]),++ans;
	for(i=1;i<=n;++i)if(a[i]!=b[i] && !s.count(a[i]))z=0,dfs(a[i]),ans+=!z;
	cout<<ans<<endl;
	return 0;
}
