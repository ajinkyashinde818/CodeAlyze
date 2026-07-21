#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=30100;
const ll INF=2147483647;
const ll mod=998244353;
ll a,b,c,n,ia[maxn],ib[maxn],ic[maxn],sum;
int main()
{
	cin>>a>>b>>c>>n;
	for(int i=0;i<=n;i++)
	{
		if(i*a>n)break;
		ia[i*a]=1;
	}
	for(int i=0;i<=n;i++)
	{
		if(i*b>n)break;
		ib[i*b]=1;
	}
	for(int i=0;i<=n;i++)
	{
		if(i*c>n)break;
		ic[i*c]=1;
	}
	for(int i=0;i<=n;i++)
	{
		if(ia[i])
		{
			for(int j=0;j<=n;j++)
			{
				if(n-i-j<0)continue;
				if(ib[j]&&ic[n-i-j])
				{
					sum++;
					//cout<<i/a<<" "<<j/b<<" "<<(n-i-j)/c<<"\n";
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
