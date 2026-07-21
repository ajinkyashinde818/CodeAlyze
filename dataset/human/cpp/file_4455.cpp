#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;

int n,m,a[maxn],b[maxn],t[maxn],t0[maxn],Ans;
int tote,FIR[maxn],TO[maxn<<1],NEXT[maxn<<1];
bool exist[maxn],vis[maxn];

void addedge(int u,int v)
{
	TO[++tote]=v;
	NEXT[tote]=FIR[u];
	FIR[u]=tote;
}

void dfs(int u)
{
	vis[u]=1;
	for (int p=FIR[u];p;p=NEXT[p])
	{
		int v=TO[p];
		if (!vis[v]) dfs(v);
	}
}

int main()
{
#ifdef h10
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]),a[0]^=a[i];
	for (i=1;i<=n;i++)
		scanf("%d",&b[i]),b[0]^=b[i];
	memcpy(t,a,sizeof(a));
	sort(t,t+n+1);
	memcpy(t0,b,sizeof(b));
	sort(t0,t0+n+1);
	for (i=0;i<=n;i++)
		if (t[i]!=t0[i]) {puts("-1"); return 0;}

	m=unique(t,t+n+1)-t-1;

	for (i=0;i<=n;i++)
		a[i]=lower_bound(t,t+m+1,a[i])-t;
	for (i=0;i<=n;i++)
		b[i]=lower_bound(t,t+m+1,b[i])-t;

	exist[a[0]]=exist[b[0]]=1;

	for (i=1;i<=n;i++)
		if (a[i]!=b[i])
		{
			exist[a[i]]=exist[b[i]]=1;
			addedge(a[i],b[i]);
			addedge(b[i],a[i]);
			Ans++;
		}
	for (i=0;i<=m;i++)
		if (exist[i]&&!vis[i])
			dfs(i),Ans++;
	Ans-=Ans!=0;
	printf("%d\n",Ans);
}
