#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],id;
vector<int> e[N];
map<int,int> M;
bool vis[N];
void dfs(int x){
	vis[x]=1;
	for (int i=0;i<e[x].size();i++)
	if (!vis[e[x][i]]) dfs(e[x][i]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[0]^=a[i];
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),b[0]^=b[i];
	for (int i=0;i<=n;i++) M[a[i]]++,M[b[i]]--;
	for (int i=0;i<=n;i++)
		if (M[a[i]]) return puts("-1"),0;
	for (int i=0;i<=n;i++)
		if (!M[a[i]]) M[a[i]]=++id;
	int ans=0;
	for (int i=0;i<=n;i++)
		if (a[i]!=b[i]) e[M[a[i]]].push_back(M[b[i]]),ans++;
	for (int i=1;i<=id;i++)
		if (!vis[i]&&!e[i].empty()) dfs(i),ans++;
	if (!e[M[a[0]]].empty()) ans--;
	if (a[0]!=b[0]) ans--;
	printf("%d\n",ans);
	return 0;
}
