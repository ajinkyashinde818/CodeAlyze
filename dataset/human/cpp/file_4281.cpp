#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N=2e5+5;

typedef long long LL;

int n,a[N],b[N],tot,h[N],e[N],nxt[N],m;

map <int,int> Id,sa,sb;

bool vis[N];

void Add(int x,int y)
{
	e[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
}

void Link(int x,int y)
{
	if (!Id[x]) Id[x]=++m;
	if (!Id[y]) Id[y]=++m;
	Add(Id[x],Id[y]); Add(Id[y],Id[x]);
}

void dfs(int x)
{
	vis[x]=1;
	for (int i=h[x];i;i=nxt[i]) if (!vis[e[i]]) dfs(e[i]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) a[0]^=a[i],b[0]^=b[i];
	for (int i=0;i<=n;i++)
	{
		sa[a[i]]++; sb[b[i]]++;
	}
	for (int i=0;i<=n;i++) if (sa[a[i]]!=sb[a[i]])
	{
		printf("-1\n"); return 0;
	}
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) Link(a[i],b[i]);
	if (!tot)
	{
		printf("0\n"); return 0;
	}
	Link(a[0],b[0]);
	//tot--;
	tot=(tot>>1)-2;
	for (int i=1;i<=m;i++) if (!vis[i])
	{
		tot++; dfs(i);
	}
	printf("%d\n",tot);
	return 0;
}
