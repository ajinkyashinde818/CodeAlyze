#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll n,d,ans;
	scanf("%lld%lld%lld",&n,&d,&ans);
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		ans+=(d+t-1)/t;
	}
	printf("%lld",ans);
}
