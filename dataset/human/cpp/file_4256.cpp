#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int N=200005;
map<int,int> mp;
map<int,int>::iterator ddq;
int n,i,j,k,l,x,y,ans,a[N],b[N],c[N],d[N],cnt,p[N];
bool brg[N];
int Abs(int a)
{
	return a>0?a:-a;
}
int find(int x)
{
	return !p[x]?x:p[x]=find(p[x]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		a[n+1]^=a[i];
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",b+i);
		b[n+1]^=b[i];
	}
	for(i=1;i<=n+1;++i)
		c[i]=a[i],d[i]=b[i];
	sort(c+1,c+1+n+1);
	sort(d+1,d+1+n+1);
	for(i=1;i<=n+1;++i)
		if(c[i]!=d[i])
		{
			printf("-1");
			return 0;
		}
	for(i=1;i<=n;++i)
	if(a[i]!=b[i])
	{
		if(!mp.count(a[i]))
			mp[a[i]]=++cnt;
		if(!mp.count(b[i]))
			mp[b[i]]=++cnt;
		ans++;
		if(find(mp[a[i]])!=find(mp[b[i]]))
			p[find(mp[a[i]])]=find(mp[b[i]]);
	}
	for(i=1;i<=cnt;++i)
		if(find(i)==i)
			++ans;
	--ans;
	for(i=1;i<=n;++i)
		if(a[n+1]==b[i]&&a[i]!=b[i])
			break;
	if(i>n)
		++ans;
	printf("%d",ans);
	return 0;
}
