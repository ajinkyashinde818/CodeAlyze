#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int rd()
{
	int s=0,c;
	while((c=getchar())<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=getchar())>='0'&&c<='9');
	return s;
}
int upmin(int &a,int b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int n,a[100010],b[100010],c[100010],d[100010];
map<int,int> e;
int f[100010];
int cnt;
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
int main()
{
	scanf("%d",&n);
	int s=0;
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
		s^=a[i];
	}
	c[n+1]=a[n+1]=s;
	s=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		d[i]=b[i];
		s^=b[i];
	}
	d[n+1]=b[n+1]=s;
	n++;
	sort(c+1,c+n+1);
	sort(d+1,d+n+1);
	for(i=1;i<=n;i++)
		if(c[i]!=d[i])
		{
			printf("-1\n");
			return 0;
		}
	int ans=0;
	for(i=1;i<=n;i++)
		if(a[i]!=b[i]||i==n)
		{
			if(i<n)
				ans++;
			if(!e[a[i]])
				e[a[i]]=++cnt;
			if(!e[b[i]])
				e[b[i]]=++cnt;
		}
	if(!ans)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=cnt;i++)
		f[i]=i;
	for(i=1;i<=n;i++)
		if(a[i]!=b[i])
			f[find(e[a[i]])]=find(e[b[i]]);
	for(i=1;i<=cnt;i++)
		if(find(i)==i)
			ans++;
	printf("%d\n",ans-1);
	return 0;
}
