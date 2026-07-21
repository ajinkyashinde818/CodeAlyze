#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],c[N],fa[N],len,nw=0,ans=0;
map<int,int>vis;bool f__k[N];
int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
void mg(int x,int y)
{
	if(find(x)!=find(y))
		fa[find(x)]=find(y),f__k[find(y)]=1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),vis[a[i]]++,nw^=a[i];
	vis[nw]++,a[n+1]=nw,nw=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]),vis[b[i]]--,nw^=b[i];
		if(vis[b[i]]<0)return puts("-1"),0;
	}
	b[++n]=nw;
	for(int i=1;i<=n;i++)c[i]=a[i];
	sort(c+1,c+n+1);
	len=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(c+1,c+len+1,a[i])-c;
	for(int i=1;i<=n;i++)
		b[i]=lower_bound(c+1,c+len+1,b[i])-c;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			if(i<n)ans++;
			mg(a[i],b[i]);
		}
	}
	if(!ans)return puts("0"),0;
	f__k[a[n]]=f__k[b[n]]=1;
	for(int i=1;i<=len;i++)
		if(fa[i]==i&&f__k[i])ans++;
	cout<<ans-1;	
}
