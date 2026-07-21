#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long ll;
ll a[maxn],sum[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	ll ans =1e15;
	for(int i=1;i<=n;i++)
	{
		sum[i] = sum[i-1]+a[i];
	}
	ll cnt = a[1];
	for(int i=2;i<=n;i++)
	{
		//cout<<sum[n]-sum[i]-sum[i]<<endl;
		ans = min(ans,abs(sum[n]-2*cnt));
		cnt += a[i]; 
	}
	cout<<ans<<endl;
	
	return 0;
}
