#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;
const long long iinf=100000000000000007;
const int maxn = 1000005;
long long a[maxn];
long long sum[maxn];
int main()
{
	int n;
	cin>>n;
	memset(sum,0,sizeof(sum));
	long long sumn=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=(i==0?a[i]:sum[i-1]+a[i]);
		sumn+=a[i];
	}
	long long ans=iinf;
	for(int i=0;i<n-1;i++)
	{
		ans=min(ans,abs(sumn-2*sum[i]));
	}
	cout<<ans<<endl;
	return 0;
}
