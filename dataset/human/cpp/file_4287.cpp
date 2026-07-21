#include<cstdio>
#include<map>
#include<algorithm>
#include<cctype>
using namespace std;
const int N=1e5+5;
int num,sum;
int a[N],b[N],f[N],g[N];
bool bz[N];
map<int,int>mp;
inline int read()
{
	int X=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) X=(X<<1)+(X<<3)+(ch^48),ch=getchar();
	return w?-X:X;
}
int get(int x)
{
	return f[x]==x?x:f[x]=get(f[x]);
}
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		sum^=x;
		if(!mp.count(x)) a[i]=mp[x]=++num; else a[i]=mp[x];
		f[i]=a[i];
	}
	if(!mp.count(sum)) a[n+1]=mp[sum]=++num; else a[n+1]=mp[sum];
	f[n+1]=a[n+1];
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(!mp.count(x)) b[i]=mp[x]=++num; else b[i]=mp[x];
		g[i]=b[i];
	}
	sort(f+1,f+1+n+1);
	sort(g+1,g+1+n);
	for(int i=1,j=0;i<=n+1;i++)
	{
		if(j<n && g[j+1]==f[i]) j++;
		if(i==n+1 && j<n) return 0&puts("-1");
	}
	for(int i=1;i<=num;i++) f[i]=i;
	sum=0;
	for(int i=1;i<=n;i++)
		if(a[i]^b[i])
		{
			sum++;
			int x=get(a[i]),y=get(b[i]);
			if(x^y) f[y]=x;
		}
	for(int i=1;i<=n;i++)
		if(a[i]^b[i] && !bz[get(a[i])]) sum++,bz[get(a[i])]=true;
	if(!bz[get(a[n+1])]) sum++;
	printf("%d",sum-1);
	/*for(int i=1;i<=num;i++) f[i]=g[i]=0;
	for(int i=1;i<=n;i++)
		if(a[i]^b[i])
		{
			g[f[a[i]]=a[i]]=1;
			g[f[b[i]]=b[i]]=1;
		}
	g[f[a[n+1]]=a[n+1]]=1;
	for(int i=1;i<=n;i++)
		if(a[i]^b[i])
		{
			int x=get(a[i]),y=get(b[i]);
			if(x^y)
			{
				f[y]=x;
				g[x]+=g[y];
				g[y]=0;
			}
		}
	if(g[get(a[n+1])]>1) sum=-2; else sum=g[get(a[n+1])]=0;
	for(int i=1;i<=num;i++)
		if(g[i]) sum+=g[i]+1;
	printf("%d",sum);*/
	return 0;
}
