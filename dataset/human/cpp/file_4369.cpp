#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

inline LL read()
{
	char c=getchar();LL num=0;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())
		num=num*10+c-'0';
	return num;
}

const int N=1e5+5;

int n,ans;
int a[N],b[N],ta[N],tb[N];
int sa,sb,tot,date[N];
int fa[N],scc[N],cnt;

int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),ta[i]=a[i],sa^=a[i];
	for(int i=1;i<=n;++i)
		b[i]=read(),tb[i]=b[i],sb^=b[i];
	++n,a[n]=ta[n]=sa,b[n]=tb[n]=sb;
	sort(ta+1,ta+n+1),sort(tb+1,tb+n+1);
	for(int i=1;i<=n;++i)
	{
		if(ta[i]!=tb[i])
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<n;++i)
		if(a[i]!=b[i])
			scc[++cnt]=a[i],scc[++cnt]=b[i],++ans;
	if(ans==0)
	{
		cout<<0;
		return 0;
	}
	scc[++cnt]=a[n],scc[++cnt]=b[n];
	sort(scc+1,scc+cnt+1);
	cnt=unique(scc+1,scc+cnt+1)-scc-1;
	for(int i=1;i<=cnt;++i)
		fa[i]=i;
	for(int i=1,fx,fy;i<=n;++i)
	{
		if(a[i]!=b[i])
		{
			a[i]=lower_bound(scc+1,scc+cnt+1,a[i])-scc;
			b[i]=lower_bound(scc+1,scc+cnt+1,b[i])-scc;
			fx=find(a[i]),fy=find(b[i]);
			fa[fx]=fy;
		}
	}
	for(int i=1;i<=cnt;++i)
		if(fa[i]==i)
			++ans;
	cout<<ans-1;
	return 0;
}
