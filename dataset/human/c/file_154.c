#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)((n>>m)&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

ll n,s[500][500];
int main(){
	scanf("%lld",&n);
	ll sum=0,cnt=0;
	while((sum+cnt+1)<=n)sum+=++cnt;
	if(sum!=n){
		puts("No");
		return 0;
	}
	
	ll crr=0;
	rep(i,0,cnt)rep(j,0,i+1)s[i+1][j]=s[j][i]=++crr;	
	
	puts("Yes");
	printf("%lld\n",cnt+1);
	rep(i,0,cnt+1){
		printf("%lld ",cnt);
		rep(j,0,cnt)printf("%lld ",s[i][j]);
		puts("");
	}
}
