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

ll n,k;
ll a[1010];
ll cum[1010];
ll s[510010],cnt;

int main(){
	scanf("%lld%lld",&n,&k);
	rep(i,0,n){
		scanf("%lld",a+i);
		cum[i+1]=cum[i]+a[i];
		rep(j,0,i+1)s[cnt++]=cum[i+1]-cum[j];
	}

	ll ans=0;
	for(int i=45;i>=0&&cnt>=0;i--){
		sortdown(s,cnt);
		ll cc=0;
		rep(idx,0,cnt){
			if(bit(s[idx],i)){
				cc++;
				s[idx]^=(1LL<<i);
			}
			else break;
		}
		if(cc>=k){
			cnt=cc;
			ans|=(1LL<<i);
		}
	}
	printf("%lld",ans);
}
