#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int maxn=200010;
typedef long long ll;
ll s[maxn];
ll ab(ll x)
{
	return x>0?x:-x;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		s[0]=0;
		for(int i=1;i<=n;i++)
		{
			int t;
			scanf("%d",&t);
			s[i]=s[i-1]+t;
		}
		ll temp=s[n],ans=1e15;
		for(int i=1;i<n;i++)
		{
			ans=min(ans,ab(temp-2*s[i]));	
		}
		printf("%lld\n",ans);
	}
	return 0;
}
