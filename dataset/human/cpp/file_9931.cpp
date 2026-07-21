#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

const int maxN = 100010;
const int MAXM = 310;
const int MAXK = 17;
const int MOD = 1000000007;
const ll INF = 10000000000000000LL;
const ll inf = 5000000000000LL;
int n;
//ll f[maxN];
char s[maxN]; 
int tag[27];
//ll p[maxN][27];
//ll ans = 0;
//ll d[27];
//int vis[27];
//void dfs(int i,int k)
//{
//	if(i > k)
//	{
//		ll res = 1;
//		for(int i=1;i<=k;i++)
//		{
//			res = (res * tag[d[i]])%MOD;
//		}
//		ans += res;
//		return;
//	}
//	for(int j=1;j<=26;j++)
//	{
//		if(vis[j] != 1)
//		{
//			if(j < d[i-1]) continue;
//			vis[j] = 1;
//			d[i] = j;
//			dfs(i+1,k);
//			vis[j] = 0;
//		}
//	}	
//}
ll f[27];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		int x = s[i] - 'a' + 1;
		tag[x]++;
	}
	int len = 26;
	f[0] = 1;
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<i;j++)
		{
			f[i] += (tag[i] * f[j])%MOD;
		}
	}
	ll ans = 0;
	for(int i=1;i<=len;i++)
	{
		ans = (ans + f[i])%MOD;
	}
	cout<<ans<<endl;
    return 0;
}
