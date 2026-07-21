#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

ll n,c,k;
ll a[300010];
ll ans;
int main(){
	scanf("%lld",&n);
	rep(i,0,3*n)scanf("%lld",a+i);
	sortdown(a,3*n);
	
	ll ans=0;
	repp(i,1,2*n,2)ans+=a[i];
	printf("%lld\n",ans);
}
