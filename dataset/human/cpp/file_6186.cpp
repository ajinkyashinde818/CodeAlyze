#include<cstdio>
#include<cmath>
using namespace std;

const int N = 1<<18;
const int LGN = 19;

long long max_ll(long long a,long long b) {return a<b ? b : a;}

long long a[N+5];
long long d[N+5];
long long s1[N+5];
long long c1[N+5];
long long s2[N+5];
long long c2[N+5];
long long mx1[N+2];
long long mx2[N+2];
int n;
long long m;

int main()
{
	scanf("%d%lld",&n,&m); n+=2; a[1] = 0ll; d[1] = 0ll; a[n] = 0ll; d[n] = m;
	for(int i=2; i<n; i++) scanf("%lld%lld",&d[i],&a[i]);
	s1[0] = 0;
	for(int i=1; i<=n; i++) s1[i] = s1[i-1]+a[i];
	for(int i=1; i<=n; i++) s1[i] -= d[i];
	for(int i=1; i<=n; i++) mx1[i] = max_ll(mx1[i-1],s1[i]);
	for(int i=1; i<=n; i++) c1[i] = s1[i]-d[i];
	s1[n+1] = 0;
	for(int i=n; i>=1; i--) s2[i] = s2[i+1]+a[i];
	for(int i=n; i>=1; i--) s2[i] -= (m-d[i]);
	for(int i=n; i>=1; i--) mx2[i] = max_ll(mx2[i+1],s2[i]);
	for(int i=n; i>=1; i--) c2[i] = s2[i]-(m-d[i]);
	long long ans1 = 0ll,ans2 = 0ll;
	for(int i=n; i>1; i--)
	{
		long long tmp = mx1[i-1];
		ans1 = max_ll(ans1,c2[i]+tmp);
	}
	for(int i=1; i<n; i++)
	{
		long long tmp = mx2[i+1];
		ans2 = max_ll(ans2,c1[i]+tmp);
	}
	long long ans = max_ll(ans1,ans2);
	if(ans>0ll) printf("%lld\n",ans);
	else printf("0\n");
	return 0;
}
