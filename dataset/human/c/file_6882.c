#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

ll n;
ll dp[65536];
ll flag[65536];
ll sc[65535];
ll a[16][16];

ll f(ll s){
	if(flag[s])return dp[s];
	flag[s]=1;
	ll temp=-INF;
	for (int i=(1LL<<n)-1;i>=0;i--){
		i&=s;
		temp=max(temp,sc[i]+f(s^i));
	}
	return dp[s]=temp;
}

int main(){
	scanf("%lld",&n);
	rep(i,0,n)rep(j,0,n)scanf("%lld",&a[i][j]);
	flag[0]=1;
	rep(x,0,1LL<<n){
		ll s=0;
		rep(i,0,n)if(bit(x,i))rep(j,i+1,n)if(bit(x,j))s+=a[i][j];
		sc[x]=s;
	}
	printf("%lld\n",f((1LL<<n)-1));
	return 0;
}
