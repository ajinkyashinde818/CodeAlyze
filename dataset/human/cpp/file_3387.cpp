#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxN = 1e5+7;
const int maxV = 90010;
//const int INF = 1e9+9;
const ll INF = (1ll)<<60;
const int MOD = 998244353;

int n;
ll a[maxN];
ll f[maxN];
ll g[maxN];

int main()
{

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	f[2] = a[1];  //没有操作 
	g[2] = -a[1]; //操作了 
	for(int i=3;i<=n;i++)
	{
		f[i] = max(f[i-1]+a[i-1],g[i-1]-a[i-1]);
		g[i] = max(f[i-1]-a[i-1],g[i-1]+a[i-1]); 
	}
	ll ans = max(f[n]+a[n],g[n]-a[n]);
	cout<<ans<<endl; 
	return 0;
}
