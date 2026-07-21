#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000005;
int n;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
map<int,int>f;
int fa[MAXN],cnt=0,ans=0;
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[n+1]^=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b[n+1]^=b[i];
	}
	n++;
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i];
		d[i]=b[i];
	}
	sort(c+1,c+n+1);
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=d[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i]||i==n)
		{
			if(i!=n)
				ans++;
			if(!f[a[i]])
				f[a[i]]=++cnt;
			if(!f[b[i]])
				f[b[i]]=++cnt;
		}
	}
	for(int i=1;i<=cnt;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
			fa[find(f[a[i]])]=find(f[b[i]]);
	for(int i=1;i<=cnt;i++)
		if(fa[i]==i)
			ans++;
	printf("%d\n",ans-1);
}
