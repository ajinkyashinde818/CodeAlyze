#include <bits/stdc++.h>
using namespace std;

long long l,g;
string s[100005];

int binserch(int ok,int ng,int d)
{
	if (ng-ok<2)
	{
		return ok;
	}
	int mid=(ok+ng)/2;
	if (s[mid][d]=='0')
	{
		return binserch(mid,ng,d);
	}
	else
	{
		return binserch(ok,mid,d);
	}
}

void dfs(int x,int y,long long d)
{
	if (x==y)
	{
		long long z=l-d,now=2LL;
		while (z%now==0LL)
		{
			now*=2LL;
		}
		now/=2LL;
		g^=now;
		return;
	}
	else if (x+1==y&&s[x].size()==d+1)
	{
		return;
	}
	int z=binserch(x-1,y,d+1);
	dfs(x,z+1,d+1);
	dfs(z+1,y,d+1);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n>>l;
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
	}
	sort(s,s+n);
	int tmp=binserch(-1,n,0);
	g=0LL;
	dfs(0,tmp+1,0);
	dfs(tmp+1,n,0);
	if (g==0LL)
	{
		cout<<"Bob\n";
	}
	else
	{
		cout<<"Alice\n";
	}
	return 0;
}
