#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N],b[N],ca[N],cb[N],p[N],ans;
map<int,int> mp;
bool vis[N];
int find(int x)
{
	while(p[x]!=x)
	{
		p[x]=p[p[x]];
		x=p[x];
	}
	return x;
}
int main()
{
	ans=0;
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	a[n]=b[n]=0;
	int ind=1;
	for(int i=0;i<N;i++)
	{
		p[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		mp[a[i]];
		a[n]^=a[i];
		ca[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",b+i);
		mp[b[i]];
		b[n]^=b[i];
		cb[i]=b[i];
	}
	cb[n]=b[n];
	ca[n]=a[n];
	mp[a[n]];
	mp[b[n]];
	sort(ca,ca+n+1);
	sort(cb,cb+n+1);
	for(int i=0;i<n+1;i++)
	{
		if(ca[i]!=cb[i])
		{
			printf("-1");
			return 0;
		}
	}
	for( auto& it : mp)
	{
		it.second=ind++;
	}
	for(int i=0;i<n+1;i++)
	{
		a[i]=mp[a[i]];
		b[i]=mp[b[i]];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			ans++;
			int x=find(a[i]);
			int y=find(b[i]);
			if(x!=y)
			{
				p[x]=y;
			}
		}
	}
	int x=find(a[n]);
	int y=find(a[n]);
	if(x!=y)
	p[x]=y;
	for(int i=0;i<n+1;i++)
	{
		if(a[i]!=b[i]||i==n)
		{
			if(!vis[find(a[i])])
			{
				ans++;
				vis[find(a[i])]=1;
			}
		}
	}
	ans--;
	printf("%d",ans);
	return 0;
}
