#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],b[maxn],a1[maxn],b1[maxn];
vector<int> G[maxn];
map<int,int> mp;
bool vis[maxn];
void dfs(int u)
{
	vis[u]=1;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (!vis[v]) dfs(v);
	}
}
int main()
{
	int col=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a1[i]=a[i];
		a[n+1]^=a[i];
		if (!mp[a[i]]) mp[a[i]]=++col;
	}
	a1[n+1]=a[n+1];
	if (!mp[a[n+1]]) mp[a[n+1]]=++col;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b1[i]=b[i];
		b[n+1]^=b[i];
		if (!mp[b[i]]) mp[b[i]]=++col;
	}
	b1[n+1]=b[n+1];
	if (!mp[b[n+1]]) mp[b[n+1]]=++col;
	sort(a1+1,a1+n+2);
	sort(b1+1,b1+n+2);
	for (int i=1;i<=n+1;i++)
	    if (a1[i]!=b1[i])
	    {
	    	cout<<"-1";
	    	return 0;
		}
	
	for (int i=1;i<=n+1;i++) a[i]=mp[a[i]],b[i]=mp[b[i]];
	int ans=0;
	for (int i=1;i<=n;i++)
	    if (a[i]!=b[i])
	    {
	    	ans++;
	        G[a[i]].push_back(b[i]);
	    }
	if (a[n+1]!=b[n+1]) G[a[n+1]].push_back(b[n+1]);
	for (int i=1;i<col;i++)
	    if (G[i].size()&&!vis[i])
	    {
		    dfs(i);
		    ans++;
		}
	if (!vis[col]) ans++;
	cout<<ans-1;
	return 0;
}
