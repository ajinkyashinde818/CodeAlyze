#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
const int N=1e5+5;
int a[N],b[N],n,X,Y,cnt,tot,head[N],ans;
bool vis[N];
map<int,int>id;
vector<int>va,vb;
struct edge{
	int to,nxt;
}e[N];
inline int get(int x){return id.count(x)?id[x]:id[x]=++tot;}
void dfs(int u){
	vis[u]=1;for(int i=head[u];i;i=e[i].nxt)if(!vis[e[i].to])dfs(e[i].to);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i],X^=a[i],va.push_back(a[i]);
	for(int i=0;i<n;++i)cin>>b[i],Y^=b[i],vb.push_back(b[i]);
	va.push_back(X),vb.push_back(Y);
	sort(va.begin(),va.end()),sort(vb.begin(),vb.end());
	if(va!=vb){cout<<"-1\n";return 0;}
	for(int i=0;i<n;++i)
	if(a[i]!=b[i]){
		int A=get(a[i]),B=get(b[i]);
		e[++cnt]=(edge){B,head[A]},head[A]=cnt;
		++ans;
	}
	if(!id.count(X))++ans;else
	if(X!=Y){
		int A=get(X),B=get(Y);
		e[++cnt]=(edge){B,head[A]},head[A]=cnt;
	}
	for(int i=1;i<=tot;++i)if(!vis[i])++ans,dfs(i);
	cout<<ans-1<<'\n';
	return 0;
}
