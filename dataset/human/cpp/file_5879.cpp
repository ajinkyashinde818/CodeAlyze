#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N=1e5+9;

int n;
ll c,x[N],v[N];
ll suml[N],sumr[N];
ll stk[N],top;

inline void chkmax(ll &a,ll b){if(a<b)a=b;}

int main()
{	
	if(fopen("vj.in","r"))
	{
		freopen("vj.in","r",stdin);
		freopen("vj.out","w",stdout);
	}

	scanf("%d%lld",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&v[i]);

	for(int i=1;i<=n;i++)
		suml[i]=suml[i-1]+v[i]-(x[i]-x[i-1]);
	x[n+1]=c;
	for(int i=n;i>=1;i--)
		sumr[i]=sumr[i+1]+v[i]-(x[i+1]-x[i]);

	ll ans=0;
	for(int i=1;i<=n;i++)
		chkmax(ans,suml[i]);
	for(int i=1;i<=n;i++)
		chkmax(ans,sumr[i]);

	for(int i=1;i<=n;i++)
		stk[i]=max(stk[i-1],suml[i]);

	for(int i=n;i>=1;i--)
		chkmax(ans,sumr[i]+stk[i-1]-(c-x[i]));

	for(int i=n;i>=1;i--)
		stk[i]=max(stk[i+1],sumr[i]);

	for(int i=1;i<=n;i++)
		chkmax(ans,suml[i]+stk[i+1]-x[i]);

	printf("%lld\n",ans);
	return 0;
}
