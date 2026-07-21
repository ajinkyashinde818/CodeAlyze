#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int b[100100];
int bas[200200],tot;
int get(int x){return lower_bound(bas+1,bas+tot+1,x)-bas;}
int cnt[100100];

int ans;
bool ob[100100];
struct UFS{
	int fa[100100];
	int siz[100100];
	void init(){for(int i=1;i<=tot;++i)fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y)
	{
		int fx=find(x),fy=find(y);
		if(fx==fy)return;
		fa[fy]=fx;
		siz[fx]+=siz[fy];
		ob[fx]=ob[fy]=1;
		siz[fy]=0;
	}
}ufs;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]),bas[++tot]=a[i];
		a[n+1]^=a[i];
	}
	bas[++tot]=a[n+1];
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&b[i]),bas[++tot]=b[i];
		b[n+1]^=b[i];
	}
	bas[++tot]=b[n+1];
	sort(bas+1,bas+tot+1);
	tot=unique(bas+1,bas+tot+1)-bas-1;
	for(int i=1;i<=n+1;++i)
	{
		a[i]=get(a[i]);
		cnt[a[i]]++;
		b[i]=get(b[i]);
	}
	for(int i=1;i<=n+1;++i)
	{
		cnt[b[i]]--;
		if(cnt[b[i]]<0)
		{
			puts("-1");
			return 0;
		}
	}

	ufs.init();
	for(int i=1;i<=n+1;++i)
		if(a[i]!=b[i]) 
		{
			ufs.merge(a[i],b[i]);
			if(i<=n)ans++;
		}
	if(!ans){puts("0");return 0;}
	ob[a[n+1]]=ob[b[n+1]]=1;
	for(int i=1;i<=tot;++i)
		if(ufs.siz[i]&&ob[i]) ans++;
	ans--;
	printf("%d\n",ans);
	return 0;
}
